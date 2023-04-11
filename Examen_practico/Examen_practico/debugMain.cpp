#include "Dependencias.h"
#include "Vista.h"
#include <Windows.h>


int main()
{
	system("color 0F");

	Vista* vista = new Vista();
	vista->cargaDatos();

	delete vista;

}