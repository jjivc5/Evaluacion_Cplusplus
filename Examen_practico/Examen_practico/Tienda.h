#pragma once
#include "Dependencias.h"
#include<vector>
#include "Prendas.h"
#include "Camisas.h"
#include "Pantalones.h"
#include<map>


class Tienda
{
private:
	std::string nombreTienda;
	std::string direccion;
	std::map<std::string, int> stock;
public:
	std::vector<Prendas*> vecPrendas;
	Tienda(std::string nombreTienda, std::string direccion);
	void crearCamisa();
	void crearPantalon();
	std::string nombreReturn();
	std::string direccionReturn();
	Prendas* obtenerPrenda(int indice);
	int cantidadPrendas() const;
	int obtenerStockCamisa(bool Manga, bool Cuello, bool Calidad);
	int obtenerStockPantalon(bool Chupin, bool Calidad);

	void restarStockPantalon(bool Chupin, bool Calidad, int stockRetirado);
	void restarStockCamisa(bool Manga, bool Cuello, bool Calidad, int stockRetirado);
	~Tienda();
};
