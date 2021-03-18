// Implementation of vector3d.h
#include "vector3d.h"
#include <cmath>
#include <vector>

// === constructors ===

Vector3D::Vector3D()
{
	_x = 0;
	_y = 0;
	_z = 0;
}

Vector3D::Vector3D(const Vector3D& v)
{
	_x = v._x;
	_y = v._y;
	_z = v._z;
}

Vector3D::Vector3D(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;

}

// === setters ===

void Vector3D::setX(double x)
{
	_x = x;
}

void Vector3D::setY(double y)
{
	_y = y;
}

void Vector3D::setZ(double z)
{
	_z = z;
}

// === getters ===

double Vector3D::getX()
{
	return _x;
}

double Vector3D::getY()
{
	return _y;
}

double Vector3D::getZ()
{
	return _z;
}

double Vector3D::magnitude() const
{
	return sqrt(_x*_x + _y*_y + _z*_z);
}

// === operators overload ===

std::ostream& operator << (std::ostream& os, const Vector3D& v) 
{ 
    os << v._x << " " << v._y << " " << v._z;
    return os; 
} 

std::istream& operator >> (std::istream& in, Vector3D& v) 
{ 
    in >> v._x >> v._y >> v._z;
    return in; 
}

Vector3D Vector3D::operator+(const Vector3D& v2)
{
	Vector3D v;
	v._x = _x + v2._x;
	v._y = _y + v2._y;
	v._z = _z + v2._z;

	return v;
}

//2
double Vector3D::operator* (const Vector3D& v2)
{
	return (_x * v2._x) + (_y * v2._y) + (_z * v2._z);
}

//5
bool Vector3D::operator== (const Vector3D& v2)
{
	return (_x == v2._x) && (_y == v2._y) && (_z == v2._z);
}

//7
bool Vector3D::operator< (const Vector3D& v2)
{
	return magnitude() < v2.magnitude();
}

// 9
double& Vector3D::operator[](int index)
{
	if(index == 0)
		return _x;

	if(index == 1)
		return _y;

	if(index == 2)
		return _z;
}

void Vector3D::operator=(const std::vector<double>& v)
{
	_x = v[0];
	_y = v[1];
	_z = v[2];
}

Vector3D Vector3D::operator++()	// pre-fix ++v
{
	Vector3D tmp(_x + 1.0, _y + 1.0, _z + 1.0);

	// increment (++)
	_x = tmp._x;
	_y = tmp._y;
	_z = tmp._z;

	return tmp; // and then return
} 

Vector3D Vector3D::operator++(int) // post-fix v++
{
	Vector3D tmp(_x, _y, _z); // return

	// and then increment (++)
	_x += 1.0;	
	_y += 1.0;
	_z += 1.0;

	return tmp;
}


Vector3D Vector3D::operator+= (const Vector3D& v2)
{
	_x += v2._x;
	_y += v2._y;
	_z += v2._z;

	return *(this);
}