#ifndef TRIANGLE_LIST_H
#define TRIANGLE_LIST_H

#include <list>
#include <QColor>

#include "Point.h"
#include "Object.h"

// ����� ����������� ������� ��� �������������� � ����� �����
class TriangleInList
{
public:
	Point list_original[3]; // ������ ������ �� ��������������
	Point list_changed[3]; // ������ ������ ����� ��������������

	int state; // ��������� �������� - ��������, ���������� � �.�.
	int attr; // ���������� �������� - ������������ �� ���� ��� ������, ����� ��� ������������, ����������� �������� ����
    QColor color; // ����

	TriangleInList *next;
	TriangleInList *prev;

				 /*������������ */
	TriangleInList(const Point &p1, const Point &p2, const Point &p3);
	TriangleInList(const Triangle &triangle);
	~TriangleInList();

	TriangleInList& operator=(const TriangleInList& other) noexcept;

	TriangleInList& operator=(TriangleInList&& other)noexcept;

	bool isEqual(const TriangleInList &B)noexcept;

	bool operator==(const TriangleInList &B)noexcept;

	bool operator!=(const TriangleInList &B)noexcept;
};

#define ARR_SIZE 1000

class RenderList
{
public:
	int state; // ��������� ������ ������������
	int attr; //  �������� ������
	TriangleInList* ptrs[ARR_SIZE]; //������ ������������
	// �������� ������ �� ���������� ��������������� �����������

	TriangleInList data[ARR_SIZE]; // �������� ������ � ���������������
	int size; // ���������� ���������������
	void reset()
	{
		size = 0;
	}
};

#endif
