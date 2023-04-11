#pragma once
#include "Dependencias.h"


class Prendas
{
protected:
	bool calidad;
	int cantidadStock;
	float precioUnitario;
	float precioSalida;
public:
	Prendas();
	virtual ~Prendas();
	bool devolverCalidad();
	int devolverStock();
	float devolverPrecio();
	virtual void actualizarPrecio();
	void setPrecio(float valor);
	void setCalidad(bool z);
	void setUnidades(int cantidad);

};