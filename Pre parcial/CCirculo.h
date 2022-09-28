#pragma once
#include "CFigura.h"
#include <iostream>
using namespace std;
using namespace System;
class CCirculo :public CFigura
{
private:
public:
	//constructura o destructor
	CCirculo();
	CCirculo(int _x, int _y, int _dx, int _dy);
	//acciones o metodos propios
	void Dibujar();
	void Mover();
	void Borrar();
};
CCirculo::CCirculo() {};
CCirculo::CCirculo(int _x, int _y, int _dx, int _dy) :CFigura(_x, _y, _dx, _dy )
{
	forma = 2;
	alto = 5; ancho = 10;
}
void CCirculo::Dibujar()
{
	//tipo 2
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(x, y);	       cout << "    **    ";
	Console::SetCursorPosition(x, y + 1);	   cout << " *      * ";
	Console::SetCursorPosition(x, y + 2);	   cout << "*        *";
	Console::SetCursorPosition(x, y + 3);	   cout << " *      * ";
	Console::SetCursorPosition(x, y + 4);	   cout << "    **    ";
}
void CCirculo::Borrar()
{
	Console::SetCursorPosition(x, y);	   	   cout << "          ";
	Console::SetCursorPosition(x, y + 1);  	   cout << "          ";
	Console::SetCursorPosition(x, y + 2);  	   cout << "          ";
	Console::SetCursorPosition(x, y + 3);  	   cout << "          ";
	Console::SetCursorPosition(x, y + 4); 	   cout << "          ";
}
void CCirculo::Mover()
{
	if (x + dx < 0 || x + dx + ancho > 79)dx = dx * -1;
	x += dx;
}