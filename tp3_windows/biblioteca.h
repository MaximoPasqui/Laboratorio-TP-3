

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

typedef struct
{
	char tipoPago[20];

}Pago;


typedef struct
{
	char nombre[50];
	char dni[20];
	float altura;
	int estado;
	int id;
	Pago IDpago;

}Cliente;


int utn_GetNumero(int*, char*, char*, int, int, int );
int utn_getNumeroFlotante(float*, char*, char*, float, float, int);
int utn_getNombre(char*, int, char*, char*, int);
int utn_getDescripcion(char*, int, char*, char*, int);
int utn_getDni(char*, int, char*, char*, int);

int str_imprimir(Cliente*, Pago*);
int str_imprimirArray(Cliente*, Pago*, int);
int str_InicializarArray(Cliente*, int);
int str_altaArray(Cliente*, Pago*, int, int, int*);
int str_altaForzada(Cliente*, Pago*, int, int, int*, char*, char*, float, char*);
int str_getEmptyIndex(Cliente*, int);
int str_buscarId(Cliente[], int, int);
int str_modificarArray(Cliente*, Pago*, int, int);
int str_bajaArray(Cliente*, int, int);
int str_ordenarPorNombre(Cliente*, int);
int str_ordenarPorDni(Cliente*, int);
int str_ordenarPorAltura(Cliente*, int);
int str_ordenamientoGlobal(Cliente*, int);

Cliente* strp_newC(void);
Pago* strp_newP(void);

Cliente* clienteNewParametros(Pago*, char*, char*, char*, float, int);
int strp_inicializarArrayPunteros(Cliente**, int);
int strp_getEmptyIndexArrayPunteros(Cliente**, int);
int strp_altaArrayPunteros(Cliente**, Pago**, int, int, int*);
int strs_setNombre(Cliente*, char*);
int strg_getNombre(Cliente*, char*);
int strs_setDni(Cliente*, char*);
int strg_getDni(Cliente*, char*);
int strs_setAltura(Cliente*, char*);
int strg_getAltura(Cliente*, char*);
int strs_setId(Cliente*, char*);
int strg_getId(Cliente*, char*);
int strs_setEstado(Pago*, char*);
int strg_getEstado(Pago*, char*);
int strs_setAll(Cliente*, Pago*, char*, char*, char*, char*, char*);
int strg_getAll(Cliente*, Pago*, char*, char*, char*, char*, char*);

#endif
