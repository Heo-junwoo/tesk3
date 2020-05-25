#include<iostream>
#include "Rectangle.h"
#include <cmath>
using namespace std;


// 사용되는 함수만 구현한다

int main()
{
	int x1, y1, x2, y2;
	cout << "좌측 하단x 좌표 : ";
	cin >> x1;
	cout << "좌측 하단y 좌표 : ";
	cin >> y1;
	cout << "우측 상단x 좌표 : ";
	cin >> x2;
	cout << "우측 상단x 좌표 : ";
	cin >> y2;
	

	Point p1(x1, y1), p2(x2, y2);
	Rectangle r(p1, p2);

	cout << "\n직사각형의 면적 :" << r.area();
}
// main 함수에서는 <Point>, <Rectangle> 가 사용 되었다.


// <Point> 구현

	// 4개의 Point를 담는 배열을 생성
Point cordinate[4];
	// 4개의 Point를 설정해 주는 함수 생성
Point* setcordinate(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
{	
	// 좌측하단좌표가 index = 0을 기준으로 하고 시계방향으로 순서대로 돌아간다.
	cordinate[0] = p1;
	cordinate[1] = p2;
	cordinate[2] = p3;
	cordinate[3] = p4;
	return cordinate;
}


// <Rectangle> 구현

	// Rectangle 좌측하단좌표 p1, 우측상단좌표 p2를 받아 4개의 점을 모두 설정
Rectangle::Rectangle(const Point& p1, const Point& p2)
	: Polygon(setcordinate(p1, Point(p1.getX(), p2.getY()), p2, Point(p2.getX(), p1.getY())), 4) {}

	// area 구현
double Rectangle::area() const
{
	// 높이 : 1번 y - 0번 y
	int height = points.get(1)->getY() - points.get(0)->getY();
	// 너비 : 3번 x - 0번 x
	int width = points.get(3)->getX() - points.get(0)->getX();
	// 높이 * 너비 반환
	return std::abs((double)height * width);
}
// Rectangle에는 <Polygon>, <get>이 사용되었다.


// <Polygon> 구현

	// 다각형의 갯수를 세는 numPolygons 생성
int Polygon::numPolygons = 0;
	// 소멸자가 --numPolygons이므로 ++로 구현
Polygon::Polygon(const Point pointArr[], const int numPoints) : points(pointArr, numPoints)
{
	++numPolygons;
}


// <get> 구현
	
const Point* PointArray::get(const int pos) const
{
	// 범위내의 index일때 배열 반환
	if (pos >= 0 && pos < size)
		return points + pos;
	else
		return NULL;
}
// get에는 <Pointarray>가 사용되었다.


// <Pointarray> 구현

	// Pointarray 생성자 구현
PointArray::PointArray(const Point pts[], const int size)
{
	this->size = size;
	points = new Point[size];
	for (int i = 0; i < size; ++i)
	{
		points[i] = pts[i];
	}
}
	// Pointarray 소멸자 구현
PointArray::~PointArray()
{
	delete[] points;
}