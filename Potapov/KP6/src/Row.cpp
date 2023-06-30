#include "../include/Row.hpp"
#include <sstream>

Row::Row(
            const std::string& surname,
            const std::string& initials,
            const size_t group_number,
            const std::string& group_name,
            const std::string& sex,
            const size_t math,
            const size_t english,
            const size_t computer_science
        ) {
            this->surname = surname;
            this->initials = initials;
            this->group_number = group_number;
            this->group_name = group_name;
            this->sex = sex;
            this->math = math;
            this->english = english;
            this->computer_science = computer_science;
        }

std::ostream& operator<<(std::ostream& out, const Row& student) {
    out  << student.surname << ',' << student.initials <<
    ',' << student.group_number << ',' << student.group_name << ',' << student.sex << ','
    << student.math << ',' << student.english << ',' << student.computer_science << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Row& student) {
    char delimiter = ',';
    std::string line;
    getline(in, line);
    std::stringstream stream(line);

    std::string temp;
    getline(stream, student.surname, delimiter);
    getline(stream, student.initials, delimiter);
    getline(stream, temp, delimiter);
    student.group_number = std::stoull(temp);
    getline(stream, student.group_name, delimiter);
    getline(stream, student.sex, delimiter);
    getline(stream, temp, delimiter);
    student.math = std::stoull(temp);
    getline(stream, temp, delimiter);
    student.english = std::stoull(temp);
    getline(stream, temp, delimiter);
    student.computer_science = std::stoull(temp);
    
    return in;
}