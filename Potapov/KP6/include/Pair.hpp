#ifndef PAIR_HPP_INCLUDED
#define PAIR_HPP_INCLUDED

template <typename T, typename K>
class Pair {
private:
    T first_value;
    K second_value;

public:
    Pair(const T& first_value, const K& second_value);
    T& first();
    K& second();
    Pair<T, K>& operator=(Pair<T, K>& another);
    const T& first() const;
    const K& second() const;
};

#include "../src/Pair.cpp"

#endif