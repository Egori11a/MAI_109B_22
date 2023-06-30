#include "../include/Pair.hpp"

template <typename T, typename K>
Pair<T, K>::Pair(const T& first_value, const K& second_value): first_value(first_value), second_value(second_value) {}

template <typename T, typename K>
T& Pair<T, K>::first() {
    return first_value;
}

template <typename T, typename K>
K& Pair<T, K>::second() {
    return second_value;
}

template <typename T, typename K>
const T& Pair<T, K>::first() const {
    return first_value;
}

template <typename T, typename K>
const K& Pair<T, K>::second() const {
    return second_value;
}