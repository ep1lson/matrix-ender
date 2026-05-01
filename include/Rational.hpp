/*
 * A general-purpose interface for rational numbers
 */

#pragma once
#include <sstream>

// Debug
#ifdef DEBUG_ME
#include <iostream>
using namespace std;
#endif

class Rational {
    long num, denom;

public:

    // Manual rational instantiation
    Rational(long numerator, long denominator) {
        long a = denominator, b = numerator;
        while (a % b != 0) {
            long tmp = a;
            a = b;
            b = tmp % b;
        }
        this->num   = numerator / b;
        this->denom = denominator / b;
    }

    // String instantiation
    Rational(std::string descriptor, char delimiter = '/') {
        size_t si    = descriptor.find(delimiter);
        std::string num   = descriptor.substr(0, si),
               denom = descriptor.substr(si + 1, descriptor.size());
        this->num   = std::stoi(num);
        this->denom = std::stoi(denom);
    }

    // int compatibility
    Rational(int num) : num(num), denom(1) {}

    // Move semantics and destructors: use default
    Rational(Rational&& rational) = default;
    ~Rational() = default;

    // Operators
    Rational operator+(const Rational& other) {
        return Rational(
            this->num * other.denom + other.num * this->denom,
            other.denom * this->denom
        );
    }

    Rational operator-(const Rational& other) {
        return Rational(
            this->num * other.denom - other.num * this->denom,
            other.denom * this->denom
        );
    }

    Rational operator*(const Rational& other) {
        return Rational(
            this->num * other.num,
            this->denom * other.denom
        );
    }

    Rational operator/(const Rational& other) {
        return Rational(
            this->num * other.denom,
            this->denom * other.num
        );
    }

    // Multiplicative inverse (a/b -> b/a)
    Rational inv() {
        return Rational(
            this->denom,
            this->num
        );
    }

    // Additive inverse (a/b -> -a/b)
    Rational neg() {
        return Rational(
            -this->num,
            this->denom
        );
    }

    // Generic to string method
    std::string toString(char delimiter = '/') {
        std::stringstream ss;
        ss << this->num << delimiter << this->denom;
        return ss.str();
    }
};