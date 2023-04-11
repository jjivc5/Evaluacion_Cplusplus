#pragma once
#include "Prendas.h"

class Camisas : public Prendas 
{
private:
	bool mangaLarga;
	bool cuelloMao;
	
public:
	Camisas();

	bool getMangaLarga();
	bool getCuelloMao();
	
	float actualizarPrecio(bool mangaLarga, bool cuelloMao, bool calidad, float precioUnitario);

	void setMangaLarga(bool x);
	void setCuello(bool y);
	
	~Camisas();
	


};