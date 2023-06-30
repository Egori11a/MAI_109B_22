#include "../include/Database.hpp"

int main() {
    Database db("students");
    Row r1 (
        "bebra",
        "B B",
        5,
        "A",
        "female",
        5,
        3,
        2
    );

    Row r2 (
        "biba",
        "C C",
        5,
        "B",
        "male",
        5,
        3,
        2
    );

    db.add_data(r1);
    db.add_data(r2);
    db.task();
}    