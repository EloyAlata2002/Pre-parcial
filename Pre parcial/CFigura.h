#pragma once
#include <iostream>
using namespace std;
using namespace System;
class CFigura
{
protected:
	int x, y, dx, dy;
	int forma;
	int ancho, alto;
public:
	CFigura();
	CFigura(int _x, int _y, int _dx, int _dy);
	virtual void Borrar() {};
	void CambiaDx();
	void CambiaDy();
	int GetX();
	int GetY();
	int GetForma();
	int GetAncho();
	int GetAlto();
	virtual void Dibujar() {};
	virtual void Mover() {};
};
CFigura::CFigura() {}
CFigura::CFigura(int _x, int _y, int _dx, int _dy)
{
	x = _x; y = _y; dx = _dx; dy = _dy;
}
void CFigura::CambiaDx() { dx = dx * -1; }
void CFigura::CambiaDy() { dy = dy * -1; }
int CFigura::GetForma() { return forma; }
int CFigura::GetX() { return x; }
int CFigura::GetY() { return y; }
int CFigura::GetAncho() { return ancho; }
int CFigura::GetAlto() { return alto; }