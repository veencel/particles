/**
 * @file vector.h
 * @brief A Vector osztály deklarációja.
 *
 * Ez a fájl tartalmazza a Vector osztály deklarációját.
 *
 * @author Kátai Vencel
 */
#ifndef CHARGED_PARTICLES_VECTOR_H
#define CHARGED_PARTICLES_VECTOR_H

#include <iostream>
#include "SFML/System/Vector2.hpp"
/**
 * @class Vector
 * @defgroup vector Vector
 *
 * @brief Egy síkbeli vektort ábrázoló osztály
 *
 * Ez az osztály egy síkbeli vektort ábrázol
 * annak x és y tengely szerinti koordinátájával
 * és az azokon végzett mûveleteket valósítja meg.
 *
 * @see vector.cpp
 */
class Vector {
public:
    double x,y; /**< A vektor koordinátája */

    /**
    * @brief A Vector osztály konstruktora
    * @param x A vektor egyik komponense
    * @param y A vektor másik komponense
    *
    * Ez a függvény inicializálja a vektor a
    * paraméterben megadott értékekkel, ha nincs
    * megadva paraméter 0-val.
    */
    Vector(double x=0, double y=0) : x{x}, y{y} {}


    Vector operator+(const Vector&) const;

    Vector operator-(const Vector&) const;

    Vector operator*(const double&) const;

    Vector operator/(const double&) const;

    Vector& operator+=(const Vector&);

    Vector& operator-=(const Vector&);

    Vector& operator*=(const double&);

    Vector& operator/=(const double&);

    bool operator==(const Vector& rhs) { return x == rhs.x && y == rhs.y; }

    bool operator!=(const Vector& rhs) { return !(*this == rhs); }

    double length() const;

    Vector normalize();

    sf::Vector2f toVector2f() { return sf::Vector2f(x,y); }
};

std::ostream& operator<<(std::ostream& os,const Vector& v);

#endif //CHARGED_PARTICLES_VECTOR_H
