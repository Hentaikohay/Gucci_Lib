#pragma once
#include <Windows.h>

void SetWindow(const size_t& width, const size_t& height);	// Формирует класс 'окна'

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);	// Возвращает координаты каретки

void Gotoxy(COORD p);	// Установка каретки на позицию @p

char GetCursorChar();	// Возвращает символ на который указывает каретка
