#pragma once
#include "CFigura.h"
#include <iostream>
using namespace std;
using namespace System;
class CRedondo :public CFigura
{
private:
public:
	//constructura o destructor
	CRedondo();
	CRedondo(int _x, int _y, int _dx, int _dy);
	//acciones o metodos propios
	void Dibujar();
	void Mover();
	void Borrar();
};
CRedondo::CRedondo() {};
CRedondo::CRedondo(int _x, int _y, int _dx, int _dy) :CFigura(_x, _y, _dx, _dy)
{
	forma = 3;
	alto = 5; ancho = 10;
}
void CRedondo::Dibujar()
{
	//tipo 3
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(x, y);	       cout << "   000   ";
	Console::SetCursorPosition(x, y + 1);	   cout << " 0000000 ";
	Console::SetCursorPosition(x, y + 2);	   cout << "0000*0000";
	Console::SetCursorPosition(x, y + 3);	   cout << " 0000000 ";
	Console::SetCursorPosition(x, y + 4);	   cout << "   000   ";
}
void CRedondo::Borrar()
{
	Console::SetCursorPosition(x, y);	   cout << "         ";
	Console::SetCursorPosition(x, y + 1);  cout << "         ";
	Console::SetCursorPosition(x, y + 2);  cout << "         ";
	Console::SetCursorPosition(x, y + 3);  cout << "         ";
	Console::SetCursorPosition(x, y + 4);  cout << "         ";
}
void CRedondo::Mover()
{
	if (y + dy < 0 || y + dy + alto > 24)dy = dy * -1;
	y += dy;
	if (x + dx < 0 || x + dx + ancho > 79)dx = dx * -1;
	x += dx;
}