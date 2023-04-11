#include "Vista.h"
#include <cstdlib>

Vista::Vista()
{
	p_presentador = new Presentador(this);
}

Vista::~Vista()
{
	delete p_presentador;
}

void Vista::menuPrincipal()
{
	separador();
	std::cout << "COTIZADOR EXPRESS >>> MENU PRINCIPAL\n";
	nombreTienda();
	std::cout << " | ";
	direccionTienda();
	std::cout << "\n";
	nombreVendedor();
	std::cout << " | ";
	codigoVendedor();
	separador();


	do {

		std::cout << "\n\n";
		std::cout << "SELECCION UNA OPCION DEL MENU\n";
		std::cout << "1) Historial de Cotizaciones\n";
		std::cout << "2) Realizar Cotizacion\n";
		std::cout << "3) Salir\n";
		testeoDatochar(select, " ingrese unicamente un caracter numerico o el apropiado ");

	} while (select != '1' && select != '2' && select != '3');


	switch (select)
	{
	case '1' :
		separador();
		historial();
		break;
	case '2' :
		solicitudPrenda();
		break;
	case '3':
		salir();
		break;
	}

	
}

void Vista::historial()
{
	
	refresh();
	do{
	separador();
	std::cout << "COTIZADOR EXPRESS >>> HISTORIAL\n";
	separador();
	std::cout << "Presionar 3 / Para Regresar al Menu Principal";
	separador();
	p_presentador->accesoVector();
	separador();
	separador();
	std::cout << "Presionar 3 / Para Regresar al Menu Principal";
	separador();
	testeoDatochar(select, " ingrese unicamente un caracter numerico o el apropiado ");
	} while (select != '3');
	refresh();
	menuPrincipal();
}

void Vista::cargaDatos()
{
	separador();
	std::cout << "Por favor ingrese los siguientes datos para iniciar\n";
	separador();
	std::cout << "Ingrese el nombre de su tienda\n";
    std::getline(std::cin, s_nombreTienda);
	std::cout << "Ingrese la direccion de su tienda\n";
	std::getline(std::cin, s_direccionTienda);
	std::cout << "Ingrese su nombre, vendedor\n";
	std::getline(std::cin, s_nombreVendedor);
	std::cout << "Ingrese su apellido, vendedor\n";
	std::getline(std::cin, s_apellidoVendedor);
	std::cout << "Ingrese su codigo, vendedor\n";
	testeoDatoint(n_codigoVendedor," Debe ser un valor de tipo entero ");
	

	

	p_presentador->setearTienda(s_nombreTienda,s_direccionTienda);
	p_presentador->setearVendedor(s_nombreVendedor, s_apellidoVendedor, n_codigoVendedor);
	refresh();
	menuPrincipal();
}	

void Vista::solicitudPrenda()
{
	refresh();
	

	do 
	{
		separador();
		std::cout << "COTIZADOR EXPRESS >>> COTIZAR\n";
		separador();
		std::cout << "Presionar 3 / Para Regresar al Menu Principal";
		separador();
		std::cout << "PASO 1 Seleccionar prenda a cotizar";
		separador();
		std::cout << "1) Camisa\n";
		std::cout << "2) Pantalon\n";
		testeoDatochar(select, " ingrese unicamente un caracter numerico o el apropiado");

	} while (select != '1' && select != '2' && select != '3');
	
	switch (select)
	{
	case '1':
		refresh();
		camiNext1();
		break;
	case '2':
		refresh();
		pantNext();
		break;
	case '3':
		refresh();
		menuPrincipal();
		break;
	}
}

void Vista::camiNext1()
{
	p_presentador->setearPrenda(select);

	refresh();
	

	do
	{
		separador();
		std::cout << "COTIZADOR EXPRESS >>> COTIZAR\n";
		separador();
		std::cout << "Presionar 3 / Para Regresar al Menu Principal";
		separador();
		std::cout << "PASO 2.a: La camisa a cotizar, es manga larga?";
		separador();
		std::cout << "1) Si\n";
		std::cout << "2) No \n";
		testeoDatochar(select, " ingrese unicamente un caracter numerico o el apropiado");

	} while (select != '1' && select != '2' && select != '3');

	switch (select)
	{
	case '1':
		refresh();
		camiNext2();
		break;
	case '2':
		refresh();
		camiNext2();
		break;
	case '3':
		refresh();
		menuPrincipal();
		break;
	}
}

void Vista::camiNext2()
{
	p_presentador->setearManga(select);

	refresh();
	

	do
	{
		separador();
		std::cout << "COTIZADOR EXPRESS >>> COTIZAR\n";
		separador();
		std::cout << "Presionar 3 / Para Regresar al Menu Principal";
		separador();
		std::cout << "PASO 2.a: La camisa a cotizar, tiene cuello mau?";
		separador();
		std::cout << "1) Si\n";
		std::cout << "2) No \n";
		testeoDatochar(select, " ingrese unicamente un caracter numerico o el apropiado ");

	} while (select != '1' && select != '2' && select != '3');

	switch (select)
	{
	case '1':
		refresh();
		p_presentador->setearCuello(select);
		calidadPrenda();
		break;
	case '2':
		refresh();
		p_presentador->setearCuello(select);
		calidadPrenda();
		break;
	case '3':
		refresh();
		menuPrincipal();
		break;
	}

}

void Vista::pantNext()
{
	p_presentador->setearPrenda(select);

	refresh();


	do
	{
		separador();
		std::cout << "COTIZADOR EXPRESS >>> COTIZAR\n";
		separador();
		std::cout << "Presionar 3 / Para Regresar al Menu Principal";
		separador();
		std::cout << "PASO 2: El pantalon, es de tipo Chupin?";
		separador();
		std::cout << "1) Si\n";
		std::cout << "2) No \n";
		testeoDatochar(select, " ingrese unicamente un caracter numerico o el apropiado");

	} while (select != '1' && select != '2' && select != '3');

	switch (select)
	{
	case '1':
		refresh();
		p_presentador->setearChupin(select);
		calidadPrenda();
		break;
	case '2':
		refresh();
		p_presentador->setearChupin(select);
		calidadPrenda();
		break;
	case '3':
		refresh();
		menuPrincipal();
		break;
	}


}

void Vista::calidadPrenda()
{
	refresh();
	

	do
	{
		separador();
		std::cout << "COTIZADOR EXPRESS >>> COTIZAR\n";
		separador();
		std::cout << "Presionar 3 / Para Regresar al Menu Principal";
		separador();
		std::cout << "PASO 3 : Seleccione la calidad de la prenda";
		separador();
		std::cout << "1) Premium\n";
		std::cout << "2) Standart\n";
		testeoDatochar(select, " ingrese unicamente un caracter numerico o el apropiado");

	} while (select != '1' && select != '2' && select != '3');

	switch (select)
	{
	case '1':
		refresh();
		p_presentador->setearCalidad(select);
		ingresarPrecio();
		break;
	case '2':
		refresh();
		p_presentador->setearCalidad(select);
		ingresarPrecio();
		break;
	case '3':
		refresh();
		menuPrincipal();
		break;
	}

	
}


void Vista::ingresarPrecio()
{
	refresh();
	
	do 
	{
		separador();
		std::cout << "COTIZADOR EXPRESS >>> COTIZAR\n";
		separador();
		std::cout << "Presionar 3 / Para Regresar al Menu Principal";
		separador();

		std::cout << "PASO 4 : Ingresar Precio Unitario de la prenda {por ej 10.5, 99.9} debe ser mayor a 0";
		separador();
		testeoDatofloat(precioUnit, "I ngrese un tipo de precio apropiado, en el formato indicado : ");

	} while (precioUnit <= 0);
	if (precioUnit == 3)
	{
		consistencia();
	}
	p_presentador->setearPrecio(precioUnit);
	cantidadUnidades();
}

void Vista::cantidadUnidades()
{
	refresh();

	do {
		
		separador();
		std::cout << "COTIZADOR EXPRESS >>> COTIZAR\n";
		separador();
		std::cout << "Presionar 3 / Para Regresar al Menu Principal";
		separador();

		std::cout << "Existen "; std::cout << p_presentador->verificarStock(); std::cout << " unidades en stock \n";
		separador();
		std::cout << "PASO 5 : Ingresar la Cantidad de Unidades {1,2..100} \n ";
		separador();
		std::cout << " Recuerde que no puede ser 0 o inferior \n\n Tampoco superar el stock actual ";
		separador();
		testeoDatoint(cantidadUni, " Ingrese el dato de forma apropiada como se indica : ");

		if (cantidadUni > p_presentador->verificarStock())
		{
			refresh();
			separador();
			std::cout << " La cantidad solicitada supera el stock ";
			separador();
		}

		if (cantidadUni <= 0)
		{
			refresh();
			separador();
			std::cout << " La cantidad solicitada es inferior o igual a 0 !!!!!";
			separador();
		}

	} while (cantidadUni <= 0 || cantidadUni > p_presentador->verificarStock());

	if (cantidadUni == 3)
	{
		consistencia();
	}

	p_presentador->setearUnidades(cantidadUni);
	p_presentador->actualizarStock();
	cotizacionEfectuada();
}

void Vista::cotizacionEfectuada()
{

	do{
	refresh();
	separador();
	std::cout << "COTIZADOR EXPRESS >>> COTIZAR\n";
	separador();
	std::cout << "Presionar 3 / Para Regresar al Menu Principal";
	separador();

	std::cout << "Numero de Identificacion "; std::cout << p_presentador->setearCotizacion(); std::cout << "\n";
	std::cout << "Fecha y Hora de la Cotizacion : " ; std::cout << p_presentador->crearFechaHora(); std::cout << "\n";
	std::cout << "Codigo del vendedor:  "; codigoVendedor(); std::cout << "\n";
	std::cout << "Prenda Cotizada:  "; std::cout << p_presentador->devolverPrenda();  std::cout << "\n";
	std::cout << "Precio Unitario:  ", std::cout << p_presentador->devolverPrecioUnitario(); std::cout << "\n";
	std::cout << "Cantidad de Unidades Cotizadas:  "; std::cout << p_presentador->devolverCantidadUnidades(); std::cout << "\n";
	std::cout << "Precio final :  "; std:: cout << p_presentador->calculoCotizacion(); std::cout << "\n";
	separador();
	std::cout << "Presionar 3 / Para Regresar al Menu Principal";
	separador();
	testeoDatochar(select, " ingrese unicamente un caracter numerico o el apropiado");
	} while (select != '3');

	refresh();
	p_presentador->eliminarMemoria();
	menuPrincipal();
}	
void Vista::salir()
{
	refresh();
	separador();
	std::cout << "Gracias por usar el cotizador de precios ";
	separador();

}

void Vista::consistencia()
{
	refresh();
	do {
		separador();
		std::cout << "Desea volver al Menu Principal o Asignar el Valor 3\n";
		std::cout << " 1 (Retorno al Menu Principal) / 2 (Asigno el valor 3)\n";
		testeoDatochar(select, " ingrese unicamente un caracter numerico o el apropiado");
	} while (select != '1' && select != '2');

	if (select == '1')
	{
		refresh();
		menuPrincipal();
	}
}
void Vista::separador()
{
	std::cout << "\n===============================================\n";
}

void Vista::nombreTienda()
{
	std::cout << p_presentador->devolverNombreTienda();
}

void Vista::direccionTienda()
{
	std::cout << p_presentador->devolverDireccion();
}

void Vista::nombreVendedor()
{
	std::cout << p_presentador->devolverNombreVendedor() << " " << p_presentador->devolverApellido();
}

void Vista::codigoVendedor()
{
	std::cout << p_presentador->devolverCodigoVendedor();
}

void Vista::refresh()
{
	system("cls");
	system("color 0F");
}


void Vista::testeoDatoint(int& variable, const std::string& mensaje) {
	while (true) {
		if (std::cin >> variable) {
			// El valor ingresado es del tipo de dato correcto, se puede continuar con el programa
			break;
		}
		else {
			// El valor ingresado no es del tipo de dato correcto, se debe limpiar el buffer de entrada
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error: El valor ingresado no es del tipo de dato correcto. Intente nuevamente.\n" << mensaje;
		}
	}
}

void Vista::testeoDatofloat(float& variable, const std::string& mensaje) {
	while (true) {
		if (std::cin >> variable) {
			// El valor ingresado es del tipo de dato correcto, se puede continuar con el programa
			break;
		}
		else {
			// El valor ingresado no es del tipo de dato correcto, se debe limpiar el buffer de entrada
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error: El valor ingresado no es del tipo de dato correcto. Intente nuevamente.\n" << mensaje;
		}
	}
}


void Vista::testeoDatochar(char& variable, const std::string& mensaje) {
	while (true) {
		if (std::cin >> variable) {
			// El valor ingresado es del tipo de dato correcto, se puede continuar con el programa
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			refresh();
			separador();
			std::cout << mensaje;
			separador();
			break;
		}	
	}
}