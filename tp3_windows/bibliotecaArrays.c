
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "Passenger.h"


static int getString(char*, int);
static int getInt(int*);
static int getFloat(float*);
static int getNombre(char*, int);
static int getDescripcion(char*, int);
static int getDni(char*, int);
static int esNumerica(char*, int);
static int esFlotante(char*);
static int esDescripcion(char*, int);
static int esNombre(char*, int);

int utn_GetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0){
		do
		{
		printf("%s",mensaje);
		if(getInt(&bufferInt) == 1 && bufferInt >= minimo && bufferInt <= maximo){
			*pResultado = bufferInt;
			retorno = 1;
			break;
		}else{
			printf("%s",mensajeError);
			reintentos --;
		}
		}while(reintentos >=0);
	}
	return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 1)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 1;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int utn_getNombre(char* pResultado, int size,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 1 && strnlen(bufferString,sizeof(bufferString)) < size)
		{
			strncpy(pResultado,bufferString,size);
			retorno = 1;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 1 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 1;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int utn_getDni(char* pResultado, int size,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDni(bufferString,sizeof(bufferString)) == 1 && strnlen(bufferString,sizeof(bufferString)) < size)
		{
			strncpy(pResultado,bufferString,size);
			retorno = 1;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

static int getString(char* cadena, int size)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && size > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= size)
			{
				strncpy(cadena,bufferString,size);
				retorno = 1;
			}
		}
	}
	return retorno;
}

static int getInt(int* pResultado)
{
	int retorno= -1;
	char bufferString[50];
	if(	pResultado != NULL && getString(bufferString,sizeof(bufferString)) == 1 && esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno = 1;
		*pResultado = atoi(bufferString);
	}
	    return retorno;
}

static int getFloat(float* pResultado)
{
    int retorno= -1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))== 1 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 1;
		}
    }
    return retorno;
}

static int getNombre(char* pResultado, int size)
{
    int retorno= -1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==1 && esNombre(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<size)
    	{
    		strncpy(pResultado,buffer,size);
			retorno = 1;
		}
    }
    return retorno;
}

static int getDescripcion(char* pResultado, int size)
{
    int retorno= -1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))== 1 && esDescripcion(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<size)
    	{
    		strncpy(pResultado,buffer,size);
			retorno = 1;
		}
    }
    return retorno;
}

static int getDni(char* pResultado, int size)
{
    int retorno= -1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))== 1 && esNumerica(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<size)
    	{
    		strncpy(pResultado,buffer,size);
			retorno = 1;
		}
    }
    return retorno;
}

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

int str_imprimir(Cliente* auxProducto, Pago* auxPago)
{
	int retorno;
	retorno = -1;
	if(auxProducto != NULL && auxProducto->estado == 1)
	{
		printf("%d\t%s\t%s\t%.2f\t%s\n",auxProducto->id,auxProducto->nombre,auxProducto->dni,auxProducto->altura,auxPago->tipoPago);
		retorno = 1;
	}

	return retorno;
}

int str_imprimirArray(Cliente* array, Pago* arrayP, int size)
{
	int retorno;
	retorno = -1;
	if(array != NULL && size > 0)
	{
		for(int i=0;i<size;i++)
		{
			str_imprimir(&array[i], &arrayP[i]);
		}
		retorno = 1;
	}

	return retorno;
}

int str_InicializarArray(Cliente* array, int size)
{
	int retorno;
		retorno = -1;
		if(array != NULL && size > 0)
		{
			for(int i=0;i<size;i++)
			{
				array[i].estado = 0;
			}
			retorno = 1;
		}

		return retorno;
}

int str_altaArray(Cliente* array, Pago* arrayP , int size, int indice, int* id)
{
	int retorno;
	Cliente bufferCliente;
	Pago bufferPago;
	retorno = -1;
	if(array != NULL && arrayP != NULL && size >= 0 && indice < size && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferCliente.nombre,50,"Ingrese nombre: \n","Error. Ingrese nombre valido...\n",3) == 1 &&
			utn_getDni(bufferCliente.dni,20,"Ingrese DNI: \n","Error, ingrese DNI valido...\n",3) ==1 &&
			utn_getNumeroFlotante(&bufferCliente.altura,"Ingrese altura: \n","Error, Ingrese altura valida", 1, 3, 3) == 1 &&
			utn_getDescripcion(bufferPago.tipoPago, 20, "Ingrese tipo de pago: [debito / credito / efectivo / tarjeta] \n",
														"Error, Elija un tipo de pago correcto.. [debito / credito / efectivo / tarjeta]", 3)== 1)

		{
			if(strncmp(bufferPago.tipoPago,"debito",20)== 0 ||
			   strncmp(bufferPago.tipoPago,"credito",20)== 0 ||
			   strncmp(bufferPago.tipoPago,"efectivo",20)== 0 ||
			   strncmp(bufferPago.tipoPago,"tarjeta",20)== 0)
			{
			bufferCliente.id = *id;
			bufferCliente.estado = 1;
			array[indice] = bufferCliente;
			arrayP[indice] = bufferPago;
			(*id)++;
			retorno = 1;
			}

		}
	}

	return retorno;
}

int str_altaForzada(Cliente* array, Pago* arrayP, int size, int indice, int* id, char* nombre, char* dni, float altura, char* tipo)
{
	Cliente bufferCliente;
	Pago bufferPago;
	int retorno;
	retorno = -1;

	if(array != NULL && arrayP != NULL && size > 0 && indice < size && indice >= 0 &&
	   id != NULL && nombre != NULL && dni != NULL && tipo != NULL)
	{
		strncpy(bufferCliente.nombre,nombre,50);
		strncpy(bufferCliente.dni,dni,20);
		strncpy(bufferPago.tipoPago,tipo,20);
		bufferCliente.altura = altura;
		bufferCliente.id = *id;
		bufferCliente.estado = 1;
		array[indice] = bufferCliente;
		arrayP[indice] = bufferPago;
		(*id)++;
		retorno = 1;
	}

	return retorno;
}

int str_modificarArray(Cliente* array, Pago* arrayP, int size, int indice)
{
	Cliente bufferArray;
	Pago bufferPago;
	int retorno;
	int opcion;
	char confirmar[3] = {'n','o','\0'};
	retorno = -1;
	if(array != NULL && arrayP != NULL && size >= 0 && array[indice].estado == 1)
	{
		do{
			if(utn_GetNumero(&opcion, "\nIngrese opcion a cambiar:\n1)Nombre \n2)DNI \n3)Altura \n4)Forma Pago \n5)Salir \n", "Opcion invalida...", 1, 5, 3)== 1)
			{
				switch(opcion)
				{
				case 1:
					if( utn_getNombre(bufferArray.nombre, 50, "Ingrese el nuevo nombre: ", "Error, ingrese nombre valido...", 3)== 1 &&
						utn_getDescripcion(confirmar, 3, "Guardar cambios? [si/no]", "Error, responda si o no", 2) && strncmp(confirmar,"si",3)== 0)
					{
						strncpy(array[indice].nombre,bufferArray.nombre,50);
						printf("Cambio realizado.\n");
						retorno = 1;
					}
					else
					{
						printf("Cambio no realizado.");
						retorno = 2;
					}
					break;
				case 2:
					if( utn_getDni(bufferArray.dni, 20, "Ingrese el nuevo DNI: ", "Error, DNI invalido...", 3)== 1 &&
						utn_getDescripcion(confirmar, 3, "Guardar cambios? [si/no]", "Error, responda si o no", 2)== 1 &&
						strncmp(confirmar,"si",3)== 0)
					{
						strncpy(array[indice].dni,bufferArray.dni,20);
						printf("Cambio realizado.\n");
						retorno = 1;
					}
					else
					{
						printf("Cambio no realizado.\n");
						retorno = 2;
					}
					break;
				case 3:
					if( utn_getNumeroFlotante(&bufferArray.altura, "Ingrese la nueva altura: ", "Error, altura invalida...", 1.2, 4.0, 3)== 1 &&
						utn_getDescripcion(confirmar, 3, "Guardar cambios? [si/no]", "Error, responda si o no", 2) && strncmp(confirmar,"si",3)== 0)
					{
						array[indice].altura = bufferArray.altura;
						printf("Cambio realizado.\n");
						retorno = 1;
					}
					else
					{
						printf("Cambio no realizado.");
						retorno = 2;
					}
					break;
				case 4:
					if(utn_getNombre(bufferPago.tipoPago, 20, "Ingrese nuevo medio de pago: [debito / credito / efectivo / tarjeta] \n",
															  "Error, medio de pago invalido...", 3)== 1 &&
					   utn_getDescripcion(confirmar, 3, "Guardar cambios? [si/no]", "Error, responda si o no", 2) && strncmp(confirmar,"si",3)== 0)
					{
						if(strncmp(bufferPago.tipoPago,"debito",20)== 0 ||
									   strncmp(bufferPago.tipoPago,"credito",20)== 0 ||
									   strncmp(bufferPago.tipoPago,"efectivo",20)== 0 ||
									   strncmp(bufferPago.tipoPago,"tarjeta",20)== 0)
						{
							strncpy(arrayP[indice].tipoPago, bufferPago.tipoPago,20);
							printf("Cambio realizado.\n");
							retorno = 1;
						}else
						{
							printf("Error... medio de pago desconocido...\n");
						}
					}else
					{
						printf("Cambio cancelado.\n");
					}
					break;
				case 5:
					opcion = 6;
					printf("Saliendo...");
					break;
				}
			}
	}while(opcion != 6);
}


	return retorno;
}

int str_bajaArray(Cliente* array, int size, int indice)
{
	int retorno;
	char confirmar[3] = {'n','o','\0'};
	retorno = -1;
	if(array != NULL && size >= 0 && array->estado == 1 && array[indice].estado == 1)
	{
		if(utn_getDescripcion(confirmar, 3, "Guardar cambios? [si/no]", "Error, responda si o no", 2)== 1 && strncmp(confirmar,"si",3)==0)
		{
			array[indice].estado = 0;
			retorno = 1;
		}
	}

	return retorno;
}

int str_buscarId(Cliente array[], int size, int valorBuscado)
{
	int retorno;
	retorno = -1;
	if(array != NULL && size > 0 && valorBuscado >= 0)
	{
		for(int i=0;i<size;i++)
		{
			if(array[i].id == valorBuscado)
			{
				retorno = i;
			}
		}
	}

	return retorno;
}

int str_getEmptyIndex(Cliente* array, int size)
{
	int retorno;
		retorno = -1;
		if(array != NULL && size >= 0)
		{
			for(int i=0;i<size;i++)
			{
				if(array[i].estado == 0)
				{
					retorno = i;
					break;
				}
			}
		}
		return retorno;
}

int str_ordenarPorNombre(Cliente* array, int size)
{
	Cliente auxiliar;
	int retorno;
	retorno = -1;

	if(array != NULL && size >0)
	{
		for(int i=0;i<size-1;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(strncmp(array[i].nombre,array[j].nombre,50)>0)
				{
					auxiliar = array[i];
					array[i] = array[j];
					array[j] = auxiliar;
				}
			}
		}
		retorno = 1;
	}
	return retorno;
}

int str_ordenarPorDni(Cliente* array, int size)
{
	Cliente auxiliar;
	int retorno;
	retorno = -1;

	if(array != NULL && size >0)
	{
		for(int i=0;i<size-1;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(strncmp(array[i].dni,array[j].dni,20)>0)
				{
					auxiliar = array[i];
					array[i] = array[j];
					array[j] = auxiliar;
				}
			}
		}
		retorno = 1;
	}
	return retorno;
}

int str_ordenarPorAltura(Cliente* array, int size)
{
	Cliente auxiliar;
	int retorno;
	retorno = -1;

	if(array != NULL && size >0)
	{
		for(int i=0;i<size-1;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(array[i].altura>array[j].altura)
				{
					auxiliar = array[i];
					array[i] = array[j];
					array[j] = auxiliar;
				}
			}
		}
		retorno = 1;
	}
	return retorno;
}

int str_ordenamientoGlobal(Cliente* array, int size)
{
	int retorno;
	int opcion;
	retorno = -1;
	if(array != NULL && size >0)
	{
		do
		{
			if(utn_GetNumero(&opcion,   "Ingrese opcion:\n"
										"1)Ordenar por nombre\n"
										"2)Ordenar por DNI\n"
										"3)Ordenar por altura\n"
										"4)Salir\n",
										"Error. Ingrese opcion valida...", 1, 4, 3)==1)
			{
				switch(opcion)
				{
				case 1:
					if(str_ordenarPorNombre(array, size)== 1)
					{
						printf("Datos ordenados por nombre.\n");
						retorno =1;
					}
					break;
				case 2:
					if(str_ordenarPorDni(array, size)== 1)
					{
						printf("Datos ordenados por DNI\n");
						retorno =1;
					}
					break;
				case 3:
					if(str_ordenarPorAltura(array, size)== 1)
					{
						printf("Datos ordenados por altura.\n");
						retorno =1;
					}
					break;
				case 4:
					opcion = 5;
					break;
				}
			}
		}while(opcion != 5);
	}
	return retorno;
}

Cliente* strp_newC(void)
{
	Cliente* auxC;
	auxC = NULL;
	auxC = (Cliente*) malloc(sizeof(Cliente)*5);
	return auxC;
}

Pago* strp_newP(void)
{
	Pago* auxP;
	auxP = NULL;
	auxP = (Pago*) malloc(sizeof(Pago)*3);
	return auxP;
}

Cliente* clienteNewParametros(Pago* auxP, char* nombre, char* dni, char* tipoPago, float altura, int id)
{
	Cliente* pauxC;
	pauxC = NULL;
	pauxC = strp_newC();
	auxP = NULL;
	auxP = strp_newP();
	if(pauxC != NULL && auxP != NULL)
	{
		strncpy(pauxC->nombre,nombre,50);
		strncpy(pauxC->dni,dni,20);
		strncpy(auxP->tipoPago,tipoPago,20);
		pauxC->altura = altura;
		pauxC->id = id;
	}
		return NULL;
}

int strp_inicializarArrayPunteros(Cliente* array[],int size)
{
	int retorno;
	retorno = -1;
	if(array != NULL && size > 0)
	{
		for(int i=0;i<size;i++)
		{
			array[i] = NULL;
		}
		retorno = 1;
	}

	return retorno;
}

int strp_getEmptyIndexArrayPunteros(Cliente* array[], int size)
{
	int retorno;
	retorno = -1;
	if(array != NULL && size >= 0)
	{
		for(int i=0;i<size;i++)
		{
			if(array[i] == NULL)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;

}

int strp_altaArrayPunteros(Cliente* array[], Pago* arrayP[], int size, int indice, int* id)
{
	int retorno;
	Cliente bufferCliente;
	Cliente* Pc;
	Pago bufferPago;
	Pago* Pp;
	retorno = -1;
	if(array != NULL && arrayP != NULL && size >= 0 && indice < size && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferCliente.nombre,50,"Ingrese nombre: \n","Error. Ingrese nombre valido...\n",3) == 1 &&
			utn_getDni(bufferCliente.dni,20,"Ingrese DNI: \n","Error, ingrese DNI valido...\n",3) ==1 &&
			utn_getNumeroFlotante(&bufferCliente.altura,"Ingrese altura: \n","Error, Ingrese altura valida", 1, 3, 3) == 1 &&
			utn_getDescripcion(bufferPago.tipoPago, 20, "Ingrese tipo de pago: [debito / credito / efectivo / tarjeta] \n",
														"Error, Elija un tipo de pago correcto.. [debito / credito / efectivo / tarjeta]", 3)== 1)

		{
			if(strncmp(bufferPago.tipoPago,"debito",20)== 0 ||
			   strncmp(bufferPago.tipoPago,"credito",20)== 0 ||
			   strncmp(bufferPago.tipoPago,"efectivo",20)== 0 ||
			   strncmp(bufferPago.tipoPago,"tarjeta",20)== 0)
			{
				bufferCliente.id = *id;
				Pc = strp_newC();
				Pp = strp_newP();
				if(Pc != NULL && Pp != NULL)
				{
					*Pc = bufferCliente;
					*Pp = bufferPago;
					array[indice] = Pc;
					arrayP[indice] = Pp;
					(*id)++;
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

int strp_buscarLibrePuntero(Cliente* array[], int size)
{
	int retorno;
		retorno = -1;
		if(array != NULL && size > 0)
		{
			retorno = -2;
			for(int i=0;i<size;i++)
			{
				if(array[i] == NULL)
				{
					retorno = i;
					break;
				}
			}
		}
		return retorno;
}

int strp_imprimirArrayPunteros(Cliente* array[], Pago* arrayP[], int size)
{
	int retorno;
	retorno = -1;
	if(array != NULL && arrayP != NULL && size > 0)
	{
		for(int i=0;i<size;i++)
		{
			if(array[i] != NULL)
			{
				printf("%d\t%s\t%s\t%.2f\t%s\n",array[i]->id, array[i]->nombre,array[i]->dni,array[i]->altura,arrayP[i]->tipoPago);
			}
		}
		retorno = 1;
	}
	return retorno;
}

int strp_deleteIndexArray(Cliente* arrayP[], int indice)
{
	int retorno;
	retorno = -1;
	if(arrayP != NULL && indice >0 && arrayP[indice] != NULL)
	{
		free(arrayP[indice]);
		arrayP[indice] = NULL;
		retorno = 1;
	}
	return retorno;
}

int strp_alumnoDelete(Cliente* this)
{
	int retorno;
	retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 1;
	}
	return retorno;
}

int strs_setNombre(Cliente* this, char* nombre)
{
	int retorno;
	retorno = -1;
	if(this != NULL && nombre != NULL && esNombre(nombre, 50)== 1)
	{
		strncpy(this->nombre,nombre,50);
	}
	return retorno;
}

int strg_getNombre(Cliente* this, char* nombre)
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

int strs_setDni(Cliente* this, char* dni)
{
	int retorno;
	retorno = -1;
	if(this != NULL && dni != NULL && esNombre(dni, 20)== 1)
	{
		strncpy(this->dni,dni,20);
		retorno = 1;
	}
	return retorno;
}

int strg_getDni(Cliente* this, char* dni)
{
	int retorno;
	retorno = -1;
	if(this != NULL && dni != NULL)
	{
		strncpy(this->dni,dni,20);
		retorno = 1;
	}
	return retorno;
}

int strs_setAltura(Cliente* this, char* altura)
{
	int retorno;
	retorno = -1;
	if(this != NULL && altura != NULL && esFlotante(altura)== 1)
	{
		this->altura = atof(altura);
		retorno = 1;
	}
	return retorno;
}

int strg_getAltura(Cliente* this, char* altura)
{
	int retorno;
	retorno = -1;
	if(this != NULL && altura != NULL)
	{
		sprintf(altura,"%f",this->altura);
		retorno = 1;
	}
	return retorno;
}

int strs_setId(Cliente* this, char* id)
{
	int retorno;
	retorno = -1;
	if(this != NULL && id != NULL && esNumerica(id, 5)== 1)
	{
		this->id = atoi(id);
		retorno = 1;
	}
	return retorno;
}

int strg_getId(Cliente* this, char* id)
{
	int retorno;
	retorno = -1;
	if(this != NULL && id != NULL)
	{
		sprintf(id,"%d", this->id);
		retorno = 1;
	}
	return retorno;
}

int strs_setEstado(Pago* this, char* tipoPago)
{
	int retorno;
	retorno = -1;
	if(this != NULL && tipoPago != NULL && esNombre(tipoPago, 20)== 1)
	{
		strncpy(this->tipoPago,tipoPago,20);
		retorno = 1;
	}
	return retorno;
}

int strg_getEstado(Pago* this, char* tipoPago)
{
	int retorno;
	retorno = -1;
	if(this != NULL && tipoPago != NULL)
	{
		strncpy(this->tipoPago,tipoPago,20);
		retorno = 1;
	}
	return retorno;
}

int strs_setAll(Cliente* thisC, Pago* thisP, char* nombre, char* dni, char* altura, char* id, char* tipoPago)
{
	int retorno;
	retorno = -1;
	if(thisC != NULL && thisP != NULL && nombre != NULL && dni != NULL &&
	   altura != NULL && id != NULL && tipoPago != NULL &&
	   esNombre(nombre, 50)==1 && esNombre(dni, 20)== 1 &&
	   esFlotante(altura)== 1 && esNumerica(id, 5)== 1 &&
	   esNombre(tipoPago, 20)== 1)
	{
		strncpy(thisC->nombre,nombre,50);
		strncpy(thisC->dni,dni,20);
		thisC->altura = atof(altura);
		thisC->id = atoi(id);
		strncpy(thisP->tipoPago,tipoPago,20);
		retorno = 1;
	}
	return retorno;
}

int strg_getAll(Cliente* thisC, Pago* thisP, char* nombre, char* dni, char* altura, char* id, char* tipoPago)
{
	int retorno;
	retorno = -1;
	if(thisC != NULL && thisP != NULL && nombre != NULL && dni != NULL &&
	altura != NULL && id != NULL && tipoPago != NULL)
	{
		strncpy(thisC->nombre,nombre,50);
		strncpy(thisC->dni,dni,20);
		sprintf(altura,"%f", thisC->altura);
		sprintf(id,"%d", thisC->id);
		strncpy(thisP->tipoPago,tipoPago,20);
		retorno = 1;
	}
	return retorno;
}







