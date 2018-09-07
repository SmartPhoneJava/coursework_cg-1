#ifndef LOADER_H
#define LOADER_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ctype.h>

#include "Transformation.h"
#include "Object.h"
#include "Bit.h"
#include "Resource.h"

// ����� ���������� ����� � ������� RGB ��� � ���� �������
#define PLX_RGB_MASK 0x8000
// ����� ���������� ������ ���������
#define PLX_SHADE_MODE_MASK 0x6000
// ����� ������� ��������������
#define PLX_2SIDED_MASK 0x1000
#define PW_COLOR_MASK 0x0fff // xxxxrrrrggggbbbb,
							 // no 4 ���� �� ������ ����� RGB
							 // xxxxxxxximiiii - 8-�������
							 // ������ � ��������� ������
							 // ����� ���������, �������������� ����� ��������� �����
							 // �������� ����� ��������������
							 // ���� �������������� �������� � ������� RGB
#define PLX_COLORJ40DE_RGB_FLAG 0x8000
	// 8-������� ��������� ���� ��������������
#define PLX_COLOR_MODEJNDEXED_FLAG 0x0000
	// ����� ��������������
	// ������������� ������������
#define PU_2SIDED_FLAG 0x1000
	// ������������� �������������
#define PLX_1SIDED_FUG OxOOOO
	// ����� ��������� ��������������
	// ���������� ���������
#define PLX_SHADE_MODE_PURE_FLAG 0x0000
	// ������� ���������
#define PU_SHADE_MODE_FLAT_FLAG 0x2000
	// ��������� �� ����
#define PLX_SHADE_MODE_GOURAUD_FLAG 0x4000
	// ��������� �� �����
#define PW_SHADE_MODE_PHONG_FUG 0x6000

class Loader
{
	// ��� ��������� ��������������� ������� ���������
	// ���������� �� ����� ������ �� ����� � ������� PLG �
	// ���������� ����������� � ������ ������. �������
	// ���������� �������� ������ ��������������� ����� ���
	// �������� NULL, ���� ���� ���� ����
	char *getLine(char* buffer, int maxLength,
		FILE *f)
    {
        size_t length;
        int i;
        while (1)
        {
            if (!fgets(buffer, maxLength, f))
                return nullptr;// ������� �������
            for (length = strlen(buffer), i = 0;
                 isspace(buffer[i]); i++);	// ��������� �� ��������� �� ������ ������
            if ((i >= length) || (buffer[i] == '#'))
                continue;
            // ������ �������, ��� ��������� ������
            // �������� ��������
            return (&buffer[i]);
        }
	}

    void message(char *filename, const char* text,
		const int err)
    {
		std::cout << "\n ������ � ����� " <<
			filename << " ��� ������� " << text <<
            ". ��� ������:" << err;
	}

	// �������� ������ ��� Object obj; &obj;
    int load(Object *object, char* filename, ScaleOptions sop,
        RotateOptions rop, MoveOptions mop)
	{
		FILE *f;
		char buffer[256];
		char *token_string; // ��������� �� ������
		
		// ������������� �������
        object->state = OBJECT_STATE_ACTIVE | OBJECT_STATE_VISIBLE;
        object->center = Point(mop);

		// ��������� ����
		if (!(f = fopen(filename, "r")))
		{
			message(filename, "������� ����",
				ERROR_NO_FILE);
			return ERROR_NO_FILE;
		}

		// ��������� ������ �������, ������� ������ ����
		// ������������ �������
		if (!(token_string = getLine(buffer, 255, f)))
		{
			message(filename, "�������� ���������� �������",
				ERROR_WRONG_VERTEX_DESCRIPTOR);
			return ERROR_WRONG_VERTEX_DESCRIPTOR;
		}

		// ����������� ������ � ����������� �������
		sscanf(token_string, "%s %d %d",
			object->name,
			&object->vertices_size,
			&object->polygons_size);

		// �������� �� ������������ ���������� ������
		if (object->vertices_size < 1)
		{
			message(filename, "�������� ���������� ������",
				ERROR_WRONG_AMOUNT_OF_VERTEX);
			return ERROR_WRONG_AMOUNT_OF_VERTEX;
		}

		// �������� �� ������������ ���������� ���������
		if (object->polygons_size < 1)
		{
			message(filename, "�������� ���������� ���������",
				ERROR_WRONG_AMOUNT_OF_POLYGON);
			return ERROR_WRONG_AMOUNT_OF_POLYGON;
		}
		
		// ���������� ��� �������� ��������� ��������� �������
		double v_x, v_y, v_z;

		// ������ ������ ��������(����������������)
		Scale scale;
		
		// ��������� ������ ������
		for (int v = 0; v < object->vertices_size; v++)
		{
			//��������� ��������� �������
			if (!(token_string - getLine(buffer, 255, f)))
			{
				message(filename, "��������� �������",
					ERROR_WRONG_VERTEX);
				return ERROR_WRONG_VERTEX;
			}

			// ���������� ����������
			sscanf(token_string, "%f %f %f",
				&v_x, &v_y, &v_z);

			// �������� � ������ ������ �������
			object->vertex_local.push_back(
				Point(v_x, v_y, v_z, 1));

			// ��������� ��������������� �������
			Transformation::apply(object->vertex_local.back(), scale, sop);
		}
		
		// ������������� ������������ � ������� �������
		object->updateRad();

		// ���������� �����������
		int surface_desc = 0;

		// ���������� ������ � ��������������, ������ 3
		int poly_num_verts = 0;
		
		// ������ ��������� ������ � ����������� ��������
		char tmp_string[8];

		// ���������� ��� �������� ��������
		int index1, index2, index3;

		// �������� ���������� � ������ ��������
		for (int pol = 0; pol < object->polygons_size; pol++)
		{
			// ��������� ������ ����������
			if (!(token_string = getLine(buffer, 255, f)))
			{
				message(filename, "�������� ���������� ��������",
					ERROR_WRONG_POLYGOM_DESCRIPTOR);
				return ERROR_WRONG_POLYGOM_DESCRIPTOR;
			}

			// ���������� ����������, ���������� ������ � 3 �������
			sscanf(token_string, "%s %d %d %d %d", tmp_string,
				&poly_num_verts, &index1, &index2, &index3);

			// ���������, ��� ������� ����� 3 �������
			if (poly_num_verts != 3)
			{
				message(filename, "���������� ���������� ������ ��������",
					ERROR_TOO_MUCH_VERTEX_IN_POLYGON);
				return ERROR_TOO_MUCH_VERTEX_IN_POLYGON;
			}

			// ���������, ��� ������� ����������
			if ((index1 < 0) || (index2 < 0) || (index3 < 0))
			{
				message(filename, "�������� �������",
					ERROR_WRONG_INDEX);
				return ERROR_WRONG_INDEX;
			}

			// ������� ������� � ��������  ������ �� ������ � 3 �������
            object->polygons.push_back(
				Triangle(object, index1,
					index2, index3));

			// ��������� ���������� ����������� ����� ���� �
			// ����������������� ������� (��� ���� � ��� ������
			// ����� ������� "��"), ����� �������� ��������
			if (
				(tmp_string[0] == '0')
				&&
				(toupper(tmp_string[1]) == 'X')
				)
				sscanf(tmp_string, "%x", &surface_desc);
			else
				surface_desc = atoi(tmp_string);

			if ((surface_desc & PLX_2SIDED_MASK))
			{
				SET_BIT(object->polygons.back().attr,
                    POLY4DV1_ATTR_2SIDED);
			}
			else
			{
				SET_BIT(object->polygons.back().attr,
					POLY4DV1_ATTR_1SIDED);
			}//else
		}
	}
};

#endif
