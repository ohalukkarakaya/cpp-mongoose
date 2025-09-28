<div align="center">
    <img src="https://github.com/ohalukkarakaya/cpp-mongoose/blob/3758f7b57d4cb9f541f34f083e3b79e637ef23c5/assets/mongo_db.png" alt="thumbnail" style="width: 100%; height: auto;"></img>

<h1>C++ Mongoose-Like Library</h1>
<p>A lightweight C++ library for managing MongoDB with an object-oriented approach.</p>
</div>

---

## 📖 Overview

This project is an experimental **MongoDB helper library in C++**, inspired by Mongoose in Node.js.  
It simplifies CRUD operations, schema validation, and exception handling for C++ applications.

---

## 🗺️ Table of Contents
- [👤 Intended Audience](#-intended-audience)
- [🌟 Features](#-features)
- [📦 Installation](#-installation)
  - [🔧 Prerequisites](#-prerequisites)
  - [📥 Installing MongoDB C++ Driver](#-installing-mongodb-c-driver)
  - [🗂️ Project Structure](#-project-structure)
- [🚀 Usage](#-usage)
  - [🏗️ Adding to Your Project Using CMake](#️-adding-to-your-project-using-cmake)
  - [📝 Using the MongoSchema Class](#-using-the-mongoschema-class)
- [💡 Example Usage](#-example-usage)
  - [➕ Inserting a Single Document](#-inserting-a-single-document)
  - [🔍 Finding a Document by ID](#-finding-a-document-by-id)
- [⚠️ Error Handling](#-error-handling)
- [📊 Sample Output](#-sample-output)
- [📜 License](#-license)
- [🤝 Contributions](#-contributions)
- [🙏 Acknowledgements](#-acknowledgements)

---

## 👤 Intended Audience

This library is designed for **C++ developers** who want to simplify MongoDB usage in their projects.  
Expected audience: **intermediate to advanced C++ developers** who are already familiar with basic database concepts.

---

## 🌟 Features

- **CRUD Operations**: `insert_one`, `insert_many`, `find_by_id`, `find_one`, `find`, `update_one`, `update_many`, `delete_one`, and `delete_many`.
- **Data Validation**: Built-in `validation()` method for custom rules.
- **TTL & createdAt Indexing**: Auto-creation of TTL and timestamp indices.
- **Custom Exceptions**: `MongoSchemaException`, `MongoValidationException`, and `NotFoundException`.

---

## 📦 Installation

### 🔧 Prerequisites
- **C++17** or higher  
- **CMake** (3.10+)  
- **MongoDB C++ Driver** (`mongocxx` 3.10+ and `bsoncxx`)  
- **Boost Library**  

### 📥 Installing MongoDB C++ Driver
On macOS with Homebrew:
```bash
brew install mongo-cxx-driver
```

On Linux (Ubuntu/Debian):
```bash
sudo apt-get install libmongocxx-dev libbsoncxx-dev
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

---

## 🚀 Usage

> 📝 **Note**: This library assumes that you are comfortable with CMake and basic C++ class design.  
It is intended for developers with at least intermediate C++ knowledge.

### 🏗️ Adding to Your Project Using CMake
```cmake
add_subdirectory(path/to/cpp-mongoose)
target_link_libraries(YourProject PRIVATE CppMongoose)
```

### 📝 Using the **MongoSchema** Class
```cpp
#include "MongoSchema.h"

class UserModel : public MongoSchema {
public:
    UserModel() : MongoSchema("users") {}

    void initializeSchema(bsoncxx::document::view document) override {
        // Map BSON document to fields
    }

    bool validation() const override {
        // Add validation logic
        return true;
    }
};
```

---

## 💡 Example Usage

### ➕ Inserting a Single Document
```cpp
mongocxx::client client{mongocxx::uri{}};
UserModel user;
user.insert_one(R"({"name": "Alice", "age": 25})", client, "testdb");
```

### 🔍 Finding a Document by ID
```cpp
bsoncxx::oid id("your_object_id_here");
UserModel user;
auto result = user.find_by_id(id, client, "testdb");
```

---

## ⚠️ Error Handling

The library uses custom exceptions (`MongoSchemaException`, `MongoValidationException`, `NotFoundException`) for clear error reporting.

Example:
```cpp
try {
    user.insert_one("{}", client, "testdb");
} catch (const MongoValidationException& e) {
    std::cerr << "Validation failed: " << e.what() << std::endl;
}
```

---

## 📊 Sample Output

When inserting a valid document:
```
Inserted document into collection 'users' with _id: 60c72b2f9af1a4f5d4b7c9d1
```

When validation fails:
```
Validation failed: Missing required field 'name'
```

---

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🤝 Contributions

Contributions are welcome! Open an issue or submit a PR.

---

## 🙏 Acknowledgements
- [MongoDB C++ Driver](https://mongodb.github.io/mongo-cxx-driver/)
- [Boost Library](https://www.boost.org/doc/)
