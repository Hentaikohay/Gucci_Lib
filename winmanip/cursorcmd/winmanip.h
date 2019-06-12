#pragma once
#include <Windows.h>

void SetWindow(const size_t& width, const size_t& height);	// ��������� ����� '����'

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);	// ���������� ���������� �������

void Gotoxy(COORD p);	// ��������� ������� �� ������� @p

char GetCursorChar();	// ���������� ������ �� ������� ��������� �������
