#include "NotFoundException.h"

NotFoundException::NotFoundException(std::string collectionName, std::optional<std::string> objectId, std::optional<std::string> methodName)
        : collectionName(std::move(collectionName)), objectId(std::move(objectId))
{
    std::ostringstream oss;
    if (objectId.has_value() && methodName.has_value()) {
        oss << *methodName << " - " << this->collectionName << " - " << *objectId;
    } else if (methodName.has_value()) {
        oss << *methodName << " - " << this->collectionName << " - none";
    } else if (objectId.has_value()) {
        oss << "none - " << this->collectionName << " - " << *objectId;
    } else {
        oss << "none - " << this->collectionName << " - none";
    }
    message = oss.str();
}
NotFoundException::~NotFoundException() {}

const char* NotFoundException::what() const noexcept
{
    return message.c_str();
}

const std::string& NotFoundException::get_collection_name() const
{
    return collectionName;
}

const std::optional<std::string>& NotFoundException::get_object_id() const
{
    return objectId;
}
