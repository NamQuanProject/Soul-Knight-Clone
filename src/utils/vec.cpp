#include "Vec.h"

// Addition
Vec Vec::operator+(const Vec& other) const {
    return Vec(x + other.x, y + other.y);
}

// Subtraction
Vec Vec::operator-(const Vec& other) const {
    return Vec(x - other.x, y - other.y);
}

// Scalar multiplication
Vec Vec::operator*(double scalar) const {
    return Vec(x * scalar, y * scalar);
}

// Scalar division
Vec Vec::operator/(double scalar) const {
    return Vec(x / scalar, y / scalar);
}

// Compound addition
Vec& Vec::operator+=(const Vec& other) {
    x += other.x;
    y += other.y;
    return *this;
}

// Compound subtraction
Vec& Vec::operator-=(const Vec& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

// Compound multiplication
Vec& Vec::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

// Compound division
Vec& Vec::operator/=(double scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

// Magnitude of the vector
double Vec::Magnitude() const {
    return std::sqrt(x * x + y * y);
}

// Normalize the vector (unit vector)
Vec Vec::Normalize() const {
    double mag = Magnitude();
    return mag > 0 ? Vec(x / mag, y / mag) : Vec(0, 0);
}

// Dot product
double Vec::Dot(const Vec& other) const {
    return x * other.x + y * other.y;
}

// Distance between two vectors
double Vec::Distance(const Vec& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}
