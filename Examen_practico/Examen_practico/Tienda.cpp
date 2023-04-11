#include "Tienda.h"

Tienda::Tienda(std::string nombreTienda, std::string direccion)
{
	this->nombreTienda = nombreTienda;
	this->direccion = direccion;
	vecPrendas = std::vector<Prendas*>();
	stock["s_cam_Nman_c_prem"] = 100;
	stock["s_cam_Nman_c_stan"] = 100;
	stock["s_cam_Nman_Nc_prem"] = 150;
	stock["s_cam_Nman_Nc_stan"] = 150;
	stock["s_cam_man_c_prem"] = 75;
	stock["s_cam_man_c_stan"] = 75;
	stock["s_cam_man_Nc_prem"] = 175;
	stock["s_cam_man_Nc_stan"] = 175;
	stock["s_pan_chup_prem"] = 750;
	stock["s_pan_chup_stan"] = 750;
	stock["s_pan_Nchup_prem"] = 250;
	stock["s_pan_Nchup_stan"] = 250;
}

Prendas* Tienda::obtenerPrenda(int indice)
{
	if (indice < vecPrendas.size())
	{
		return vecPrendas[indice];
	}
	else
	{
		return nullptr;
	}
}

int Tienda::obtenerStockCamisa(bool Manga, bool Cuello, bool Calidad)
{
	if (!Manga) // Manga corta
	{
		if (Cuello) // Cuello Mau
		{
			if (Calidad) // Premium
			{
				return stock["s_cam_Nman_c_prem"];
			}
			else // Standart
			{
				return stock["s_cam_Nman_c_stan"];
			}
		}
		else // Cuello Comun
		{
			if (Calidad) // Premium
			{
				return stock["s_cam_Nman_Nc_prem"];
			}

			else // Standart

			{
				return stock["s_cam_Nman_Nc_stan"];
			}
		}
	}
	else // Manga Larga
	{
		if (Cuello) // Cuello Mau
		{
			if (Calidad) // Premium
			{
				return stock["s_cam_man_c_prem"];
			}
			else // Standart
			{
				return stock["s_cam_man_c_stan"];
			}
		}
		else // Cuello Comun
		{
			if (Calidad) // Premium
			{
				return stock["s_cam_man_Nc_prem"];
			}
			else // Standart
			{
				return stock["s_cam_man_Nc_stan"];
			}
		}
	}
}

int Tienda::obtenerStockPantalon(bool Chupin, bool Calidad)
{
	if (Chupin) // Chupin
	{
		if (Calidad) // Premium
		{
			return stock["s_pan_chup_prem"];
		}

		else // Standart

		{
			return stock["s_pan_chup_stan"];
		}
	}
	else // Normal
	{
		if (Calidad) // Premium
		{
			return stock["s_pan_Nchup_prem"];
		}
		else // Standart
		{
			return stock["s_pan_Nchup_stan"];
		}
	}
}
void Tienda::restarStockCamisa(bool Manga, bool Cuello, bool Calidad, int stockRetirado)
{
	if (!Manga) // Manga corta
	{
		if (Cuello) // Cuello Mau
		{
			if (Calidad) // Premium
			{
				stock["s_cam_Nman_c_prem"] = stock["s_cam_Nman_c_prem"] - stockRetirado;
			}
			else // Standart
			{
				stock["s_cam_Nman_c_stan"] = stock["s_cam_Nman_c_stan"] - stockRetirado;
			}
		}
		else // Cuello Comun
		{
			if (Calidad) // Premium
			{
				stock["s_cam_Nman_Nc_prem"] = stock["s_cam_Nman_Nc_prem"] - stockRetirado;
			}

			else // Standart

			{
				stock["s_cam_Nman_Nc_stan"] = stock["s_cam_Nman_Nc_stan"] - stockRetirado;
			}
		}
	}
	else // Manga Larga
	{
		if (Cuello) // Cuello Mau
		{
			if (Calidad) // Premium
			{
				stock["s_cam_man_c_prem"] = stock["s_cam_man_c_prem"] - stockRetirado;
			}
			else // Standart
			{
				stock["s_cam_man_c_stan"] = stock["s_cam_man_c_stan"] - stockRetirado;
			}
		}
		else // Cuello Comun
		{
			if (Calidad) // Premium
			{
				stock["s_cam_man_Nc_prem"] = stock["s_cam_man_Nc_prem"] - stockRetirado;
			}
			else // Standart
			{
				stock["s_cam_man_Nc_stan"] = stock["s_cam_man_Nc_stan"] - stockRetirado;
			}
		}
	}
}
void Tienda::restarStockPantalon(bool Chupin, bool Calidad,int stockRetirado)
{
	if (Chupin) // Chupin
	{
		if (Calidad) // Premium
		{
			stock["s_pan_chup_prem"] = stock["s_pan_chup_prem"] - stockRetirado;
		}

		else // Standart

		{
			stock["s_pan_chup_stan"] = stock["s_pan_chup_stan"] - stockRetirado;
		}
	}
	else // Normal
	{
		if (Calidad) // Premium
		{

			stock["s_pan_Nchup_prem"] = stock["s_pan_Nchup_prem"] - stockRetirado;
		}
		else // Standart
		{
			stock["s_pan_Nchup_stan"] = stock["s_pan_Nchup_stan"] - stockRetirado;
		}
	}
}
int Tienda::cantidadPrendas() const
{
	return vecPrendas.size();
}



std::string Tienda::nombreReturn()
{
	return nombreTienda;
}

std::string Tienda::direccionReturn()
{
	return direccion;
}

void Tienda::crearCamisa()
{
	Prendas* prendaCotizada = new Camisas();
	vecPrendas.push_back(prendaCotizada);
}
void Tienda::crearPantalon()
{
	Prendas* prendaCotizada = new Pantalones();
	vecPrendas.push_back(prendaCotizada);
}


Tienda::~Tienda()
{

}