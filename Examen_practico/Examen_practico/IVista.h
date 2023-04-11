#pragma once
#include<iostream>
class IVista
{

public:
	virtual ~IVista() = default;
	virtual void menuPrincipal() = 0;
	virtual void separador() = 0;
	virtual void nombreTienda() = 0;
	virtual void direccionTienda() = 0;
	virtual void nombreVendedor() = 0;
	virtual void codigoVendedor() = 0;
};