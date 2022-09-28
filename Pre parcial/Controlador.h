#pragma once
#include "CDisco.h"
#include "CCirculo.h"
#include "CRedondo.h"
#include <vector>
using namespace std;
using namespace System;
class Controlador
{
private:
	vector <CFigura*> vecfig;
public:
	Controlador();
	void Insertar(char letra);
	void Dibujar();
	void Mover();
	void Borrar();
	void Colision();
};
Controlador::Controlador() {}
void Controlador::Insertar(char letra)
{
	Random f;
		int tipo = f.Next(1, 3);
		if (tipo == 1)//vertical rojo
			vecfig.push_back(new CDisco(f.Next(1, 70), f.Next(1, 18), 0, 1 ));
		if (tipo == 2)//horizontal verde
			vecfig.push_back(new CCirculo(f.Next(1, 70), f.Next(1, 18), 1, 0 ));
}
void Controlador::Dibujar()
{
	for (int i = 0; i < vecfig.size(); i++)   vecfig[i]->Dibujar();
}
void Controlador::Mover()
{
	for (int i = 0; i < vecfig.size(); i++)   vecfig[i]->Mover();
}
void Controlador::Borrar()
{
	for (int i = 0; i < vecfig.size(); i++)   vecfig[i]->Borrar();
}
void Controlador::Colision()
{
	Random f;
		if (vecfig.size() > 2)
		{
			for (int i = 0; i < vecfig.size() - 1; i++)
				for (int j = i + 1; j < vecfig.size(); j++)
					if (vecfig[i]->GetForma() == 1 && vecfig[j]->GetForma() == 2|| vecfig[i]->GetForma() == 2 && vecfig[j]->GetForma() == 1)
					{	
						int x1 = vecfig[i]->GetX(); int y1 = vecfig[i]->GetY();
						int x2 = vecfig[j]->GetX();	int y2 = vecfig[j]->GetY();
						int ancho1 = vecfig[i]->GetAncho(); int alto1 = vecfig[i]->GetAlto();
						int ancho2 = vecfig[j]->GetAncho(); int alto2 = vecfig[j]->GetAlto();
						if (!(x1 + ancho1<x2 || y1 + alto1<y2 ||
							x1>x2 + ancho2 || y1>y2 + alto2))
						{
							vecfig[i]->CambiaDx(); vecfig[i]->CambiaDy();
							vecfig[j]->CambiaDx(); vecfig[j]->CambiaDy();
							vecfig.push_back(new CRedondo(f.Next(1, 70), f.Next(1, 18), 1, 1));
							vecfig.erase(vecfig.begin());
						}
						
					}
		}
		
}

