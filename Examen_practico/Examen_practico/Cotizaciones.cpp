#include "Cotizaciones.h"

int Cotizaciones::nextnumIdentificacion = 0;

Cotizaciones::Cotizaciones(int cantidadUniCoti, int codVendedor, 
	std::string fechaYhora,std::string prendaCotizada, float precioUnitario, float resultado)
{
	this->numIdentificacion = ++nextnumIdentificacion;
	this->cantidadUniCoti = cantidadUniCoti;
	this->codVendedor = codVendedor;
	this->fechaYhora = fechaYhora;
	this->prendaCotizada = prendaCotizada;
	this->precioUnitario = precioUnitario;
	this->resultado = resultado;


}


int Cotizaciones::devolverId()
{
	return numIdentificacion;
}
int Cotizaciones::devolverCodVend()
{
	return codVendedor;
}

int Cotizaciones::devolverCantidadUniCoti()
{
	return cantidadUniCoti;
}

float Cotizaciones::devolverPrecioUnitario()
{
	return precioUnitario;
}

std::string Cotizaciones::devolverPrenda()
{
	return prendaCotizada;
}

std::string Cotizaciones::devolverFechaHora()
{
	return fechaYhora;
}

std::string Cotizaciones::tomarFechaHora()
{
	time_t tiempoActual = time(nullptr);
	tm tiempoLocal;

	// Utilizar localtime_s en lugar de localtime
	localtime_s(&tiempoLocal, &tiempoActual);

	char buffer[80];
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %I:%M:%S %p", &tiempoLocal);

	return std::string(buffer);
}


float Cotizaciones::devolverResultado()
{
	return resultado;
}



Cotizaciones::~Cotizaciones()
{
	
}
