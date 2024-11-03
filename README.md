<div align="center">
    <img src="https://github.com/ohalukkarakaya/cpp-mongoose/blob/3758f7b57d4cb9f541f34f083e3b79e637ef23c5/assets/mongo_db.png" alt="thumbnail" style="width: 100%; height: auto;"></img>

<h1>C++ Mongoose Like Library</h1>
<p>Library for managing mongo db</p>
</div>

## 🗺️ <code>map</code> 
- [<code>🌟 Features</code>](#-features)
- [<code>📦 Installation</code>](#-installation)
  - [<code>🔧 Prerequisites</code>](#-prerequisites)
  - [<code>📥 Installing MongoDB C++ Driver</code>](#-installing-mongodb-c-driver)
  - [<code>🗂️ Project Structure</code>](#-project-structure)
- [<code>🚀 Usage</code>](#-usage)
  - [<code>🏗️ Adding to Your Project Using CMake</code>](#️-adding-to-your-project-using-cmake)
  - [<code>📝 Using the **MongoSchema** Class</code>](#-using-the-mongoschema-class)
- [<code>💡 Example Usage</code>](#-example-usage)
  - [<code>➕ Inserting a Single Document</code>](#-inserting-a-single-document)
  - [<code>🔍 Finding a Document by ID</code>](#-finding-a-document-by-id)
- [<code>⚠️ Error Handling</code>](#-error-handling)
- [<code>📜 License</code>](#-license)
- [<code>🤝 Contributions</code>](#-contributions)
- [<code>🙏 Acknowledgements</code>](#-acknowledgements)

<hr style="border: 0.1px solid #ccc;" />

## 🌟 Features

- **CRUD Operations**: Basic database operations such as `insert_one`, `insert_many`, `find_by_id`, `find_one`, `find`, `update_one`, `update_many`, `delete_one`, and `delete_many`.
- **Data Validation**: Built-in `isValid()` method for data validation.
- **TTL and `createdAt` Indexing**: Automatic creation of TTL (Time-To-Live) and `createdAt` indices.
- **Exception Handling**: Comprehensive error reporting through `MongoSchemaException`, `MongoValidationException`, and `NotFoundException` classes.

## 📦 Installation

### 🔧 Prerequisites
- **CMake** (version 3.10 or higher)
- **MongoDB C++ Driver** (`mongocxx` and `bsoncxx`)
- **Boost Library**

### 📥 Installing MongoDB C++ Driver
You can install the MongoDB C++ driver using `Homebrew`:

```bash
brew install mongo-cxx-driver
```

### 🗂️ Project Structure
```
├── include
│   ├── MongoSchema.h
│   ├── exceptions
│   │   ├── MongoSchemaException.h
│   │   ├── MongoValidationException.h
│   │   └── NotFoundException.h
├── src
│   ├── MongoSchema.cpp
│   ├── exceptions
│   │   ├── MongoSchemaException.cpp
│   │   ├── MongoValidationException.cpp
│   │   └── NotFoundException.cpp
├── CMakeLists.txt
└── README.md
```

## 🚀 Usage

### 🏗️ Adding to Your Project Using CMake
To build your project and include `CppMongoose as a library, add the following to your `CMakeLists.txt`:
```
add_subdirectory(path/to/CppMongoose)
target_link_libraries(YourProjectName PRIVATE CppMongoose)
```

### 📝 Using the **MongoSchema** Class
Extend the `MongoSchema class to create your own MongoDB models:

```cpp
#include "MongoSchema.h"

class YourModel : public MongoSchema {
public:
    YourModel() : MongoSchema("YourCollectionName") {}

    void initializeSchema(bsoncxx::document::view document) override {
        // Map the document to your model
    }

    bool validation() const override {
        // Perform model validation
        return true;
    }
};
```

## 💡 Example Usage

### ➕ Inserting a Single Document
```cpp
mongocxx::client client{mongocxx::uri{}};
YourModel model;
model.insert_one(R"({"name": "John Doe", "age": 30})", client, "YourDatabaseName");
```

### 🔍 Finding a Document by ID
```cpp
bsoncxx::oid id("your_object_id_here");
YourModel model;
model.find_by_id(id, client, "YourDatabaseName");
```

## ⚠️ Error Handling

This library uses custom exception classes (`MongoSchemaException`, `MongoValidationException`, and `NotFoundException`) to handle errors effectively, providing detailed information about what went wrong.

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🤝 Contributions

Contributions are welcome! Feel free to open an issue or submit a pull request.

## 🙏 Acknowledgements
- [MongoDB C++ Driver documentation](https://mongodb.github.io/mongo-cxx-driver/)
- [Boost Library documentation](https://www.boost.org/doc/)
