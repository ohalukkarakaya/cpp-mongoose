#include "MongoValidationException.h"

MongoValidationException::MongoValidationException(std::string collectionName)
        : collectionName(std::move(collectionName))
{
    std::ostringstream oss;
    oss << ErrorMessages::MONGO_VALIDATION_EXCEPTION << ": " << this->collectionName;
    message = oss.str();
}
MongoValidationException::~MongoValidationException() {}

const char* MongoValidationException::what() const noexcept {
return message.c_str();
}

const std::string& MongoValidationException::get_collection_name() const {
    return collectionName;
}
