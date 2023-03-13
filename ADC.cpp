/**********************************************************************
	Nombre del archivo:    ADC.cpp
	Escuela:			   TecNM campus Chihuahua.
	Descripcion:           Implementación de métodos de la clase ADC
	Autor:      	       Mario De Jesus Castro Vazquez
************************************************************************/
#include "ADC.hpp"
#include <iostream>
#include <cmath>

using namespace std;

//Inicializacion de variables estaticas de la clase ADC
unsigned int ADC::rs = 0;
float ADC::hz = 0;

//Implementación de los métodos de la clase ADC
void ADC::resolucion(int _rs)
{
	rs = _rs;
}

void ADC::frecuencia(float _hz)
{
	hz = _hz;
}

void ADC::captura(float _v)
{
	v = _v;
}

float ADC:: getf ()
{
	return hz;
}

unsigned int ADC::conversion()
{	
	o = (v*pow(2,rs)-1)/3.3; 	//Conversion del ADC
	return o;
}

void ADC::setname (short _name)
{
	name = _name;
} 

short ADC::getname()
{
	return name;
}
