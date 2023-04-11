#pragma once
#include "Prendas.h"
#include "Cotizaciones.h"

class Pantalones : public Prendas
{
private:
	bool chupines;
public:
	Pantalones();
	float actualizarPrecio(bool chupines, bool calidad, float precioUnitario);
	bool getChupines();
	void setChupines(bool x);
	
	~Pantalones();
};