
#include "Console.h"
using namespace std;

int k;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Console::Error(std::string msg)//, WORD Color)
{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x5b);
	//system(color);
	SetConsoleTextAttribute(hConsole, 0x0C);
	std::cout << "ERROR: " << msg.c_str() << endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void Console::Warning(std::string msg)
{
	SetConsoleTextAttribute(hConsole, 0x0E);
	std::cout << "WARNING: " << msg.c_str() << endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void Console::Text(std::string msg)
{
	SetConsoleTextAttribute(hConsole, 0x07);
	std::cout << msg.c_str() << endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void Console::Good(std::string msg)
{
	SetConsoleTextAttribute(hConsole, 0x0A);
	std::cout << msg.c_str() << endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void Console::Special(std::string msg)
{
	SetConsoleTextAttribute(hConsole, 0x0D);
	std::cout << msg.c_str() << endl;
	SetConsoleTextAttribute(hConsole, 7);
}