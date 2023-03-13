/**********************************************************************
	Nombre del archivo:    ADC.hpp
	Escuela:			   TecNM campus Chihuahua.
	Descripcion:           Declaraci�n de clase para la creaci�n de objetos ADC.
	Autor:      	       Mario De Jesus Castro Vazquez
************************************************************************/
#pragma once
#include <iostream>

using namespace std;

class ADC
{
	private:
		static unsigned int rs;		//Resoluci�n 8,10 o 12v
		static  float hz;			//Frecuencia de muestreo
		float v;					//Voltaje a convertir 0-3.3v
		unsigned int o;				//Salida en bits seg�n resoluci�n
		short name;
	
	public:
		void Canal(){};					//Constructor por defecto
//------------------------------------------SETTERS------------------------------------------
		static void resolucion (int);
		static void frecuencia(float);
		void captura (float);
		void setname(short);
//------------------------------------------GETTERS------------------------------------------		
		static float getf();
		unsigned int conversion();
		short getname();
};
