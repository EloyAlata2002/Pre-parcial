#pragma once
#include "CFigura.h"
#include <iostream>
using namespace std;
using namespace System;
class CDisco :public CFigura
{
private:
public:
	//constructura o destructor
	CDisco();
	CDisco(int _x, int _y, int _dx, int _dy);
	//acciones o metodos propios
	void Dibujar();
	void Mover();
	void Borrar();
};
CDisco::CDisco() {};
CDisco::CDisco(int _x, int _y, int _dx, int _dy) :CFigura(_x, _y, _dx, _dy)
{
	forma = 1;
	alto = 5; ancho = 8;
}
void CDisco::Dibujar()
{
	//tipo 1
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x,y);	   cout<<"   ..   ";
		Console::SetCursorPosition(x,y+1);	   cout<<".d8888b.";
		Console::SetCursorPosition(x,y+2);	   cout<<"88888888";
		Console::SetCursorPosition(x,y+3);	   cout<<" Y8888Y ";
		Console::SetCursorPosition(x,y+4);	   cout<<"   ''   ";
}
void CDisco::Borrar()
{
	    Console::SetCursorPosition(x, y);	   cout<<"        ";
	    Console::SetCursorPosition(x, y + 1);  cout<<"        ";
	    Console::SetCursorPosition(x, y + 2);  cout<<"        ";
	    Console::SetCursorPosition(x, y + 3);  cout<<"        ";
	    Console::SetCursorPosition(x, y + 4);  cout<<"        ";
}
void CDisco::Mover()
{
	if (y + dy < 0 || y + dy + alto > 24)dy = dy * -1;
	y += dy;
}
