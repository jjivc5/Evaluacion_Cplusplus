#pragma once
#include"Dependencias.h"
#include<vector>
#include "Cotizaciones.h"


class Cotizaciones;


class Vendedor

{
private:
	std::string nombre;
	std::string apellido;
	int codigoVendedor;
	std::vector<Cotizaciones> vecCotis;
public:
	Vendedor(std::string nombre, std::string apellido, int codigoVendedor);
	~Vendedor();
	void agregarCotizacion(Cotizaciones* cotiPunt);
	int devolverCodVen();
	void historialCotizaciones();
	std::string darNombre();
	std::string darApellido();
};