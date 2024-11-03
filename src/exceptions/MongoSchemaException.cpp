#include "../../include/exceptions/MongoSchemaException.h"

MongoSchemaException::MongoSchemaException(std::string methodName, std::string collectionName, std::string object_id)
        : methodName(std::move(methodName)), collectionName(std::move(collectionName)), object_id(std::move(object_id))
{
    // Create a formatted message using ostringstream
    std::ostringstream oss;
    oss << ErrorMessages::MONGO_EXCEPTION_DESC << ": " << methodName << ", " << object_id;
    std::string formattedMessage = oss.str();

    // Clear the ostringstream and use it again for the final message
    oss.str("");
    oss.clear();
    oss << ErrorMessages::MONGO_EXCEPTION << ": " << collectionName << ", " << formattedMessage;
    message = oss.str();
}
MongoSchemaException::~MongoSchemaException() {}

const char* MongoSchemaException::what() const noexcept {
return message.c_str();
}

const std::string& MongoSchemaException::get_collection_name() const {
    return collectionName;
}

const std::string& MongoSchemaException::get_object_id() const {
    return object_id;
}