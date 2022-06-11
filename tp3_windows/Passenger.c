#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "biblioteca.h"

static int esNumerica(char*, int);
static int esFlotante(char*);
static int esDescripcion(char*, int);
static int esNombre(char*, int);

static int esNumerica(char* cadena, int size)
{
	int retorno;
	retorno = -1;
	for(int i=0;i<size && cadena[i]!='\0';i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 1;
			break;
		}
	}
	return retorno;
}
static int esFlotante(char* cadena)
{
	int retorno = -1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(int i=0;cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}
static int esDescripcion(char* cadena,int size)
{
	int i=0;
	int retorno = -1;

	if(cadena != NULL && size > 0)
	{
		for(i=0;cadena[i]!='\0' && i<size;i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9'))
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
static int esNombre(char* cadena,int size)
{
	int retorno;
	retorno = -1;

	if(cadena != NULL && size > 0)
	{
		for(int i=0 ; cadena[i] != '\0' && i < size; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}


Passenger* Passenger_new()
{
	Passenger* auxP;
	auxP = NULL;
	auxP = (Passenger*) malloc(sizeof(Passenger)*10);
	return auxP;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr)
{
	Passenger* pauxP;
	pauxP = (Passenger*) malloc(sizeof(Passenger));
	pauxP = NULL;
	pauxP = Passenger_new();
	if(pauxP != NULL && pauxP != NULL)
	{
		Passenger_setId(pauxP, idStr);
		Passenger_setNombre(pauxP, nombreStr);
		Passenger_setTipoPasajero(pauxP, tipoPasajeroStr);
	}
		return NULL;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,char* id)
{
	int retorno;
	retorno = -1;
	if(this != NULL && id != NULL && esNumerica(id,1000)== 1)
	{
		this->id = atoi(id);
	}
	return retorno;
}

int Passenger_getId(Passenger* this,char* id)
{
	int retorno;
	retorno = -1;
	if(this != NULL && id != NULL)
	{
		sprintf(id,"%d",this->id);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;
	retorno = -1;
	if(this != NULL && nombre != NULL && esNombre(nombre, 50)== 1)
	{
		strncpy(this->nombre,nombre,50);
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;
	retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre,nombre,50);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;
	retorno = -1;
	if(this != NULL && apellido != NULL && esNombre(apellido, 50)== 1)
	{
		strncpy(this->apellido,apellido,50);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;
	retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		strncpy(this->apellido,apellido,50);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;
	retorno = -1;
	if(this != NULL && codigoVuelo != NULL && esNombre(codigoVuelo, 4)== 1)
	{
		strncpy(this->codigoVuelo,codigoVuelo, 4);
		retorno = 1;
	}
	return retorno;

}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;
	retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(this->codigoVuelo,codigoVuelo, 4);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this, char* tipoPasajero)
{
	int retorno;
	retorno = -1;
	if(this != NULL && tipoPasajero != NULL && esNumerica(tipoPasajero,20)== 1)
	{
		this->tipoPasajero = atoi(tipoPasajero);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno;
	retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		sprintf(tipoPasajero,"%d",this->tipoPasajero);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,char* precio)
{
	int retorno;
	retorno = -1;
	if(this != NULL && precio != NULL && esFlotante(precio)== 1)
	{
		this->precio = atof(precio);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,char* precio)
{
	int retorno;
	retorno = -1;
	if(this != NULL && precio != NULL)
	{
		sprintf(precio,"%f",this->precio);
		retorno = 1;
	}
	return retorno;
}



