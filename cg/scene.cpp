#include "Scene.h"

void Scene::localToWorld()
{
    Point point_tmp;
    for (Object obj : objects)
    {
        obj.vertex_trans.clear();
        for (Point point : obj.vertex_local)
        {
            point_tmp = Point(point.x + obj.center.x,
                point.y + obj.center.y, point.z + obj.center.z, point.w);
            obj.vertex_trans.push_back(point_tmp);
        }
    }
}

Point Scene::cameraTransformation(Point old)
{
    // ����� �����
    Point ret(old);

    // ������� �������� ��� �������������� �����
    Rotate rotate;
    RotateOptions ropX(AXIS_X, camera.ang_x, true);
    RotateOptions ropY(AXIS_Y, camera.ang_y, true);
    RotateOptions ropZ(AXIS_Z, camera.ang_z, true);

    MoveOptions mop(&camera.point, true);
    Move move;

    // ��������� ������� ��������������
    Transformation::apply(ret, move, mop);
    Transformation::apply(ret, rotate, ropY);
    Transformation::apply(ret, rotate, ropX);
    Transformation::apply(ret, rotate, ropZ);

    return ret;
}

void Scene::worldToCam()
{
    Rotate rotate;
    RotateOptions ropX(AXIS_X, camera.ang_x, true);
    RotateOptions ropY(AXIS_Y, camera.ang_y, true);
    RotateOptions ropZ(AXIS_Z, camera.ang_z, true);

    MoveOptions mop(&camera.point, true);
    Move move;

    for (Object obj : objects)
    {
        for (Point point : obj.vertex_trans)
        {
            point = Point(point.x - camera.point.x,
                point.y - camera.point.y, point.z - camera.point.z, point.w);

            //YXZ ������� 437
            Transformation::apply(point, move, mop);
            Transformation::apply(point, rotate, ropY);
            Transformation::apply(point, rotate, ropX);
            Transformation::apply(point, rotate, ropZ);
        }
    }
    Transformation::apply(camera.point, move, mop);
    Transformation::apply(camera.point, rotate, ropY);
    Transformation::apply(camera.point, rotate, ropX);
    Transformation::apply(camera.point, rotate, ropZ);
}

Scene::Scene()
{
    this->ar = 1;
    this->fov = 90;
    this->d = 1;
}

// �������� ������������� ��������� �� ��������� Z
bool Scene::cutZ(int culL_flags, Point sphere, Object obj )
{
    // ���������� ���������� ��������� ������
    double farZ = camera.far_clip_z;
    double nearZ = camera.near_clip_z;

    // ������ ����� � z-���������� ������ �����
    double rad = obj.max_radius;
    double sZ = sphere.z;

    if (culL_flags & CULL_OBJECT_Z)
    {
        if ( // ������� ����� ����� �� ������� ����������
                ((sZ - rad) > farZ)
                ||
                ((sZ + rad) < nearZ)
           ) // ������� ����� ����� ����� ������� ����������
        {
            SET_BIT(obj.state, OBJECT_STATE_CULLED);
            return true;
        }
    }
    return false;
}

// ������������� ������ �� ��� �
// ����� ���� �� ��������������� ����������
// ����������, �� ����� ��������� �������� ��������
// �������������, ��� ��� ��� ��������� ������. ����
// ������� ��������� ����� ����� ��������������
// ���������������, ������ ���������� �����������,
// ������ �����������, ��� ��� �� ���
bool Scene::cutX(int culL_flags, Point sphere, Object obj )
{
    // ������ �����
    double rad = obj.max_radius;

    // ������ ������ ������ � ��������� �� ���������
    double width = camera.viewplane_width;
    double dist = camera.view_dist;

    // ���������� ������ �����
    double sX = sphere.x;
    double sZ = sphere.z;

    if (culL_flags & CULL_OBJECT_X)
    {
        // �������� ��������� ����� ������ � ����� �����
        // ����� �������������� ����� ������� ������������
        // ������ � ����� ���������� ���������
        double z_test = (0.5) * width * sZ / dist;

        if ( // ����� ����� ����� �� ������ ������� ������
                ((sX - rad) > z_test)
                ||
                ((sX + rad) < -z_test)
           ) // ������ ����� ����� �� ����� ������� ������
        {
            SET_BIT(obj.state, OBJECT_STATE_CULLED);
            return true;
        }
    }
    return false;
}

// �� �������� � X
bool Scene::cutY(int culL_flags, Point sphere, Object obj )
{
    // ������ �����
    double rad = obj.max_radius;

    // ������ ������ ������ � ��������� �� ���������
    double height = camera.viewplane_height;
    double dist = camera.view_dist;

    // ���������� ������ �����
    double sY = sphere.y;
    double sZ = sphere.z;

    if (culL_flags & CULL_OBJECT_Y)
    {
        // �������� ��������� ����� ������� � ����� ������
        // ����� �������������� ����� ������� ������������
        // ������ � ����� ���������� ���������
        double z_test = (0.5) * height * sZ / dist;

        if ( // ������ ����� ����� ���� ������� ���������
                ((sY - rad) > z_test)
                ||
                ((sY + rad) < -z_test)
           ) // ������� ����� ����� ���� ������ ���������
        {
            SET_BIT(obj.state, OBJECT_STATE_CULLED);
            return true;
        }
    }
    return false;
}

// ���������� ��������, 574
// ������ ������� ������������� �������,
// �� �������� � ������� ���������. ��� ����
// ������������ ��������� ������ � �������. � �������
// ��������� culL_flags ������������, �� ����� ����
// ������� ����������� ���������- �� ��� �,�,z ��� ��
// ����, ��� ���� ��� ����� ����� ���������� � �������
// ���������� ��������� ���. (����������� �������)
// ���� ������ ���������������, ��� ��������� ����������.
// � ������� ��������������, ��� � ������, � ������ ������
// ���������!

void Scene::removeObject(int culL_flags)
{
    // ����� ������� � ����������� ������
    Point sphere_center;

    // ������ �� ���� ��������
    for (Object obj : objects)
    {
        // �������� ����� ������� � ���������� �� ��������
        // ��������� �����, ����������� �� ������ ����������
        sphere_center = cameraTransformation(obj.center);

        // ������������� �� ��� z
        if (cutZ(culL_flags, sphere_center, obj))
            continue;

        // ������������� �� ��� x
        if (cutX(culL_flags, sphere_center, obj))
            continue;

        // ������������� �� ��� y
        if (cutY(culL_flags, sphere_center, obj))
            continue;
    }
}

// 580
// ����������. � ���� ������� �� ������������ �������,
// ������� ������� �� ������� ������� ���
// ��������������, ���������� ��������� �������������,
// ��������� ��� ���� ��������� ������, ������������ �
// ������ vertex_trans, � ����� ���������� �����, �
// ������� ����������� ������. �������� ��������, ���
// ��� ������� �������������� ��������������� ������
//����������������� �����������

void Scene::removeBackSurfaces()
{
    // ������ �����
    Point p0;

    // �������� �������� �� ������ ������
    std::list<Point>::iterator it;

    // ������ ������� � ������, ������������ � ����� ����������
    Vector n, view;

    // ������ ��������� ���������� ������������
    double dp;

    // ������������ ������ ������ �����
    for (Object obj : objects)
    {
        // ��������� �� ���������� �� ������
        if (obj.state & OBJECT_STATE_CULLED)
            continue;

        // ������������ ������ ������������� �������
        for (Triangle pol : obj.polygons)
        {
            // �������� �� ������������
            if ( // ���� ������� �� ��������
                    (!(pol.state & POLYGON_STATE_ACTIVE)) // ���
                    || // ��� ����������
                    (pol.state & POLYGON_STATE_CLIPPED) // ���
                    || // �������������(������ ����������, �.�. ��� ������ ����� �����)
                    (pol.state & POLYGON_ATTR_2SIDED) // ���
                    || // ���������� ���������(������ ������)
                    (pol.state & POLYGON_STATE_BACKFACE)
               )
            { //�� ���������� ���� �������
                continue;
            }

            // �������
            n = pol.normalTrans();

            // �������� ����� ��������� - ��� ��
            // ������ ������� �������
            it = obj.vertex_trans.begin();
            std::advance(it, pol.indexes[0]);
            p0 = *it;

            // ������ ������������ �� ������
            // ������� ������� � ����� ������
            view = Vector(p0, camera.point);

            // ��������� ������������
            dp = Vector::scalarMultiplication(n, view);

            // ���� ��� > 0, �� ����������� ��������� �������,
            // ���� = 0 - ��� ���� �����, � ���� < 0, ��
            // ����������� ��������
            if (dp <= 0.0) // �������� � 0 �� ���������...
            {
                SET_BIT(pol.state,
                        POLYGON_STATE_BACKFACE);
            }
        }
    }
}
