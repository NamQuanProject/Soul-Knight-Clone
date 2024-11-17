#pragma once
#include <cmath>

class Vec {
public:
    // Member variables
    double x;
    double y;

    // Constructors
    Vec() : x(0), y(0) {}                // Default constructor (0, 0)
    Vec(double x, double y) : x(x), y(y) {} // Parameterized constructor

    // Vector operations
    Vec operator+(const Vec& other) const;  // Add two vectors
    Vec operator-(const Vec& other) const;  // Subtract two vectors
    Vec operator*(double scalar) const;     // Scale vector
    Vec operator/(double scalar) const;     // Divide vector

    Vec& operator+=(const Vec& other);      // Add and assign
    Vec& operator-=(const Vec& other);      // Subtract and assign
    Vec& operator*=(double scalar);         // Scale and assign
    Vec& operator/=(double scalar);         // Divide and assign

    double Magnitude() const;               // Length of the vector
    Vec Normalize() const;                  // Unit vector

    // Utility functions
    double Dot(const Vec& other) const;     // Dot product
    double Distance(const Vec& other) const; // Distance between two points
};
