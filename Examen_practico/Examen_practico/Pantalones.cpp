#include "Pantalones.h"

Pantalones::Pantalones()
{
	this->chupines = false;
	this->calidad = false;
	this->cantidadStock = 0;
	this->precioUnitario = 0;

}

void Pantalones::setChupines(bool x)
{
	this->chupines = x;
}





bool Pantalones::getChupines()
{
	return chupines;
}


float Pantalones::actualizarPrecio(bool chupines, bool calidad, float precioUnitario)
{
	precioSalida = precioUnitario;

	if (chupines)
	{
		precioSalida *= 0.88;
	}

	if (calidad)
	{
		precioSalida *= 1.3;
	}

	return precioSalida;
	
}



Pantalones::~Pantalones()
{
	
}

