#ifndef DATABASE_HPP_INCLUDED
#define DATABASE_HPP_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "Row.hpp"
#include "Pair.hpp"
#include "Vector.hpp"

class Row;

class Database {
private:
    std::string path;

public:
    Database() = default;
    Database(const std::string& file_name);
    ~Database() = default;

    std::string create_file(const std::string& file_name = "db_1");
    void delete_file();
    void add_data(const Row& student);
    std::string make_dir(const std::string& dir_name);
    void task() const;
};

#include "../src/Database.cpp"

#endif