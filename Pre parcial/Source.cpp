#include "Controlador.h"
#include <conio.h>
void main()
{
	Console::CursorVisible = false;
	Controlador objman;
	char letra;
	while (1)
	{
		if (kbhit())
		{
			letra = toupper(_getch());
		     objman.Insertar(letra);
		}
		objman.Dibujar();
		_sleep(50);
		objman.Borrar();
		objman.Colision();
		objman.Mover();
	}
}