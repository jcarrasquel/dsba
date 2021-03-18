#include <iostream>
#include <vector>

#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
	public:
		// ----< Methods >----
		
		// === constructors ===
		Vector3D();								// empty constructor
		Vector3D(const Vector3D& v);			// copy constructor
		Vector3D(double x, double y, double z);	// constructor with arguments

		// === setters ===
		void setX(double x);
		void setY(double y);
		void setZ(double z);

		// === getters ===
		double getX();
		double getY();
		double getZ();

		double magnitude() const; // calculate the vector magnitude - length from point (0,0,0).

		Vector3D operator+ (const Vector3D& v2);

		// === overloads of homework ===
		
		double operator*(const Vector3D& v2); 
		
		bool operator==(const Vector3D& v2);

		bool operator<(const Vector3D& v2); 

		double& operator[](int index);

		// === ...and more overloads! ===

		void operator=(const std::vector<double>& v); // assign a vector v of 3 doubles to a vector3D

		Vector3D operator++(); 		// prefix increment ++()
		Vector3D operator++(int);	// postfix increment ()++

		Vector3D operator+= (const Vector3D& v2);

		// not functions from this class, but "friends"! Can access to private fields.
		friend std::ostream& operator << (std::ostream &out, const Vector3D& v);
		friend std::istream& operator >> (std::istream &in, Vector3D& v);

	private:
		// ----< Fields >----
		double _x;
		double _y;
		double _z;
};

#endif