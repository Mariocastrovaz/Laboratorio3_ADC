/**********************************************************************
	Nombre del archivo:    main.cpp
	Escuela:			   TecNM campus Chihuahua.
	Descripcion:           Simulación de la configuración de un ADC.
	Autor:      	       Mario De Jesus Castro Vazquez
************************************************************************/

#include <iostream>
#include <stdlib.h>
#include "ADC.hpp"

using namespace std;

short i,cantidad,bits,n_canal;
float frec;
float volt;

int main()
{
	cout<<"Ingrese el numero de canales a utilizar: "<<endl;
	cin>>cantidad;
	
	do					//Validacion de datos
	{
		cout<<"Ingrese la resolucion deseada en bits (8,10,12)"<<endl;
		cin>>bits;
		fflush(stdin);
		
		if(!(bits == 8||bits == 10||bits == 12))
			cout<<"Resolucion no permitida"<<endl;	
		
	}while(!(bits == 8||bits == 10||bits == 12));

	ADC::resolucion(bits);
	cout<<"Ingrese la frecuencia de muestreo (MHz)"<<endl;
	cin>>frec;
	ADC::resolucion(bits);
	ADC::frecuencia(frec);
	ADC canales [cantidad];		//Creacion de objetos segun los canales a usar
	

	for(i=0;i<cantidad;i++)
	{
		do 
		{
			cout<<"Ingrese que canal deseas usar (1-32)"<<endl;
			cin>>n_canal;
			canales[i].setname(n_canal);
			
			if(n_canal>32||n_canal == 0)
				cout<<"No existe canal"<<endl;
				
		}while(n_canal>32||n_canal == 0);
	}

	for(i=0;i<cantidad;i++)
	{
		cout<<"Ingrese el valor a medir del canal: "<<i+1<<endl;
		fflush(stdin);
		
		do					//Validacion de datos
		{
			cin>>volt;	//Lectura del voltaje de cada canal
			 
			if(volt>3.3)
				cout<<"El Voltaje es mayor a 3.3"<<endl;
			
		}while(volt>3.3);
		
		canales[i].captura(volt);
	}
	
	for(i=0;i<cantidad;i++)		//Ciclo for para la impresion de datos
	{
		cout<<"El valor digital del canal AN"<<canales[i].getname();
		cout<<",con frecuencia de muestreo de "<<ADC::getf();
		cout<<" MHz";
		cout<<": "<<canales[i].conversion()<<endl;
	}
	return 0;
}
