#include "Presentador.h"

Presentador::Presentador(IVista* ivista) : p_ivista(ivista)
{
}



void Presentador::setearPrenda(char x)
{
	if (x == '1')
	{
		this->p_tienda->crearCamisa();
		this->p_camisa = dynamic_cast<Camisas*>(p_tienda->obtenerPrenda(p_tienda->cantidadPrendas() - 1));
	}
	else
	{
		if (x == '2')
		{
			this->p_tienda->crearPantalon();
			this->p_pantalon = dynamic_cast<Pantalones*>(p_tienda->obtenerPrenda(p_tienda->cantidadPrendas() - 1));
		}
	}
}

void Presentador::setearManga(char y)
{
	if (y == '1')
	{
		p_camisa->setMangaLarga(true);
	}
	else
	{
		if (y == '2')
		{
			p_camisa->setMangaLarga(false);
		}
	}
}
void Presentador::setearCuello(char w)
{
	if (w == '1')
	{
		p_camisa->setCuello(true);
	}
	else
	{
		if (w == '2')
		{
			p_camisa->setCuello(false);
		}
	}
}

void Presentador::setearChupin(char q)
{

	if (q == '1')
	{
		this->p_pantalon->setChupines(true);
	}
	else
	{
		if (q == '2')
		{
			this->p_pantalon->setChupines(false);
		}
	}
}
void Presentador::setearCalidad(char z)
{
	if (z == '1')
	{
		if (p_pantalon == nullptr)
		{
			p_camisa->setCalidad(true);
		}
		else
		{
			p_pantalon->setCalidad(true);
		}
		
	}
	else
	{
		if (z == '2')
		{
			if (p_pantalon == nullptr)
			{
				p_camisa->setCalidad(false);
			}
			else
			{
				p_pantalon->setCalidad(false);
			}
		}
	}
}

void Presentador::setearPrecio(float valor)
{
	if (p_pantalon == nullptr)
	{
		p_camisa->setPrecio(valor);
	}
	else
	{
		p_pantalon->setPrecio(valor);
	}
}

int Presentador::verificarStock()
{
	if (p_pantalon == nullptr)
	{
		int stockdevuelto = p_tienda->obtenerStockCamisa(this->p_camisa->getMangaLarga(),
			this->p_camisa->getCuelloMao(),this->p_camisa->devolverCalidad());
		return stockdevuelto;
	}
	else
	{
		int stockdevuelto = p_tienda->obtenerStockPantalon(this->p_pantalon->getChupines()
			,this->p_pantalon->devolverCalidad());

		return stockdevuelto;
	}
}

void Presentador::actualizarStock()
{
	if (p_pantalon == nullptr)
	{
		this->p_tienda->restarStockCamisa(this->p_camisa->getMangaLarga(),
			this->p_camisa->getCuelloMao(), this->p_camisa->devolverCalidad(), devolverCantidadUnidades());
	}
	else
	{
		this->p_tienda->restarStockPantalon(this->p_pantalon->getChupines()
			, this->p_pantalon->devolverCalidad(),devolverCantidadUnidades());
	}
}
void Presentador::setearUnidades(int unidades)
{
	if (p_pantalon == nullptr)
	{
		p_camisa->setUnidades(unidades);
	}
	else
	{
		p_pantalon->setUnidades(unidades);
	}
}


float Presentador::calculoCotizacion()
{
	if (p_pantalon == nullptr)
	{
		float precioAct = p_camisa->actualizarPrecio(p_camisa->getMangaLarga(), 
			p_camisa->getCuelloMao(), p_camisa->devolverCalidad(), p_camisa->devolverPrecio());

		return precioAct * p_camisa->devolverStock();
	}
	else
	{
		float precioAct = p_pantalon->actualizarPrecio(p_pantalon->getChupines(),
			p_pantalon->devolverCalidad(), p_pantalon->devolverPrecio());

		return precioAct * p_pantalon->devolverStock();
	}
}



float Presentador::devolverPrecioUnitario()
{
	
	if (p_pantalon == nullptr)
	{
		return p_camisa->devolverPrecio();
	}
	else
	{
		return p_pantalon->devolverPrecio();
	}
}


int Presentador::devolverCantidadUnidades()
{
	if (p_pantalon == nullptr)
	{
		return p_camisa->devolverStock();
	}
	else
	{
		return p_pantalon->devolverStock();
	}
}

std::string Presentador::devolverPrenda()
{
	std::string s_Prenda;
	std::string calidad;

	if (p_pantalon == nullptr)
	{
		
		if (p_camisa->devolverCalidad())
		{
			calidad = " Premium ";
		}
		else
		{
			calidad = " Standart ";
		}

		s_Prenda = " Camisa - ";

		std::string s_manga;
		std::string s_cuello;

		if (p_camisa->getMangaLarga())
		{
			s_manga = "Manga Larga -";
		}
		else
		{
			s_manga = " Manga Corta - ";
		}

		if (p_camisa->getCuelloMao())
		{
			s_cuello = " Cuello Mau -";
		}
		else
		{
			s_cuello = " Cuello Normal - ";
		}

		return s_Prenda + s_manga + s_cuello + calidad;

	}
	else
	{
		if (p_pantalon->devolverCalidad())
		{
			calidad = " Premium ";
		}
		else
		{
			calidad = " Standart ";
		}

		s_Prenda = " Pantalon - ";

		std::string s_chupin;

		if (p_pantalon->getChupines())
		{
			s_chupin = " Con Chupin - ";
		}
		else
		{
			s_chupin = " Normal ";
		}

		return s_Prenda + s_chupin + calidad;
	}
}

int Presentador::setearCotizacion()
{	
	this->p_cotizaciones = new Cotizaciones(devolverCantidadUnidades(),devolverCodigoVendedor(),crearFechaHora()
		,devolverPrenda(),devolverPrecioUnitario(),calculoCotizacion());
	
	this->p_vendedor->agregarCotizacion(this->p_cotizaciones);

	return p_cotizaciones->devolverId();
}

void Presentador::eliminarMemoria()
{
	if (p_pantalon != nullptr)
	{
		p_pantalon = nullptr;
	}
	else
	{
		p_camisa = nullptr;
		
	}
}
void Presentador::accesoVector()
{
	p_vendedor->historialCotizaciones();
}

std::string Presentador::crearFechaHora()
{
	return p_cotizaciones->tomarFechaHora();
}
void Presentador::setearTienda(std::string s_nombreTienda, std::string s_direccionTienda)
{
	this->p_tienda = new Tienda(s_nombreTienda, s_direccionTienda);
}


void Presentador::setearVendedor(std::string s_nombreVendedor, std::string s_apellidoVendedor, int n_codigoVendedor)
{
	this->p_vendedor = new Vendedor(s_nombreVendedor, s_apellidoVendedor, n_codigoVendedor);
}

std::string Presentador::devolverNombreTienda()
{
	if (p_tienda!= nullptr)
	{ 
		return p_tienda->nombreReturn();
	}
}

std::string Presentador::devolverDireccion()
{
	if (p_tienda != nullptr)
	{
		return p_tienda->direccionReturn();
	}
}

std::string Presentador::devolverNombreVendedor()
{
	if (p_vendedor != nullptr)
	{
		return p_vendedor->darNombre();
	}
}


std::string Presentador::devolverApellido()
{
	if (p_vendedor != nullptr)
	{
		return p_vendedor->darApellido();
	}
}

int Presentador::devolverCodigoVendedor()
{
	if (p_vendedor != nullptr)
	{
		return p_vendedor->devolverCodVen();
	}
}
Presentador::~Presentador()
{
	delete p_vendedor;
	delete p_tienda;
	delete p_cotizaciones;
	delete p_camisa;
	delete p_pantalon;
}