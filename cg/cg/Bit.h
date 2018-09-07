#ifndef BIT_H
#define BIT_H

// ������� ��� ������ � ������
#define SET_BIT(word, bit_flag) \
	((word) = ((word) | (bit_flag)))
#define RESET_BIT(word, bit_flag) \
	((word) = ((word) & (~bit_flag)))

#endif
