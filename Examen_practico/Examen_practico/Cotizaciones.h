#pragma once
#include "Dependencias.h"
#include "Vendedor.h"
#include "Tienda.h"
#include <ctime>
#include "Prendas.h"

class Vendedor;
class Tienda;

class Cotizaciones {
private:
	
	// Datos
	std::string fechaYhora;
	std::string prendaCotizada;
	// Para almacenar al codigo del vendedor
	int codVendedor;
	// numero de identificacion de la cotizacion
	static int nextnumIdentificacion;
	int numIdentificacion;
	// Modificables
	int cantidadUniCoti;
	float precioUnitario;
	// Para calcular
	float resultado;
	// Para acceder a la tienda y sus prendas
public:
	Cotizaciones(int cantidadUniCoti, int codVendedor, std::string fechaYhora, std::string prendaCotizada
	,float precioUnitario, float resultado);
	~Cotizaciones();

	int devolverId();
	int devolverCodVend();
	int devolverCantidadUniCoti();
	
	float devolverResultado();
	float devolverPrecioUnitario();

	std::string tomarFechaHora();
	std::string devolverPrenda();
	std::string devolverFechaHora();
	
};

