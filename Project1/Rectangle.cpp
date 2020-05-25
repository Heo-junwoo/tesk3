#include<iostream>
#include "Rectangle.h"
#include <cmath>
using namespace std;


// ���Ǵ� �Լ��� �����Ѵ�

int main()
{
	int x1, y1, x2, y2;
	cout << "���� �ϴ�x ��ǥ : ";
	cin >> x1;
	cout << "���� �ϴ�y ��ǥ : ";
	cin >> y1;
	cout << "���� ���x ��ǥ : ";
	cin >> x2;
	cout << "���� ���x ��ǥ : ";
	cin >> y2;
	

	Point p1(x1, y1), p2(x2, y2);
	Rectangle r(p1, p2);

	cout << "\n���簢���� ���� :" << r.area();
}
// main �Լ������� <Point>, <Rectangle> �� ��� �Ǿ���.


// <Point> ����

	// 4���� Point�� ��� �迭�� ����
Point cordinate[4];
	// 4���� Point�� ������ �ִ� �Լ� ����
Point* setcordinate(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
{	
	// �����ϴ���ǥ�� index = 0�� �������� �ϰ� �ð�������� ������� ���ư���.
	cordinate[0] = p1;
	cordinate[1] = p2;
	cordinate[2] = p3;
	cordinate[3] = p4;
	return cordinate;
}


// <Rectangle> ����

	// Rectangle �����ϴ���ǥ p1, ���������ǥ p2�� �޾� 4���� ���� ��� ����
Rectangle::Rectangle(const Point& p1, const Point& p2)
	: Polygon(setcordinate(p1, Point(p1.getX(), p2.getY()), p2, Point(p2.getX(), p1.getY())), 4) {}

	// area ����
double Rectangle::area() const
{
	// ���� : 1�� y - 0�� y
	int height = points.get(1)->getY() - points.get(0)->getY();
	// �ʺ� : 3�� x - 0�� x
	int width = points.get(3)->getX() - points.get(0)->getX();
	// ���� * �ʺ� ��ȯ
	return std::abs((double)height * width);
}
// Rectangle���� <Polygon>, <get>�� ���Ǿ���.


// <Polygon> ����

	// �ٰ����� ������ ���� numPolygons ����
int Polygon::numPolygons = 0;
	// �Ҹ��ڰ� --numPolygons�̹Ƿ� ++�� ����
Polygon::Polygon(const Point pointArr[], const int numPoints) : points(pointArr, numPoints)
{
	++numPolygons;
}


// <get> ����
	
const Point* PointArray::get(const int pos) const
{
	// �������� index�϶� �迭 ��ȯ
	if (pos >= 0 && pos < size)
		return points + pos;
	else
		return NULL;
}
// get���� <Pointarray>�� ���Ǿ���.


// <Pointarray> ����

	// Pointarray ������ ����
PointArray::PointArray(const Point pts[], const int size)
{
	this->size = size;
	points = new Point[size];
	for (int i = 0; i < size; ++i)
	{
		points[i] = pts[i];
	}
}
	// Pointarray �Ҹ��� ����
PointArray::~PointArray()
{
	delete[] points;
}