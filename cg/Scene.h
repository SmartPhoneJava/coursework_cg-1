#ifndef SCENE_H
#define SCENE_H

#include "Object.h"
#include "Camera.h"
#include "Transformation.h"
#include "Bit.h"
#include <list>

//����� ����� ���������
#define CULL_OBJECT_X 0x0001// ��������� �� ��� �
#define CULL_OBJECT_Y 0x0002 // ��������� �� ��� �
#define CULL_OBJECT_Z 0x0004 // ��������� �� ��� �
#define CULL_OBJECT_XYZ (CULL_OBJECT_X | \
CULL_OBJECT_Y| CULL_OBJECT_Z)

// ���������
class Scene
{
private:
public:
    //HDC hdc;
	double A, B, C, D;
	std::list<Object> objects;
	Camera camera;

	int ar;  // ����������� ����� � ������
	int fov; // ���� ������, ������ 90
	int d;   // ���������� �� ��������� ��������

    Scene();

	// 430
    void localToWorld();

	// 435
    void worldToCam();

	//450
	// d - ���������� �� ������
	/*
    void camToAxonometric(int d = 1)
	{
		ar ...
		for (Object obj : objects)
		{
			for (Point point : obj.vertex_trans)
			{
				point.x = d * point.x / point.z;
				point.y = d * point.y / point.z;
			}
		}
	}
	*/

    // �������������� ����� �� ������� ���������
    // � ��������
    Point cameraTransformation(Point old);

    // �������� ������������� ��������� �� ��������� Z
    bool cutZ(int culL_flags, Point sphere, Object obj );

    // �������� ������������� ��������� �� ��������� Y
     bool cutX(int culL_flags, Point sphere, Object obj );

    // �������� ������������� ��������� �� ��������� X
    bool cutY(int culL_flags, Point sphere, Object obj );

    // ���������� ��������, 574
    void removeObject(int culL_flags);

    // �������� �������� ������������(������ ����� ����), 580
    void removeBackSurfaces();
};

#endif
