#ifndef ROW_HPP_INCLUDED
#define ROW_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Database.hpp"

class Row {
    friend class Database;
    
private:
    std::string surname;
    std::string initials;
    size_t group_number;
    std::string group_name;
    std::string sex;
    size_t math;
    size_t english;
    size_t computer_science;

public:
    Row() = default;
    ~Row() = default;
    Row(
            const std::string& surname,
            const std::string& initials,
            const size_t group_number,
            const std::string& group_name,
            const std::string& sex,
            const size_t math,
            const size_t english,
            const size_t computer_science
        );

    friend std::ostream& operator<<(std::ostream& out, const Row& student);
    friend std::istream& operator>>(std::istream& in, Row& student);

    friend class Database;
};

#include "../src/Row.cpp"

#endif