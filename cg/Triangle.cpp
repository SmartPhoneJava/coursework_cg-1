#include "Triangle.h"
#include <iostream>


void Triangle::copy(const Triangle& triangle) noexcept
{

    this->object = triangle.object; // ��������� �� ������ ������
    this-> indexes[0] = triangle.indexes[0]; // 3 ������� ��� ������ 3-�� �����
    this->indexes[1] = triangle.indexes[1];
    this->indexes[2] = triangle.indexes[2];
    this->state = triangle.state; // ��������� �������� - ��������, ���������� � �.�.
    this->attr = triangle.attr; // ���������� �������� - ������������ �� ���� ��� ������, ����� ��� ������������, ����������� �������� ����
    this->color = triangle.color; // ����
}

void Triangle::destroy() noexcept
{
    object = nullptr;
}

Triangle::Triangle(Object* obj, int i1, int i2, int i3,
                   int st, int a, QColor col)
{
    this->object = obj; // ��������� �� ������ ������
    this->indexes[0] = i1; // 3 ������� ��� ������ 3-�� �����
    this->indexes[1] = i2;
    this->indexes[2] = i3;
    this->state = st; // ��������� �������� - ��������, ���������� � �.�.
    this->attr = a; // ���������� �������� - ������������ �� ���� ��� ������, ����� ��� ������������, ����������� �������� ����
    this->color = col; // ����
}

Triangle::Triangle(const Triangle &triangle)
{
	copy(triangle);
}

Triangle::~Triangle()
{
	destroy();
}

Triangle& Triangle::operator=(const Triangle& other) noexcept
{
	destroy();
	copy(other);
	return *this;
}

Triangle& Triangle::operator=(Triangle&& other)noexcept
{
	destroy();
	copy(other);
	other.destroy();
	return *this;
}

// 581 �������� ������ �������
Vector Triangle::getNormal(std::list<Point> vertix)
const noexcept
{
    // ������� ���������, ������� �������� ���������
    // � ����� ������ �������.
    Vector u, v, n;

    // 3 ����� ��������, �������� ���������
    Point p0, p1, p2;

    // ������ � ������� ���������� ��������� �����
    int i = 0, kol = 0;

    // https://metanit.com/cpp/tutorial/7.3.php
     for (auto  it = vertix.begin();
          it != vertix.end(); ++it)
     {
         if (i == indexes[0])
         {
             p0 = *it;
             kol++;
         }

         if (i == indexes[1])
         {
             p1 = *it;
             kol++;
         }

         if (i == indexes[2])
         {
             p2 = *it;
             kol++;
         }

         if (kol == 3)
            it = vertix.end();
         i++;
     }

    // ����� ������ �������������� �� ������� �������,
    // ��� ��� u=pO->p1, v=p0->p2, n=u*v

    u = Vector(p0, p1);
    v = Vector(p0, p2);
    n = Vector::vectorMultiplication(u, v);

    return n;
}
// ������� ��� ��������� ��������
Vector Triangle::normalOrigin() const noexcept
{
    return getNormal(object->vertex_local);
}

// ������� ��� ����������� ��������(����� ���������
// ����� �� ����� ��������� � ������)
Vector Triangle::normalTrans() const noexcept
{
    return getNormal(object->vertex_trans);
}

// ��������� ���������
bool Triangle::isEqual(
	const Triangle &O) noexcept
{
    bool boolObject = this->object == O.object;
    bool boolIndexes = true;
    for (int i = 0; i < 3; i++)
    {
        if (this->indexes[i] == O.indexes[i])
        {
            boolIndexes = false;
            break;
        }
    }

    bool boolInfo = (
                (this->state == O.state)
                &&
                (this->attr == O.attr)
                &&
                (this->color == O.color)
                );

    return (boolObject && boolIndexes && boolInfo);

}

bool Triangle::operator==(const Triangle& other)noexcept
{
	return isEqual(other);
}

bool Triangle::operator!=(const Triangle& other)noexcept
{
	return !isEqual(other);
}
