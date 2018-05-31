#include <iostream>
#include <memory>
#include <map>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#include "RecordSchema.h"

using namespace xercesc;
using namespace RecordSchema;

// These are the domain objects in the existing code that unflatten directly, converted to schema method
class SubDomainObject {
public:
    double value1;
    double value2;

    void unflatten(const std::shared_ptr<ClusterField> &schema, Record &record) {
        value1 = schema->getValue("Value 1")->asDouble(record);
        value2 = schema->getValue("Value 2")->asDouble(record);
    };
};

class DomainObject {
public:
    SubDomainObject subgroup1;
    SubDomainObject subgroup2;

    void unflatten(const std::shared_ptr<ClusterField> &schema, Record &record) {
        subgroup1.unflatten(schema->getCluster("SubGroup 1"), record);
        subgroup2.unflatten(schema->getCluster("SubGroup 2"), record);
    };
};

int main() {

    XMLPlatformUtils::Initialize();

    auto *parser = new XercesDOMParser();
    parser->setValidationScheme(XercesDOMParser::Val_Always);
    parser->setDoNamespaces(false);    // optional
    parser->setIncludeIgnorableWhitespace(false);

    parser->parse("test.xml");
    if (!parser->getDocument()) {
        std::cout << "Could not Parse test.xml document. Is it in the working directory?" << std::endl;
    }

    Schema *schema;
    try {
        schema = new Schema(parser->getDocument());
    } catch (std::runtime_error &error) {
        std::cout << error.what() << std::endl;
        return 0;
    }

    double values[] = {1.1, 2.2, 3.3, 4.4};
    auto record = reinterpret_cast<Record>(values);

    DomainObject domainObject;
    domainObject.unflatten(schema->getRootCluster("Main Group"), record);

    std::cout << "parsed values are"
        << " " << domainObject.subgroup1.value1 << " " << domainObject.subgroup1.value2
        << " " << domainObject.subgroup2.value1 << " " << domainObject.subgroup2.value2 << std::endl;


    XMLPlatformUtils::Terminate();

    return 0;
}