#include "Printer.h"



void Printer::SetString(const char * input)
{
	strcpy(str, input);
}

void Printer::ShowString()
{
	cout << str << endl;
}

Printer::Printer()
{
}


Printer::~Printer()
{
}
