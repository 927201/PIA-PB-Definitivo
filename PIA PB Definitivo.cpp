#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <conio.h>

const char DIR_ARCHIVO[] = "productos.dat";

using namespace std;


//declaracion de variables
int* producto, registros, decision;             //Los asericos son punteros que ayudan a ver la informacion en los espacios de memoria donde se marca
string* nombre, * clasificacion, * caracteristicas, * descripcion, * genero, * year;
float* precio, * iva, * total;

//funciones void
void alta();
void eliminar();
void modificar();  //Las funciones void sirven para ejecutar muchas instrucciones y no alargar el codigo
void lista();
void archivo();

int main()
{
	int opcion;
	do {
		system("cls");
		printf("\t ***Game Buy*** \n");
		printf("1.-Agregar articulo \n 2.-Modificar articulo \n 3.-Eliminar articulo \n 4.-Lista de Articulos \n 5.-Limpiar Pantalla \n 6.-Salir \n\n");
		printf("Seleccione una opcion: ");
		cin >> opcion;
		cin.ignore();   //salta o ignora el espacio entre palabras
		//scanf("d%", &opcion);

		switch (opcion)        // Puse switch para ser la entrada del menu y haya opciones a elegir
		{
		case 1: //Agregar articulo
			alta();
			break;

		case 2://Modificar articulo
			modificar();
			break;

		case 3: //Eliminar articulo
			eliminar();
			break;

		case 4: //Lista de Articulos
			lista();
			break;

		case 5: //Limpiar Pantalla
			system("cls");
			break;

		case 6: //Salir
			exit(1);
			break;

		default:
			printf("opcion invalida \n");
			system("pause");
		}
	} while (opcion != 6);  //dejar un limite de que solo hay 6 opciones y no mas
	return 0;
}

void alta()   //Aqui es para meter articulos
{
	system("cls");
	printf("Cuantos registros desea dar de alta?: ");
	scanf_s("%d", &registros);
	producto = new int[registros];
	year = new string[registros]; 
	nombre = new string[registros];
	caracteristicas = new string[registros];    //NEW: es para marcar nuevas cadenas de texto de las variables
	clasificacion = new string[registros];
	descripcion = new string[registros];
	genero = new string[registros];
	precio = new float[registros];
	iva = new float[registros];
	total = new float[registros];
	int n = 1;
	//arreglo
	for (int i = 0; i < registros; i++)         // la "i" significa el int del codigo el "<" el ++ es para decir la cantidad de datos que se van a ingresar
	{
		printf("Ingrese el producto %d: ", i + 1);
		scanf_s("%d", &producto[i]);
		do
		{
			if (producto[i] != producto[i - n])
			{
				n = n + 1;
			}
			else
			{
				printf("El Producto ya existe...\n");
				printf("Ingrese el Producto: ");
				scanf_s("%d", &producto[i]);           // %d es para marcar qu la variable es de tipo entero y el "scanf_s" es el cout pero mas avanzado
			}
		} while (n < registros);
		printf("Ingrese el a%co de lanzamiento\n: " ,164);//Ñ  // %c esto ayuda para usar caracteres especificos o letras con lo mismo
		cin.ignore();
		getline(cin, year[i]);           //getline sirve para poner espacios entre palabras y no se amontonen
		printf("Ingrese el nombre: ");
		getline(cin, nombre[i]);
		printf("Ingrese las caracteristicas: ");
		getline(cin, caracteristicas[i]);
		printf("Ingrese la clasificacion: ");
		getline(cin, clasificacion[i]);
		printf("Ingrese la descripcion: ");
		getline(cin, descripcion[i]);
		printf("Ingrese el genero: ");
		getline(cin, genero[i]);
		printf("Ingrese el precio: ");
		scanf_s("%f", &precio[i]);
		iva[i] = precio[i] * .16;
		total[i] = precio[i] + iva[i];
		printf("IVA: %f", iva[i]);            // El %f es para indicar las variable de tipo de decimal
		printf("    Total: %f \n\n", total[i]);
		if ((registros - 1) == i)
		{
			printf("Quiere dar de alta otro registro?: 1-Si  2-No ");
			cin >> decision;
			cin.ignore();
			//scanf_s("%d", decision);
			if (decision == 1)
			{
				registros = registros + 1;
			}
		}
	}
}

void modificar()
{
	system("cls");
	int modifi;
	do {
		printf("Ingrese el numero de Producto a modificar: ");
		scanf_s("%d", &modifi);
	} while (modifi < 0);   //Puse while para indicar que se debe cumplir la condicion

	for (int i = 0; i < registros; i++)
	{
		if (modifi == producto[i])
		{
			printf("Ingrese el a%co de lanzamiento\n: " , 165); //Ñ
			cin.ignore();
			getline(cin, year[i]);
			printf("Ingrese el nombre: ");
			getline(cin, nombre[i]);
			printf("Ingrese las caracteristicas: ");
			getline(cin, caracteristicas[i]);
			printf("Ingrese la clasificacion: ");
			getline(cin, clasificacion[i]);
			printf("Ingrese la descripcion: ");
			getline(cin, descripcion[i]);
			printf("Ingrese el genero: ");
			getline(cin, genero[i]);
			printf("Ingrese el precio: ");
			scanf_s("%f", &precio[i]);
			iva[i] = precio[i] * .16;
			total[i] = precio[i] + iva[i];
		}
	}
}

void eliminar()
{
	system("cls");
	int elim;
	printf("Ingrese el numero de Producto a eliminar: ");
	scanf_s("%d", &elim);
	for (int i = 0; i < registros; i++)
	{
		if (elim == producto[i]) //es para eliminar el producto
		{
			producto[i] = 0;
		}
	}

}

void lista()
{
	system("cls");
	int op2;
	string busc;
	printf("Seleccione el tipo de busqueda. \n");
	printf("1.- Por Clasificacion \n 2.- Por Genero \n");
	cin >> op2;
	cin.ignore();
	//scanf("&d", &op2);
	switch (op2) // este switch es para separa las dos formas en las que se buscaria el producto  pero teniendo las mismas descripciones
	{
	case 1:
		printf("Ingrese la clasificacion a buscar: ");
		cin.ignore();
		getline(cin, busc);
		for (int i = 0; i < registros; i++)
		{
			if (clasificacion[i] == busc)
			{
				//if(producto[i] != 0)
				//{
				printf("Producto: %d", producto[i]);
				printf("A%co: %d\n" , year[i]); //Ñ
				printf("Videojuego: %d", nombre[i].c_str());
				printf("Clasificacion: %d", clasificacion[i].c_str());
				printf("Genero: %d", genero[i].c_str());
				printf("Caracteristicas: %d", caracteristicas[i].c_str());
				printf("Descripcion: %d", descripcion[i].c_str());
				printf("Precio: %f", precio[i]);
				printf("IVA: %f", iva[i]);
				printf("Total: %f", total[i]);
				//}
			}
		}
		system("pause");
		break;

	case 2:
		printf("Ingrese el Genero a buscar: ");
		cin.ignore();
		getline(cin, busc);
		for (int i = 0; i < registros; i++)
		{
			if (genero[i] == busc)
			{
				//if(producto[i] != 0)
				  //{
				printf("Producto: %d", producto[i]);
				printf("A%co: %d\n", year[i]); //Ñ
				printf("Videojuego: %d", nombre[i].c_str());
				printf("Clasificacion: %d", clasificacion[i].c_str());
				printf("Genero: %d", genero[i].c_str());
				printf("Caracteristicas: %d", caracteristicas[i].c_str());
				printf("Descripcion: %d", descripcion[i].c_str());
				printf("Precio: %f", precio[i]);
				printf("IVA: %f", iva[i]);
				printf("Total: %f", total[i]);
				//}
			}
		}
		system("pause");
		break;
		//default;
	}
}
