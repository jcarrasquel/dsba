#include "vector3d.h"
#include <vector>
#include <iostream>

int main()
{
	Vector3D v1(1.0,2.0,3.0);

	Vector3D v2(5.0,5.0,5.0);

	v1 += v2;

	std :: cout << ++v1 << std :: endl;

	return 0;
}