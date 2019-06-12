#include <Windows.h>
#include <iostream>
#include <string>
#include "prettyPrint.h"
void txtColor(enum::ConsoleColor a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | a));
}
void txtColor(int a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | a));
}
void print_color(const char target, enum::ConsoleColor color)
{
	txtColor(color);
	std::cout << target;
	txtColor(White);
}
void print_color(std::string target, enum::ConsoleColor color)
{
	txtColor(color);
	std::cout << target;
	txtColor(White);
}


