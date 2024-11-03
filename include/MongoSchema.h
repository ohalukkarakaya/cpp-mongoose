#ifndef MONGODBSCHEMA_H
#define MONGODBSCHEMA_H

#include <mongocxx/client.hpp>
#include <optional>
#include <bsoncxx/json.hpp>
#include <utility>

#include "exceptions/MongoSchemaException.h"
#include "exceptions/MongoValidationException.h"
#include "exceptions/NotFoundException.h"

class MongoSchema {
private:
    // validasyon koşullarını burada belirle
    bool isValid() const;

    // createdAt indeksini oluşturmak için gerekli veriyi döner
    std::optional<bsoncxx::document::view> create_created_at_index() const;

    // TTL indeksini oluşturmak için süreyi formatlar
    std::optional<bsoncxx::document::view> create_ttl_index() const;

protected:
    std::string collectionName;
    std::optional<int> expires;
    std::optional<int> created_at_option; // 1 = on | 0 = off

    // JSON formatındaki filtreyi BSON dökümanına dönüştürür
    static bsoncxx::document::view create_filter(const std::string& jsonFilter) ;

    // Koleksiyon adı döndüren yardımcı metod
    [[nodiscard]] mongocxx::collection get_collection(const mongocxx::client& client, const std::string& db_name) const;

    // Türemiş Classlar için muhakkak oluşturulmalı
    virtual void initializeSchema(bsoncxx::document::view document) = 0;

    // validasyon koşullarını burada belirle
    [[nodiscard]] virtual bool validation() const;
public:
    bsoncxx::oid _id;

    explicit MongoSchema(std::string collectionName, bsoncxx::oid id = bsoncxx::oid());

    // Tek bir belge ekleme
    void insert_one(const std::string& jsonDocument, const mongocxx::client& client, const std::string& db_name);

    // Birden fazla belge ekleme
    std::vector<bsoncxx::document::view> insert_many(const std::vector<std::string>& jsonDocuments, const mongocxx::client& client, const std::string& db_name);

    // ID'ye göre belge bulma
    void find_by_id(const bsoncxx::oid& id, const mongocxx::client& client, const std::string& db_name);

    // Tek bir belge bulma
    void find_one(const bsoncxx::v_noabi::document::view jsonFilter, const mongocxx::client& client, const std::string& db_name);

    // Belge bulma (birden fazla sonuç)
    std::vector<bsoncxx::document::view> find(const std::string& jsonFilter, const mongocxx::client& client, const std::string& db_name);

    // Tek bir belgeyi güncelleme
    void update_one(const std::string& jsonFilter, const std::string& jsonUpdate, const mongocxx::client& client, const std::string& db_name);

    // Birden fazla belgeyi güncelleme
    void update_many(const std::string& jsonFilter, const std::string& jsonUpdate, const mongocxx::client& client, const std::string& db_name);

    // Tek bir belgeyi silme
    void delete_one(const std::string& jsonFilter, const mongocxx::client& client, const std::string& db_name);

    // Birden fazla belgeyi silme
    void delete_many(const std::string& jsonFilter, const mongocxx::client& client, const std::string& db_name);
};

#endif //MONGODBSCHEMA_H
