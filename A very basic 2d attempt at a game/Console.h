#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

class Console
{
public:
	void Error(std::string msg);//,WORD Color);
	void Warning(std::string msg);
	void Text(std::string msg);
	void Good(std::string msg);
	void Special(std::string msg);

private:
};

#endif CONSOLE_H_