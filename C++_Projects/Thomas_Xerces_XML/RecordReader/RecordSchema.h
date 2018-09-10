//
// Created by twoolie on 21/05/18.
//

#ifndef RECORDREADER_RECORDSCHEMA_H
#define RECORDREADER_RECORDSCHEMA_H

#include <map>
#include <memory>

#include <xercesc/dom/DOM.hpp>

namespace RecordSchema {

    enum class FIELD_TYPE : char {
        CLUSTER = 'c', VALUE = 'v'
    };
    enum class VALUE_TYPE : char {
        DOUBLE, SINGLE, INT,
    };

    typedef char *Record;

    class Schema; // class prototype satisfies lexical order for ClusterField Friendship;

    class Field {
    protected:
        FIELD_TYPE type;

        Field(FIELD_TYPE type) : type(type) {};
    public:
        inline FIELD_TYPE getType() { return type; };
    };

    class ValueField : public Field {
    protected:
        const uint16_t offset;
        const VALUE_TYPE value_type;

    public:
        ValueField(const std::string &type_name, uint16_t &out_offset);
        double asDouble(Record record);
    };

    class ClusterField : public Field {
        friend Schema;
    protected:
        std::map<std::string, std::shared_ptr<Field>> children;

    public:
        ClusterField() : Field(FIELD_TYPE::CLUSTER) {};

        std::shared_ptr<ValueField> getValue(const std::string &name);
        std::shared_ptr<ClusterField> getCluster(const std::string &name);
    };

    class Schema {
        uint16_t record_length;
        std::pair<std::string, std::shared_ptr<Field>> root_record;

    public:

        std::pair<std::string, std::shared_ptr<Field>> parse_child_node(xercesc::DOMNode *element);

        Schema(xercesc::DOMDocument *document) : record_length(0), root_record(parse_child_node(document->getFirstChild())) {};

        std::shared_ptr<ClusterField> getRootCluster(const std::string &expected_name);

    };
}

#endif //RECORDREADER_RECORDSCHEMA_H
