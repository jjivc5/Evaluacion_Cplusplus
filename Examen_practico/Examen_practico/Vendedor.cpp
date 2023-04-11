#include "Vendedor.h"

Vendedor::Vendedor(std::string nombre, std::string apellido, int codigoVendedor) 
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->codigoVendedor = codigoVendedor;
	vecCotis = std::vector<Cotizaciones>();
}



void Vendedor::agregarCotizacion(Cotizaciones* cotiPunt)
{
	vecCotis.push_back(*cotiPunt);
}
std::string Vendedor::darNombre()
{
	return nombre;
}

std::string Vendedor::darApellido()
{
	return apellido;
}


int Vendedor::devolverCodVen()
{
	return codigoVendedor;
}
void Vendedor::historialCotizaciones()
{
	std::cout << "\nEl historia del vendedor: " << nombre << " " << apellido << " es : \n";
	for (int it = 0; it < vecCotis.size(); it++)
	{	
		std::cout << "\n===============================================\n";
		std::cout << "Numero de Identificacion "; std:: cout << vecCotis[it].devolverId(); std::cout << "\n";
		std::cout << "Fecha y Hora de la Cotizacion : "; std::cout << vecCotis[it].devolverFechaHora(); std::cout << "\n";
		std::cout << "Codigo del vendedor:  "; std::cout << vecCotis[it].devolverCodVend(); std::cout << "\n";
		std::cout << "Prenda Cotizada:  "; std::cout << vecCotis[it].devolverPrenda(); std::cout << "\n";
		std::cout << "Precio Unitario:  ", std::cout << vecCotis[it].devolverPrecioUnitario();  std::cout << "\n";
		std::cout << "Cantidad de Unidades Cotizadas:  ";  std::cout << vecCotis[it].devolverCantidadUniCoti(); std::cout << "\n";
		std::cout << "Precio final :  "; std::cout << vecCotis[it].devolverResultado();  std::cout << "\n";
		std::cout << "\n===============================================\n";
	}
}


Vendedor::~Vendedor()
{
	
}