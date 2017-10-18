/* Menu de opciones del proyecto (Pilas y colas)
*  Fecha 18/10/2017
*  Elaborado por: John Sebastian Nieto gil 
*  Elaborado por: Ricardo Andres Villalobos
*/
#define PAUSE getchar();printf("\nPresiona una tecla para continuar");getchar() //Generar pausa en linux

int menuCantidad();
int menuEstructura();
int menuOrdenar();
int opcionesCantidad(int);
void nombreArchivo(int, char *);
void menu();

/**
 * Muestra un menu para las opciones correspondientes
 * de estructuras pilas y colas
 */
void menu()
{
	Nodo * pila = NULL;
	Nodo * inicio = NULL;
	Nodo * fin = NULL;

	int opcion = 0;
	int subOpcion = 0;
	int opcionEstructura = 0;
	int opCantidad = 0;
	int copiaOpcion = 0;
	int cantidad = 0;
	int dato = 0;
	char nombre[14];


	do
	{
		system("clear");
		printf("\n\t---Menu principal--");
		printf("\n 1. Pilas");
		printf("\n 2. Colas");
		printf("\n 0. Salir");
		printf("\n\nOpcion: ");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 0:
				printf("\nVuelve pronto...\n");
				exit(0);

			case 1:

				do
				{
					opcionEstructura = menuEstructura();

					switch(opcionEstructura)
					{
						case 0: 
							break;

						case 1:
							subOpcion = menuCantidad();
							cantidad = opcionesCantidad(subOpcion);
							generarDatosPila(cantidad, pila);
							PAUSE;
							break;

						case 2:
							subOpcion = menuCantidad();
							nombreArchivo(subOpcion, nombre);
							cargarDatosPila(nombre, pila);
							PAUSE;
							break;

						case 3:
							listarElementos(pila);
							dato = pedirDato();
							editarElemento(pila, dato);
							PAUSE;
							break;

						case 4:
							eliminarElementoPila(pila);
							PAUSE;
							break;

						case 5:
							eliminarPila(pila);
							PAUSE;
							break;

						case 6: 
							listarElementos(pila);
						    PAUSE;
							break;

						case 7: 
							dato = pedirDato();
							buscarElementos(pila, dato); 
							PAUSE;
							break;

						case 8:
							subOpcion = menuOrdenar();
							switch(subOpcion)
							{
								case 1:
									ordenarDatosDirecto(pila);
									break;
								case 2:
									ordenarDatosRapido(pila);
									break;
							}
							PAUSE;
							break;

						case 9:
							salvarDatos(pila, 1);
							PAUSE;
							break;

						case 10:
							char nombre[23];
							strcpy(nombre, "archivos/datosPila.txt");
							cargarDatosPila(nombre, pila);
							PAUSE;
							break;

						default: 
						    printf("\nNo es una opcion valida");	
						    PAUSE;
						    break;
					}
				}while(opcionEstructura != 0);
				break;

			case 2:

				do
				{
					opcionEstructura = menuEstructura();

					switch(opcionEstructura)
					{
						case 0: 
							break;

						case 1:
							subOpcion = menuCantidad();
							cantidad = opcionesCantidad(subOpcion);
							generarDatosCola(cantidad, inicio, fin);
							PAUSE;
							break;

						case 2:
							subOpcion = menuCantidad();
							nombreArchivo(subOpcion, nombre);
							cargarDatosCola(nombre, inicio, fin);
							PAUSE;
							break;

						case 3:
							listarElementos(inicio);
							dato = pedirDato();
							editarElemento(inicio, dato);
							PAUSE;
							break;

						case 4:
							eliminarElementoCola(inicio, fin);
							PAUSE;
							break;

						case 5:
							eliminarCola(inicio, fin);
							PAUSE;
							break;

						case 6: 
							listarElementos(inicio);
						    PAUSE;
							break;

						case 7: 
							dato = pedirDato();
							buscarElementos(inicio, dato); 
							PAUSE;
							break;

						case 8: 
							subOpcion = menuOrdenar();
							switch(subOpcion)
							{
								case 1:
									ordenarDatosDirecto(inicio);
									break;
								case 2:
									ordenarDatosRapido(inicio);
									break;
							}
							PAUSE;
							break;

						case 9:
							salvarDatos(inicio, 2);
							break;

						case 10:
							char nombre[23];
							strcpy(nombre, "archivos/datosCola.txt");
							cargarDatosCola(nombre, inicio, fin);
							PAUSE;
							break;

						default: 
						    printf("\nNo es una opcion valida");	
						    PAUSE;
						    break;
					}
				}while(opcionEstructura != 0);
				break;

			default:
				printf("\nOpcion no valida");
				PAUSE;
				break;

		}

	}while(opcion != 0);
}

/**
 * Imprime las operaciones de la estructura
 * y retorna la seleccionada
 */
int menuEstructura()
{
	int opcion = 0;
	system("clear");
	printf("\n\t\t\t---MENU---");
	printf("\n\t1. Generar Elementos");
	printf("\n\t2. Cargar Elementos");
	printf("\n\t3. Editar Elementos");
	printf("\n\t4. Eliminar Elementos");
	printf("\n\t5. Eliminar estructura");
	printf("\n\t6. Listar Elementos");
	printf("\n\t7. Buscar Elementos");
	printf("\n\t8. Ordenar estructura");
	printf("\n\t9. Salvar Datos");
	printf("\n\t10. Restaurar Datos");
	printf("\n\t0. Salir");
	printf("\n\n\tIngrese una opcion\n");
	scanf("%d", &opcion);

	return opcion;
}

/**
 * Imprime as opciones con las cantidades
 * y retorna la seleccionada
 */
int menuCantidad()
{
	system("clear");
	int opcion = 0;
	printf("\n\t\t---Cantidad---");
	printf("\n 1. Un millon");
	printf("\n 2. Dos millones");
	printf("\n 3. Cinco millones");
	printf("\n 4. Diez millones");
	printf("\n 5. Veinte millones");
	printf("\n\nOpcion: ");
	scanf("%d", &opcion);

	return opcion;
}

/**
 * Imprime dos opciones con los metodos de ordenamiento
 * y retorna el seleccionado
 */
int menuOrdenar()
{
	system("clear");
	int opcion = 0;
	printf("\n\t\t---Metodo de ordenamiento---");
	printf("\n 1. Metodo directo(burbuja)");
	printf("\n 2. Metodo Rapido");
	printf("\n 0. Salir");
	printf("\n\nOpcion: ");
	scanf("%d", &opcion);

	return opcion;
}

/**
 * Retorna una cantidad segun la opcion escogida
 */
int opcionesCantidad(int opcion)
{
	int cantidad = 0;
	switch(opcion)
	{
		case 1:
			cantidad = 1000000;
			break;
		case 2:
			cantidad = 2000000;
			break;
		case 3:
			cantidad = 5000000;
			break;
		case 4:
			cantidad = 10000000;
			break;
		case 5:
			cantidad = 20000000;
			break;
	}

	return cantidad;
}

/**
 * copia un nombre de archivo en un arreglo de caracteres
 * según una opcion escogida
 */
void nombreArchivo(int opcion, char *nombre)
{
	switch(opcion)
	{
		case 1:
			strcpy(nombre, "archivos/1millon.txt");
			break;
		case 2:
			strcpy(nombre, "archivos/2millones.txt");
			break;
		case 3:
			strcpy(nombre, "archivos/5millones.txt");
			break;
		case 4:
			strcpy(nombre, "archivos/10millones.txt");
			break;
		case 5:
			strcpy(nombre, "archivos/20millones.txt");
			break;
	}
}