#pragma once
#ifndef prettyPrint_H
#define prettyPrint_H
enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void txtColor(enum::ConsoleColor);	//	����� ������ �������, ��������� ���������� ����� ����� 
void txtColor(int);					//	��������� �����

void print_color(const char, enum::ConsoleColor color);	// ������������ ������ � �������� ����. ����. ������
														// ����� �����

void print_color(std::string, enum::ConsoleColor);		// ������������ ����� � �������� ���� 
														// ����� �����
#endif