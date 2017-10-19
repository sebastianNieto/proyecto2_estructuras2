/* Se definen las funciones para las operaciones correspondientes a pilas y colas.
*  Fecha 18/10/2017
*  Elaborado por: John Sebastian Nieto gil 
*  Elaborado por: Ricardo Andres Villalobos
*/
#define RESERVAR_MEMORIA (Nodo *)malloc(sizeof(Nodo))
#define MENSAJE_TIEMPO printf("\nTiempo transcurrido: %.0f milisegundos.", ((double)clock() - tiempoInicio) / CLOCKS_PER_SEC)

struct Nodo
{
	int dato;
	Nodo* siguiente;
};

void insertarElementoPila(int, Nodo *&);
void insertarDatosCola(int, Nodo* &, Nodo* &);
void eliminarElementoPila(Nodo *&);
void eliminarElementoCola(Nodo* &, Nodo* &);
void eliminarPila(Nodo *&);
void eliminarCola(Nodo* &, Nodo* &);
void listarElementos(Nodo *);
void buscarElementos(Nodo *, int);
void editarElemento(Nodo *&, int);
bool estructuraVacia(Nodo *);
int pedirDato();
void cargarDatosPila(char*, Nodo* &);
void generarDatosPila(int, Nodo* &);
void cargarDatosCola(char*, Nodo* &, Nodo* &);
void generarDatosCola(int, Nodo* &, Nodo* &);
void ordenarDatosDirecto(Nodo* &);
void ordenarDatosRapido(Nodo * &);
int salvarDatos(Nodo* , int);
int selectDigit(int, int);
void iniciarArreglo(Nodo* [], int);

/**
 * Carga los datos desde un archivo a una pila
 */
void cargarDatosPila(char* nombreArchivo, Nodo* &estructura)
{
	clock_t tiempoInicio;
	tiempoInicio = clock();
	FILE * archivo;
	archivo = fopen(nombreArchivo, "rb");
	int dato;
	while(fread(&dato, sizeof(dato), 1, archivo))
	{
		insertarElementoPila(dato, estructura);
	}
	
	printf("\nSe cargaron correctamente los datos\n");
	MENSAJE_TIEMPO;
}

/**
 * Genera datos aleatorios y los ingresa en una pila
 */
void generarDatosPila(int cantidad, Nodo* &estructura)
{
	clock_t tiempoInicio;
	tiempoInicio = clock();
	int dato = 0;

	srand(clock());
	for(int i = 0; i < cantidad; i+=1)
	{
		dato = (rand()%1999999 - 999999);
		insertarElementoPila(dato, estructura);
	}

	printf("\nSe generaron correctamente %d de datos\n", cantidad);
	MENSAJE_TIEMPO;
}

/**
 * Carga los datos desde un archivo a una cola
 */
void cargarDatosCola(char* nombreArchivo, Nodo* &estructura, Nodo* &fin)
{
	clock_t tiempoInicio;
	tiempoInicio = clock();
	FILE * archivo;
	archivo = fopen(nombreArchivo, "rb");
	int dato;
	while(fread(&dato, sizeof(dato), 1, archivo))
	{
		insertarDatosCola(dato, estructura, fin);
	}
	printf("\nSe cargaron correctamente los datos\n");
	MENSAJE_TIEMPO;
}

/**
 * Genera datos aleatorios y los ingresa en una pila
 */
void generarDatosCola(int cantidad, Nodo* &estructura, Nodo* &fin)
{
	clock_t tiempoInicio;
	tiempoInicio = clock();
	int dato = 0;

	srand(clock());
	for(int i = 0; i < cantidad; i+=1)
	{
		dato = (rand()%1999999 - 999999);
		insertarDatosCola(dato, estructura, fin);
	}
	printf("\nSe generaron correctamente %d de datos\n", cantidad);
	MENSAJE_TIEMPO;
}


/**
 * Insertar un nuevo elemento al inicio de la pila
 */
void insertarElementoPila(int dato, Nodo* &pila)
{
	Nodo* nuevoNodo = RESERVAR_MEMORIA;

	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = pila;
	pila = nuevoNodo;
}

/**
 * Inserta un nuevo elemento al fina de la cola
 */
void insertarDatosCola(int numero, Nodo* &inicio, Nodo* &fin)
{

	Nodo * nuevoNodo = RESERVAR_MEMORIA;
	nuevoNodo->dato = numero;
	nuevoNodo->siguiente = NULL;

	if(estructuraVacia(inicio))
	{
		inicio = nuevoNodo;
	}
	else
	{
		fin->siguiente = nuevoNodo;
	}
	fin = nuevoNodo;
}

/*
 * Editar un elemento en la estructura(pila, cola)
 */
void editarElemento(Nodo* &estructura, int dato)
{
	Nodo* aux = estructura;
	int contador = 0;
	int nuevoDato = 0;
	int posicion = 0;
	char comprobar;

	if(estructuraVacia(estructura))
	{
		printf("\nPila vacia");
	}
	else
	{
		while(aux != NULL)
		{
			if(aux->dato == dato)
			{
				contador++;
				printf("\n %d dato  encontrado, posicion: %d, direccion en memoria: %p", contador, posicion+1, &aux->dato);
				printf("\n¿Desea editar este elemento?. S o N: ");
				getchar();
				scanf("%c", &comprobar);
				if(comprobar == 's' || comprobar == 'S')
				{
					nuevoDato = pedirDato();
					aux->dato = nuevoDato;
					break;
				}
			}
			posicion += 1;
			aux = aux->siguiente;
		}
		if(contador == 0)
		{
			printf("\nDato no encontrado");
		}
	}
}
 

/**
 * Eliminar el primer elemento de la pila
 */

void eliminarElementoPila(Nodo* &pila)
{
	Nodo *aux = pila;

	if(estructuraVacia(pila))
	{
		printf("\nPila vacia");
	}
	else
	{
		pila = aux->siguiente;
		free(aux);
	}
}

/**
 * Elimina el primer elemento de la cola
 */
void eliminarElementoCola(Nodo* &inicio, Nodo* &fin)
{
	Nodo* aux = inicio;
	if(estructuraVacia(inicio))
	{
		printf("\nCola vacia");
	}
	else
	{
		if(inicio == fin)
		{
			inicio = NULL;
			fin == NULL;
		}
		else
		{
			inicio = inicio->siguiente;
		}
		free(aux);
	}
}

/**
 * Eliminar completamente la pila
 */

void eliminarPila(Nodo* &pila)
{
	clock_t tiempoInicio;
	tiempoInicio = clock();

	if(estructuraVacia(pila))
	{
		printf("\nPila vacia");
	}
	else
	{
		while(pila != NULL)
		{
			eliminarElementoPila(pila);	
		}
	}

	
	printf("\nSe elimino la pila\n");
	MENSAJE_TIEMPO;
}

/**
 * Elimina todos los elementos de la cola.
 */
void eliminarCola(Nodo* &inicio, Nodo* &fin)
{
	clock_t tiempoInicio;
	tiempoInicio = clock();

	if(estructuraVacia(inicio))
	{
		printf("\nPila vacia");
	}
	else
	{
		while(inicio != NULL)
		{
			eliminarElementoCola(inicio, fin);	
		}
	}
	printf("\nSe elimino la Cola\n");
	MENSAJE_TIEMPO;
}


/**
 * Muestra todos los elementos de la estructura(pila, cola)
 */

void listarElementos(Nodo* estructura)
{
	clock_t tiempoInicio;
	tiempoInicio = clock();

	Nodo *aux = estructura;

	if(estructuraVacia(estructura))
	{
		printf("\nLa estructura esta vacia");
	}
	else
	{
		while(aux != NULL)
		{
			printf("\n %d", aux->dato);
			aux = aux->siguiente;
		}
	}
	MENSAJE_TIEMPO;
}


/**
 * Busca un elemento en la estructura(pila, cola)
 */

void buscarElementos(Nodo* estructura, int dato)
{
	clock_t tiempoInicio;
	tiempoInicio = clock();

	Nodo *aux = estructura;
	int contador = 0;
	int posicion = 0;

	if(estructuraVacia(estructura))
	{
		printf("Pila vacia\n");
	}
	else
	{
		while(aux != NULL)
		{
			if(aux->dato == dato)
			{
				contador += 1;
				printf("\n %d dato  encontrado, posicion: %d, direccion en memoria: %p", contador, posicion+1, &aux->dato);
				//break;
			}

			aux = aux->siguiente;
			posicion += 1;
		}
		if(contador == 0)
		{
			printf("\nNo se encontro el dato");
		}
	}
	MENSAJE_TIEMPO;
}


/**
 * Comprobar si la estructura(pila, cola) esta vacía
 */

bool estructuraVacia(Nodo *estructura)
{
	if(estructura == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/**
 * Ingresa un nuevo dato solicitado por teclado
 */

int pedirDato()
{	
	int dato;

	printf("\nIngrese un dato: ");
	scanf("%d", &dato);

	return dato;
}

/**
 * Ordena la estructura(pila, cola), utlizando un metodo de
 * ordenamiento directo(burbuja).
 */
void ordenarDatosDirecto(Nodo* &estructura)
{
	clock_t tiempoInicio;
	tiempoInicio = clock();

	int aux;
	Nodo* auxNodo = estructura;
	Nodo* copiaSiguiente = NULL;

	if(estructuraVacia(estructura))
	{
		printf("\nLa pila esta vacia");
	}
	else
	{
		while(auxNodo != NULL)
		{
			copiaSiguiente = auxNodo->siguiente;
			while(copiaSiguiente != NULL)
			{

				if(auxNodo->dato > copiaSiguiente->dato)
				{
					aux = auxNodo->dato;
					auxNodo->dato = copiaSiguiente->dato;
					copiaSiguiente->dato = aux;
				}

				copiaSiguiente = copiaSiguiente->siguiente;
			}
			auxNodo = auxNodo->siguiente;
		}
	}
	printf("\nDatos ordenados\n"); 
	MENSAJE_TIEMPO;
}

/**
 * Ordena la estructura(pila, cola), utlizando un metodo de
 * ordenamiento rápido(radix).
 */
void ordenarDatosRapido(Nodo* &estructura)
{
	clock_t tiempoInicio;
	tiempoInicio = clock();

	Nodo* auxNodo = estructura;
	Nodo* copiaSiguiente = NULL;
	Nodo* vector[19];
	Nodo* vectorFin[19];
	int divisor = 1;

	if(estructuraVacia(estructura))
	{
		printf("\nEstructura vacia");
	}
	else
	{
		iniciarArreglo(vector, 19);
		iniciarArreglo(vectorFin, 19);

		for(int i = 0; i < 6; i++)
		{
			copiaSiguiente = auxNodo;
			while(auxNodo != NULL)
			{
				/* vector[selectDigit(auxNodo->dato, divisor)+9] -> la función selectDigit me retorna un digito de un numero,
				y a este le sumo 9; con esto estoy diciendo que a esa posicion del vector(9+digito) se ve a gurdar el número.
				La suma del nueve se debe a q si selectDigit retorna un negativo que maximo puede ser -9 se guardara en la posicio 0 ya 
				que -9 es el numero menor de todos. */
				insertarDatosCola(auxNodo->dato, vector[selectDigit(auxNodo->dato, divisor)+9], vectorFin[selectDigit(auxNodo->dato, divisor)+9]);
				auxNodo = auxNodo->siguiente;
			}

			auxNodo = copiaSiguiente;
			//eliminarPila(auxNodo);
			for(int j = 0; j < 19; j++)
			{
				if(!estructuraVacia(vector[j]))
				{
					while(vector[j] != NULL)
					{
						//insertarElementoPila(vector[j]->dato, auxNodo);
						auxNodo->dato = vector[j]->dato;
						vector[j] = vector[j]->siguiente;
						auxNodo = auxNodo->siguiente;
					}
					while(vector[j] != NULL)
					{
						eliminarElementoCola(vector[j], vectorFin[j]);	
					}
					//eliminarCola(vector[j], vectorFin[j]);
				}
				vector[j] = NULL;
			}
				auxNodo = copiaSiguiente;
			
			divisor *= 10;
		}

		printf("\nDatos ordenados\n"); 
	}

	MENSAJE_TIEMPO;
}

/**
 * Retorna el dígito de un número
 */
int selectDigit(int number, int divisor)
{
	return (number/divisor%10);
}

/**
 * Inicializa todos los elementos del arreglo en null
 */
void iniciarArreglo(Nodo *arreglo[], int cantidad)
{
	for(int i = 0; i < cantidad; i++)
	{
		arreglo[i] = NULL;
	}
}

/**
 * Guarda los elementos de la estructura(pila, cola) en una archivo.
 */
int salvarDatos(Nodo* estructura, int tipo)
{
	clock_t tiempoInicio;
	tiempoInicio = clock();

	Nodo *aux = estructura;
	FILE * archivo;
	int dato = 0;
	char nombre[23];

	if(tipo == 1)
	{
		strcpy(nombre, "archivos/datosPila.txt");
	}
	else
	{
		 strcpy(nombre, "archivos/datosCola.txt");
	}

	archivo = fopen(nombre, "wb");

	if(archivo == NULL)
	{
		printf("No se pudo crear el archivo");
		return false;
	}

	if(estructuraVacia(estructura))
	{
		printf("\nLa estructura esta vacia");
	}
	else
	{
		while(aux != NULL)
		{
			dato = aux->dato;
			fwrite(&dato, sizeof(dato), 1, archivo);
			aux = aux->siguiente;
		}
	}
	printf("Se guardaron correctamente los datos\n");
	MENSAJE_TIEMPO;
	return 0;
}
