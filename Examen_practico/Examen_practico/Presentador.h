#pragma once
#include "IVista.h"
#include "Vendedor.h"
#include "Tienda.h"
#include "Cotizaciones.h";

class Presentador
{
private:
	Vendedor* p_vendedor = nullptr;
	IVista* p_ivista = nullptr;
	Tienda* p_tienda = nullptr;
	Camisas* p_camisa = nullptr;
	Pantalones* p_pantalon = nullptr;
	Cotizaciones* p_cotizaciones = nullptr;
	
public:
	
	Presentador(IVista* ivista);
	~Presentador();
	std::string devolverNombreTienda();
	std::string devolverNombreVendedor();
	std::string devolverDireccion();
	std::string devolverApellido();
	int devolverCodigoVendedor();
	void setearTienda(std::string s_nombreTienda, std::string s_direccionTienda);
	void setearVendedor(std::string s_nombreVendedor, std::string s_apellidoVendedor, int n_codigoVendedor);
	float calculoCotizacion();
	int setearCotizacion();

	void setearPrenda(char x);
	void setearManga(char y);
	void setearCuello(char w);
	void setearChupin(char q);
	void setearCalidad(char z);
	void setearPrecio(float precio);
	void setearUnidades(int unidades);
	void accesoVector();

	void eliminarMemoria();

	int verificarStock();
	
	std::string devolverPrenda();
	float devolverPrecioUnitario();

	int devolverCantidadUnidades();

	void actualizarStock();

	std::string crearFechaHora();
	/*float calculoCotizacion();*/
};