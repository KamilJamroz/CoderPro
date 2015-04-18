#include <iostream>
using namespace std;

class Polygon
{
	protected:
		int width, height;
	public:
		void setup (int _width, int _height)
		{
			width = _width;
			height = _height;
		}

		virtual int area() = 0;
};

class Rectangle : public Polygon
{
	public:
		int area()
		{
		    cout << "Rectangle area" << endl;
			return (width * height);
		}
};

class Triangle : public Polygon
{
	public:
		int area()
		{
		    cout << "Triangle area" << endl;
			return (width * height / 2);
		}
};

int main ()
{
	Rectangle rectangle;
	Triangle triangle;

	Polygon * polygon1 = &rectangle;
	Polygon * polygon2 = &triangle;

	polygon1->setup(2,2);
	polygon2->setup(2,2);

	polygon1->area();
	polygon2->area();

	return 0;
}
