#include "Camisas.h"

Camisas::Camisas() 
{
	this->mangaLarga = false;
	this->cuelloMao = false;
	this->calidad = false;
	this->cantidadStock = 0;
	this->precioUnitario = 0;
}
// Seteo de datos

void Camisas::setMangaLarga(bool x)
{
    this->mangaLarga = x;
}

void Camisas::setCuello(bool y)
{
    this->cuelloMao = y;
}




// Obtencion de datos.
bool Camisas::getMangaLarga()
{
	return mangaLarga;
}
bool Camisas::getCuelloMao()
{
	return cuelloMao;
}

float Camisas::actualizarPrecio(bool mangaLarga, bool cuelloMao, bool calidad, float precioUnitario)
{   
    precioSalida = precioUnitario;

    if (!mangaLarga && !cuelloMao)
    {
        precioSalida *= 0.9;
    }
    if (cuelloMao && mangaLarga)
    {
        precioSalida *= 1.03;
    }
    if (!mangaLarga && cuelloMao)
    {
        precioSalida *= 0.9;
        precioSalida *= 1.03;
    }

    if (calidad)
    {
        precioSalida *= 1.3;
    }

    return precioSalida;
}


Camisas::~Camisas()
{

}