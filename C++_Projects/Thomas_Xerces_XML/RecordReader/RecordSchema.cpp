//
// Created by twoolie on 21/05/18.
//

#include "RecordSchema.h"

namespace RecordSchema {

    using namespace xercesc;

    static const std::map<std::string, VALUE_TYPE> value_type_name_to_enum = {
        {"DBL", VALUE_TYPE::DOUBLE},
        {"FLT", VALUE_TYPE::SINGLE},
        {"INT", VALUE_TYPE::INT},
    };

    ValueField::ValueField(const std::string &type_name, uint16_t &out_offset)
            : Field(FIELD_TYPE::VALUE), offset(out_offset)
            , value_type(value_type_name_to_enum.at(type_name)) {
        switch (value_type) {
            case VALUE_TYPE::DOUBLE: out_offset += sizeof(double); break;
            case VALUE_TYPE::SINGLE: out_offset += sizeof(float);  break;
            case VALUE_TYPE::INT:    out_offset += sizeof(int);    break;
        }
    };

    double ValueField::asDouble(Record record) {
        if (value_type != VALUE_TYPE::DOUBLE)
            throw std::runtime_error("Tried to read a DOUBLE record with wrong underlying type");
        return *reinterpret_cast<double *>(record + offset);
    };


    std::shared_ptr<ValueField> ClusterField::getValue(const std::string &name) {
        auto child = children.at(name);
        if (child->getType() != FIELD_TYPE::VALUE)
            throw std::runtime_error("Tried to retrieve a Value, got a Cluster");
        return std::static_pointer_cast<ValueField, Field>(child);
    }

    std::shared_ptr<ClusterField> ClusterField::getCluster(const std::string &name) {
        auto child = children.at(name);
        if (child->getType() != FIELD_TYPE::CLUSTER)
            throw std::runtime_error("Tried to retrieve a Cluster, got a Value");
        return std::static_pointer_cast<ClusterField, Field>(child);
    }


    std::pair<std::string, std::shared_ptr<Field>> Schema::parse_child_node(DOMNode *element) {
        std::string node_type = XMLString::transcode(element->getNodeName());
        // numElts is the first child
        auto *child = element->getFirstChild();
        if (child->getNodeType() == DOMNode::TEXT_NODE) child = child->getNextSibling();
        std::string node_name = XMLString::transcode(child->getTextContent());

        if (node_type == "Cluster") {
            child = child->getNextSibling(); // throw away NumElts
            if (child->getNodeType() == DOMNode::TEXT_NODE) child = child->getNextSibling();
            auto result = std::make_shared<ClusterField>();
            while (child = child->getNextSibling()) {
                if (child->getNodeType() == DOMNode::TEXT_NODE) continue;
                result->children.insert(parse_child_node(child));
            }
            return std::pair<std::string, std::shared_ptr<Field>>(node_name, result);
        } else {
            auto result = std::make_shared<ValueField>(node_type, this->record_length);
            return std::pair<std::string, std::shared_ptr<Field>>(node_name, result);
        }
    }


    std::shared_ptr<ClusterField> Schema::getRootCluster(const std::string &expected_name) {
        if (expected_name != root_record.first)
            throw std::runtime_error("Root Record is not of the expected name");
        if (root_record.second->getType() != FIELD_TYPE::CLUSTER)
            throw std::runtime_error("Record is not of expected type CLUSTER");
        return std::static_pointer_cast<ClusterField,Field>(root_record.second);
    }
}