// Implementation of methods for structures in "cities.h"
#include "cities.h"
#include <iostream>

std::ostream& operator <<(std::ostream& os, const Coordinate& c)
{
    os << c.latitude << "," << c.longitude;

    return os;
}

std::ostream& operator <<(std::ostream& os, const City& city)
{
    os << "city=" << city.name << " population= " << city.population << " coordinate = " << city.coordinate;

    return os;
}

std::ostream& operator <<(std::ostream& os, const Country& country)
{
    os << "country=" << country.name << " cities= " << country.cities.size();

    return os;
}

