#pragma once
#include "IVista.h"
#include<iostream>
#include<string>
#include "Presentador.h"

class Vista : public IVista
{
private:
	Presentador* p_presentador;
	std::string s_nombreTienda;
	std::string s_direccionTienda;
	std::string s_nombreVendedor;
	std::string s_apellidoVendedor;
	int n_codigoVendedor;
	char select;
	float precioUnit;
	int cantidadUni;
public:
	Vista();
	~Vista();
	void menuPrincipal() override;
	void separador() override;
	void nombreTienda() override;
	void direccionTienda() override;
	void nombreVendedor() override;
	void codigoVendedor() override;
	void solicitudPrenda();
	void cargaDatos();
	void salir();
	void refresh();
	
	void camiNext1();
	void pantNext();

	void camiNext2();

	void calidadPrenda();

	void cantidadUnidades();

	void ingresarPrecio();

	void consistencia();

	void cotizacionEfectuada();

	void historial();

    void testeoDatoint(int& variable, const std::string& mensaje);
	void testeoDatofloat(float& variable, const std::string& mensaje);
	void testeoDatochar(char& variable, const std::string& mensaje);
};