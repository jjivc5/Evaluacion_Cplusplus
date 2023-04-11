#include "Prendas.h"

Prendas::Prendas()
{
	calidad = false;
	cantidadStock = 0;
	precioUnitario = 0.0;
	precioSalida = 0.0;
}

Prendas::~Prendas()
{

}

void Prendas::actualizarPrecio()
{


}

void Prendas::setPrecio(float valor)
{
	this->precioUnitario = valor;
}

void Prendas::setCalidad(bool z)
{
	this->calidad = z;
}

void Prendas::setUnidades(int cantidad)
{
	this->cantidadStock = cantidad;
}
 
bool Prendas::devolverCalidad()
{
	return calidad;
}

int Prendas::devolverStock()
{
	return cantidadStock;
}

float Prendas::devolverPrecio()
{
	return precioUnitario;
}