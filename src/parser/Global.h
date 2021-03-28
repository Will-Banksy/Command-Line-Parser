#ifndef GLOBALS_H
#define GLOBALS_H

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

template<typename T>
using Vector = std::vector<T>;

template<typename T>
using Function = std::function<T>;

typedef std::string String;

template<typename A, typename B>
struct Pair {
	A first;
	B second;

	Pair() = default;
	Pair(A first, B second) : first(first), second(second) {}
};

#endif // GLOBALS_H