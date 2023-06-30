#include "../include/Database.hpp"

Database::Database(const std::string& filename) {
    path = create_file(filename);
}

std::string Database::make_dir(const std::string& dir_name) {
    std::string dir_path = std::string("/Users/Santa/MAI_109B_22/Potapov/KP6" + dir_name);

    if (!std::filesystem::is_directory(dir_path.c_str())) {
        std::filesystem::create_directories(dir_path.c_str());
    }

    return dir_path;
}

std::string Database::create_file(const std::string& filename) {
    std::fstream file;
    std::string curr_path = make_dir("Databases") + "/" + filename + ".txt";
    file.open(curr_path, std::ios::app);
    if (!file) {
        throw std::runtime_error("Problems with file creation");
    }
    file.close();
    return curr_path;
}

void Database::delete_file() {
    std::fstream file;
    if (file) file.close();
    remove(path.data());
}

void Database::add_data(const Row& student) {
    std::fstream file;
    if (!file) {
        throw std::runtime_error("File doesn't exist");
    }
    file.open(path.data(), std::ios::out | std::ios::app);
    file << student;
    file.close();
}

size_t find(const Vector<Pair<Pair<std::string, size_t>, Vector<size_t>>>& vec, const Pair<std::string, size_t>& key) {
    for (size_t i = 0; i < vec.get_size(); ++i) {
        if (vec[i].first().first() == key.first() 
                && vec[i].first().second() == key.second()
        ) {
            return i;
        }
    }

    return vec.get_size();
}

size_t calculate_average_rate(const Vector<size_t>& vec) {
    size_t average_rate = 0;

    for (size_t i = 0; i < vec.get_size(); ++i) {
        average_rate += vec[i];
    }

    average_rate /= vec.get_size();

    return average_rate;
}

void Database::task() const {
    std::fstream file;
    size_t group_number = 0;
    std::string group_name;
    size_t max_average_rate = 0;

    file.open(path.data(), std::ios::in);

    Vector<Pair<Pair<std::string, size_t>, Vector<size_t>>> vec;
    Row student;

    while (file.peek() != EOF) {
        file >> student;
    
        if (student.sex == "female") {
            size_t average_rate = (student.english + student.math + student.english) / 3;
            size_t index = find(vec, Pair(student.group_name, student.group_number));\
            
            if (index != vec.get_size()) {
                vec[index].second().push_back(average_rate);
            } else {
                Pair<std::string, size_t> p(student.group_name, student.group_number);
                Vector<size_t> v = {average_rate};
                Pair<Pair<std::string, size_t>, Vector<size_t>> p1(p, v);
                vec.push_back(p1);
            }
        }
    }

    for (size_t i = 0; i < vec.get_size(); ++i) {
        size_t average_rate = calculate_average_rate(vec[i].second());
        if (average_rate > max_average_rate) {
            max_average_rate = average_rate;
            group_name = vec[i].first().first();
            group_number = vec[i].first().second();
        }
    }

    std::cout << group_name << '-' << group_number << std::endl;
}