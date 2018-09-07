#ifndef OBJECT_H
#define OBJECT_H

class Triangle;

#include "Triangle.h"
#include "Vector.h"
#include "Bit.h"

#include <cmath>

// 754
//��������� ��������
#define OBJECT_STATE_NULL 0x0000
#define OBJECT_STATE_ACTIVE 0x0001
#define OBJECT_STATE_VISIBLE 0x0002
#define OBJECT_STATE_CULLED 0x0004

// ��������
// �������������
#define OBJECT_SINGLE_FRAME 0x0001
// �������������� ������ ��� ��������� ������� .md2
#define OBJECT_MULTIPLE_FRAME 0x0002
// ������, ���������� �������������� � ���������
#define OBJECT_TEXTURE  0x0004

class Object
{
private:
	
public:
	// 478
	int id; //�������� ������������� �������
	const char *name;
	static int next_id; // ���� ���������� ��������
	int state; // ��������� �������
	int attr; // �������� �������

	double avg_radius; // ������� ������ ������� ��� ����������� ������������
	double max_radius; // ������������ ������ �������

    Point center; // ��������� ������� � ������� �����������
	Vector dir; // ��������� ������ �����������
	Vector ux, uy, uz;
	// ��������� ��� ��� ������������ ���������� ������� (�����������
	// ������������� ��� ������ ������� ��������)

	std::list<Point> vertex_local; // ������ ������ � ���������� ������������
	std::list<Point> vertex_trans; // ������ ������ � ���������������� �������� ������������
	int vertices_size; // ������ �������

    std::list<Triangle> polygons; // ������ ���������
	int polygons_size; // ���������� ���������

	static int get_id()
	{
		return next_id++;
	}

    Object();

    void updateRad();

    void reset();


};

// �����������, ��� ������������� � ��������� �������������� ����� ������ ������
// ������������ ����� �������� ����������
// http://www.gamedev.ru/code/forum/?id=40728
// http://rsdn.org/forum/alg/3461405.hot

#endif
