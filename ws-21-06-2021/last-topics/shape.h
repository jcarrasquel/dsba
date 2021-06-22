#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

enum Color{yellow, blue, red, green, orange, violet, white, black};


// "Abstract" class.
class Shape
{
	public:

		Shape()
			: _color(white)
		{}

		Shape(Color color)
			: _color(color)
		{}

		virtual double calcArea() = 0;
		virtual double calcPerimeter() = 0;

	protected:

		Color _color;
};

class Circle : public Shape
{
	public:

		Circle()
			: _radius(0.0)
		{}

		Circle(Color color, double radius)
			: Shape(color), _radius(radius)
		{}

		virtual double calcArea()
		{
			return 3.141592 * _radius * _radius;
		}

		virtual double calcPerimeter()
		{
			return 2 * 3.141592 * _radius;
		}

	private:

		double _radius;
};

#endif