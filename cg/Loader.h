#ifndef LOADER_H򠴍������������������������������������������������������������������������������਍⌀椀渀挀氀甀搀攀 㰀椀漀猀琀爀攀愀洀㸀�����������������������������������������򠴀����������������������������
#include "Object.h"򠴍�����������������嬀�韀�ៀ�埀�韀�ퟀ�ៀ�ퟀ�ៀ�ퟀ�埀�埀�ៀ�韀�韀�ៀ�埀�韀�ៀ�埀�ퟀ�埀�ៀ�਍����������������������������������������������������������������ÿ���ÿ���ÿ�������������������ÿ�ÿ�������������������ÿ����������������������������������������������������������������������������
#define PLX_SHADE_MODE_MASK 0x6000򠴍��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������਍ऀऀऀऀऀऀऀ ⼀⼀ 砀砀砀砀砀砀砀砀椀洀椀椀椀椀 ⴀ 㠀ⴀ񃄀񃠀񄈀񃸀񃈀񄬀񃤀������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������򠴀򐀀򐀀򐀀򐀀򐀀򐀀򐀀����������������������������������
							 // Цвет многоугольника задается в формате RGB򠴍����������������������������������������嬀�ៀ�韀�韀�ퟀ�ퟀ�ៀ�ៀ�ퟀ�埀�埀�埀�韀�ៀ�ퟀ�ퟀ�ៀ�ퟀ�ៀ�埀�ៀ�ៀ�韀�ៀ�ퟀ�埀�埀�ៀ�埀�ퟀ�ퟀ�ៀ�埀�韀�埀�韀�韀�埀�韀�ퟀ�ៀ�ퟀ�埀�ퟀ�ៀ�਍⌀搀攀昀椀渀攀 倀䰀堀开䌀伀䰀伀刀开䴀伀䐀䔀䨀一䐀䔀堀䔀䐀开䘀䰀䄀䜀 　砀　　　　��������������������������਍��������ÿ�����������������ÿ�������������ÿ���������ÿ�ÿ���ÿ�ÿ��������������������������������������������������������������
	// Многоугольник односторонний򠴍������������������������������
���������������������������������������������������������������������������������������������������������������������������������������������������������������਍ऀ⼀⼀ 񁼀񃬀񃸀񄄀񃨀񃸀񃔀 񃜀񃀀񄈀񃔀񃴀񃔀񃴀񃠀񃔀���������������������������������������������������������������������������������������������������������������������������򠴀�������������������������������������������
	// Затенение по Фонгу򠴍����������������������������������������嬀�ៀ�਍挀氀愀猀猀 䰀漀愀搀攀爀���਍������ÿ�������ÿ�ÿ�ÿ�����������������ÿ���������������ÿ�����ÿ�����������ÿ�����������ÿ�������������ÿ���ÿ������������������������������������������������������������������������������������������������������������������
	// пропускает комментарии и пустые строки. Функция򠴍򐀀��������������������������������������������������������
��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������਍    笀�����������������������������������������������������������������������������򠴀������������������
        {򠴍������������������������������������������������������������嬀�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�埀�ៀ�ퟀ�ៀ�埀�埀�ퟀ�埀�ៀ�ퟀ�ퟀ�ퟀ�ퟀ�埀�韀�韀�韀�ퟀ�韀�ퟀ�ퟀ�韀�韀�ៀ�ퟀ�ퟀ�韀�ퟀ�埀�ៀ�ៀ�韀�韀�ៀ�਍            昀漀爀 ⠀氀攀渀最琀栀 㴀 猀琀爀氀攀渀⠀戀甀昀昀攀爀⤀Ⰰ 椀 㴀 　㬀���������������������������������������������������������������������������������������������������������������ÿ���������ÿ�����ÿ�����ÿ���������ÿ�������������ÿ�����ÿ�����ÿ�ÿ���ÿ�ÿ���������ÿ�ÿ�ÿ������������������������������������������������������
            // Теперь понятно, что считанная строка򠴍���������������������������������������������������������������������������������������������������������������������������਍�����������������������������������������������������������������������������������������������������������������������������������������򠴀������
		std::cout << "\n Ошибка в файле " <<򠴍򐀀򐀀򐀀����������������������������������������������嬀�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�ퟀ�埀�埀�ퟀ�埀�埀�ퟀ�ퟀ�埀�ퟀ�ퟀ�ៀ�埀�ퟀ�埀�埀�ퟀ�ퟀ�ퟀ�ퟀ�ៀ�埀�埀�韀�ៀ�਍ऀ紀��਍����������ÿ���������������ÿ���ÿ���������������������ÿ���������������������������ÿ��������������������������������������������������������������������������������������������������������������������������������
        RotateOptions rop, MoveOptions mop)򠴍򐀀��
	��������������������������������������������������������������������������������������������������������਍ऀऀ���������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������򠴀�������������������������������������
򠴍򐀀򐀀��������������������嬀�ៀ�ៀ�ៀ�埀�ퟀ�ퟀ�ៀ�ퟀ�埀�ퟀ�ៀ�ퟀ�埀�韀�ퟀ�ៀ�埀�ퟀ�埀�ៀ�ퟀ�ៀ�埀�ៀ�ៀ�ៀ�ퟀ�ퟀ�埀�埀�埀�ៀ�ៀ�ៀ�ៀ�਍ऀऀ笀��������������������������������������਍ऀऀऀऀ�������������������ÿ���ÿ�ÿ���ÿ����������������������������������������������������
		}򠴍�
	��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������਍ऀऀ笀������������������������������������������������������������������������������������������������������������������������������������������������������������������������������򠴀򐀀򐀀򐀀��������������������������������������
		}򠴍嬀�ៀ�ៀ�韀�韀�ퟀ�ퟀ�ៀ�ퟀ�韀�ퟀ�韀�ퟀ�ퟀ�韀�ៀ�ퟀ�ퟀ�ៀ�埀�ퟀ�埀�埀�韀�ퟀ�ៀ�ퟀ�ퟀ�ៀ�ퟀ�埀�ퟀ�ퟀ�ퟀ�埀�ퟀ�ៀ�ៀ�ퟀ�埀�ៀ�埀�ៀ�埀�埀�ퟀ�ៀ�਍ऀऀ猀猀挀愀渀昀⠀琀漀欀攀渀开猀琀爀椀渀最Ⰰ ∀─猀 ─搀 ─搀∀Ⰰ������������������਍ऀऀ��������ÿ�����ÿ�����ÿ�����ÿ���ÿ�������ÿ���ÿ���ÿ����������������������������������������������������������
򠴍򐀀򐀀����������������������������������������������
	��������������������������������������������������������������������������������������������������������������������������਍ऀऀऀऀ䔀刀刀伀刀开圀刀伀一䜀开䄀䴀伀唀一吀开伀䘀开嘀䔀刀吀䔀堀⤀㬀��������������������������������������������������������������������������������������򠴀�
		// Проверка на корректность количества полигонов򠴍򐀀򐀀���������������������������������嬀�ៀ�ៀ�韀�ៀ�਍ऀऀऀ洀攀猀猀愀最攀⠀昀椀氀攀渀愀洀攀Ⰰ ∀񃼀񃸀񃬀񄌀񄜀񃠀񄈀񄰀 񃨀񃸀񃬀񃠀񄜀񃔀񄄀񄈀񃈀񃸀 񃼀񃸀񃬀񃠀񃌀񃸀񃴀񃸀񃈀∀Ⰰ�������������������������������������਍ऀऀ��ÿ���ÿ�������ÿ�����������������������ÿ�ÿ���ÿ�������������������ÿ���������ÿ����������
		򠴍򐀀򐀀�������������������������������������������������������
	���������������������������������������������������������������������������������������������਍ऀऀ匀挀愀氀攀 猀挀愀氀攀㬀���������������������������������������������������������������򠴀򐀀򐀀������������������������������������������������
		{򠴍򐀀򐀀򐀀��������������������������������嬀�ៀ�ៀ�ៀ�ៀ�埀�ퟀ�ퟀ�ៀ�ퟀ�ퟀ�韀�韀�ៀ�埀�韀�韀�ퟀ�埀�ៀ�埀�韀�ퟀ�ៀ�ퟀ�韀�ៀ�ퟀ�ퟀ�ៀ�埀�ៀ�ퟀ�埀�ៀ�埀�埀�ៀ�埀�ퟀ�ퟀ�埀�ៀ�ៀ�ퟀ�ퟀ�埀�ៀ�ៀ�ៀ�ៀ�਍ऀऀऀ笀��������������������������������������������਍ऀऀऀऀऀ�������������������������ÿ�����ÿ���ÿ���ÿ����������������������������������������������������������������
			}򠴍�
		��������������������������������������������������������������������������������������������������������������������������������������������������਍��������������������������������������������������������������������������������������������������������������������������������������������������򠴀򐀀򐀀򐀀򐀀��������������������������
򠴍򐀀򐀀򐀀����������������������������������������嬀�ៀ�ៀ�ៀ�ퟀ�埀�ៀ�埀�韀�埀�韀�埀�ៀ�ៀ�ퟀ�ៀ�韀�埀�埀�埀�ៀ�ퟀ�ퟀ�ퟀ�ៀ�ퟀ�韀�埀�埀�ៀ�韀�ퟀ�ៀ�埀�埀�ៀ�埀�ퟀ�ៀ�ퟀ�韀�ퟀ�韀�韀�ៀ�ퟀ�埀�埀�ៀ�韀�韀�ퟀ�ៀ�ퟀ�ퟀ�韀�韀�ៀ�ퟀ�ៀ�ퟀ�ퟀ�韀�韀�ퟀ�ៀ�韀�ៀ�਍ऀऀ紀����਍ऀ��������ÿ�����ÿ�������������ÿ�����������ÿ�����������ÿ���ÿ�������ÿ���ÿ���ÿ���ÿ�������������ÿ���ÿ������������������������������������������������
򠴍򐀀򐀀��������������������������
	�������������������������������������������������������������������������������������������������਍ऀऀ椀渀琀 瀀漀氀礀开渀甀洀开瘀攀爀琀猀 㴀 　㬀�������������������������������������������������������������������������������������������������������������򠴀򐀀򐀀��������������������
򠴍򐀀򐀀���������������������������������������嬀�ៀ�ៀ�ៀ�埀�ퟀ�ퟀ�ៀ�埀�ퟀ�ៀ�ퟀ�ៀ�ퟀ�ퟀ�ៀ�埀�ퟀ�ៀ�ퟀ�埀�ퟀ�ퟀ�ៀ�埀�ퟀ�ៀ�ퟀ�韀�韀�ៀ�਍��������������������������������������������਍ऀ����������ÿ���������������ÿ���������������������������ÿ�����ÿ���������ÿ�������������ÿ���ÿ���������������ÿ�ÿ����������
			// Извлекаем строку информации򠴍򐀀򐀀򐀀�����������������������������������������������
		�������������������������������������������������������������������������������������������������������������������������������������������������������਍ऀऀऀऀ爀攀琀甀爀渀 䔀刀刀伀刀开圀刀伀一䜀开倀伀䰀夀䜀伀䴀开䐀䔀匀䌀刀䤀倀吀伀刀㬀����������򠴀򐀀򐀀򐀀��������������������������������������������������������
			sscanf(token_string, "%s %d %d %d %d", tmp_string,򠴍򐀀򐀀򐀀򐀀�����������������������������������������������嬀�ៀ�਍ऀऀऀ⼀⼀ 񁼀񄀀񃸀񃈀񃔀񄀀񄼀񃔀񃰀Ⰰ 񄜀񄈀񃸀 񃼀񃸀񃬀񃠀񃌀񃸀񃴀 񃠀񃰀񃔀񃔀񄈀 ㌀ 񃈀񃔀񄀀񄠀񃠀񃴀񄬀�����������������������������਍ऀऀ��ÿ��������������������������������������������������������������������������������������������������������������������������������
					ERROR_TOO_MUCH_VERTEX_IN_POLYGON);򠴍򐀀򐀀򐀀򐀀�����������������������������������������
		�����������������������������������������������਍ऀऀऀ椀昀 ⠀⠀椀渀搀攀砀㄀ 㰀 　⤀ 簀簀 ⠀椀渀搀攀砀㈀ 㰀 　⤀ 簀簀 ⠀椀渀搀攀砀㌀ 㰀 　⤀⤀��������������������������������������������������������������������������������������������򠴀򐀀򐀀򐀀򐀀򐀀��������������������
				return ERROR_WRONG_INDEX;򠴍򐀀򐀀򐀀�嬀�ៀ�਍ऀऀऀ⼀⼀ 񂄀񃸀񃜀񃐀񃀀񃔀񃰀 񃼀񃸀񃬀񃠀񃌀񃸀񃴀 񃠀 񃼀񃸀񃰀񃔀񄤀񃀀񃔀񃰀  񄄀񄄀񄬀񃬀񃨀񄌀 񃴀񃀀 񃸀񃄀񄨀񃔀񃨀񄈀 񃠀 ㌀ 񃠀񃴀񃐀񃔀񃨀񄄀񃀀�����������������������������������������਍ऀऀऀ����ÿ�ÿ�������ÿ���������ÿ���������ÿ�����ÿ���ÿ���ÿ������������������������������������������������
򠴍򐀀򐀀򐀀�������������������������������������������������
		�����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������਍ऀऀऀऀ⠀琀洀瀀开猀琀爀椀渀最嬀　崀 㴀㴀 ✀　✀⤀�����������������������������������������������������������������������������������򠴀򐀀򐀀򐀀򐀀��
				sscanf(tmp_string, "%x", &surface_desc);򠴍򐀀򐀀򐀀����嬀�ៀ�ៀ�ៀ�ៀ�韀�ៀ�埀�埀�ៀ�韀�ៀ�韀�ퟀ�ៀ�韀�韀�ퟀ�ៀ�ퟀ�ៀ�ퟀ�韀�ៀ�ퟀ�ퟀ�ៀ�ퟀ�韀�韀�ퟀ�埀�ៀ�埀�韀�ៀ�韀�ៀ�਍������������������������������������������਍ऀऀ��ÿ��������������������������������������������������������������������������������������
                    POLY4DV1_ATTR_2SIDED);򠴍򐀀򐀀򐀀��
		���������������������������������������������������������������਍ऀऀऀऀऀ倀伀䰀夀㐀䐀嘀㄀开䄀吀吀刀开㄀匀䤀䐀䔀䐀⤀㬀����������������������������򠴀򐀀��
};򠴍嬀�韀�ៀ�埀�ퟀ�ៀ�埀�ៀ�਍                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      �