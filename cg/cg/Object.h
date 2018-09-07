#ifndef OBJECT_H
#define OBJECT_H

//#include "Scene.h"
//#include "Triangle.h"
//#include "Vector.h"

#include <cmath>

#define OBJECT_STATE_ACTIVE 101
#define OBJECT_STATE_PASSIVE 102
#define OBJECT_STATE_VISIBLE 103
#define OBJECT_STATE_INVISIBLE 104

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

	Object()
	{
		id = get_id();
		state = OBJECT_STATE_PASSIVE | OBJECT_STATE_INVISIBLE;
		attr = 0;
		avg_radius = 0;
		max_radius = 0;
		center = Point();
		dir = Vector(); ux = Vector(); uy = Vector(); uz = Vector();
		vertex_local = {};
		vertex_trans = {};
		vertices_size = 0;
		polygons = {};
		polygons_size = {};
		name = "no name";
	}

	void updateRad()
	{
		if (vertex_local.size() < 1)
			return;

        double mx = max_radius * max_radius, curr = 0;
		double px, py, pz;
		avg_radius = 0;
		for (Point p : vertex_local)
		{
			px = p.x; py = p.y; pz = p.z;
            if ((curr = (px * px + py * py + pz * pz)) > mx)
				mx = curr;
			avg_radius += curr;
		}
		max_radius = sqrt(mx);
		avg_radius /= vertex_local.size();
	}

};

int Object::next_id = 0;

// �����������, ��� ������������� � ��������� �������������� ����� ������ ������
// ������������ ����� �������� ����������
// http://www.gamedev.ru/code/forum/?id=40728
// http://rsdn.org/forum/alg/3461405.hot

#endif
