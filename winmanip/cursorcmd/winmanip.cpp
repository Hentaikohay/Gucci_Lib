#include "winmanip.h"
void SetWindow(const size_t& width, const size_t& height)
{
	_COORD coord = { width, height };

	//определяет координаты верхнего левого и нижнего правого углов
	_SMALL_RECT Rect = {0,0, height - 1, width - 1};	
	
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // ссылка на окно
	SetConsoleScreenBufferSize(Handle, coord);            // изменяет размер внутреннего буфера консоли
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // прокручивает текущую видимую часть внутри окна консоли
}
void Gotoxy(COORD p)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
char GetCursorChar()
{
	char c = '\0';
	CONSOLE_SCREEN_BUFFER_INFO con;
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hcon != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(hcon, &con))
	{
		DWORD read = 0;
		if (!ReadConsoleOutputCharacterA(hcon, &c, 1, con.dwCursorPosition, &read) || read != 1)
			c = '\0';
	}
	return c;
}
COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
		return cbsi.dwCursorPosition;

	// The function failed. Call GetLastError() for details.
	return {0, 0};
	
}