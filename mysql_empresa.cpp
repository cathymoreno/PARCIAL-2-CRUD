// mysql_empresa.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <mysql.h>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

MYSQL* conectar;
//marca




	void crear_marca() {
		system("cls");
		string marca;
		string insert;
		int q_estado;
		cout << "Ingrese Marca: ";
		cin >> marca;
		insert = "insert into marcas(marca) values('" + marca + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Ingreso Exitoso" << endl;
		}
		else {
			cout << " xxxx Error al Ingresar xxxx " << endl;

		}
		system("pause");
	}


	void eliminar_marca() {
		system("cls");
		int id_eliminar;
		string insert;
		int q_estado;
		cout << "Ingrese Id a eliminar: ";
		cin >> id_eliminar;
		insert = "delete from marcas where id_marca = " + to_string(id_eliminar);
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Eliminado Exitoso" << endl;
		}
		else {
			cout << " xxxx Error al Eliminar xxxx " << endl;

		}
		system("pause");
	}


	void modificar_marca() {
		system("cls");
		string modifica_marca;
		int id_modifica;
		string insert;
		int q_estado;
		cout << "Ingrese Id a modificar: ";
		cin >> id_modifica;
		cout << "Ingrese nombre de marca: ";
		cin >> modifica_marca;
		insert = "update marcas set marca = '" + modifica_marca + "' where id_marca = " + to_string(id_modifica);

		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Actualizado Exitoso" << endl;
		}
		else {
			cout << " xxxx Error al Actualizar xxxx " << endl;

		}
		system("pause");
	}


	void mostrar_marcas() {
		system("cls");
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string consulta = "select * from marcas";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << "," << fila[1] << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << endl;


				}
			}
		}
		else {
			cout << " xxxx Error al Consultar xxxx " << endl;

		}

		system("pause");
	}


	//producto

	void crear_producto() {
		system("cls");
		string producto, descripcion, imagen, fecha_ingreso;
		int id_marca, existencia;
		int precio_costo, precio_venta;

		string insert;
		int q_estado;
		cout << "Ingrese producto: ";
		cin >> producto;
		cout << "Ingrese el id de la marca: ";
		cin >> id_marca;
		cout << "Ingrese la descripcion del producto: ";
		cin >> descripcion;
		cout << "Ingrese la imagen del producto: ";
		cin >> imagen;
		cout << "Ingrese el precio costo del producto: ";
		cin >> precio_costo;
		cout << "Ingrese el precio venta del producto: ";
		cin >> precio_venta;
		cout << "Ingrese la cantidad del productos en existencia: ";
		cin >> existencia;
		cout << "Ingrese la fecha de ingreso: ";
		cin >> fecha_ingreso;
		insert = "insert into productos(producto,id_marca,descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso) values('" + producto + "'," + to_string(id_marca) + ",'" +descripcion + "','" +imagen + "'," + to_string(precio_costo) + "," + to_string(precio_venta) + "," + to_string(existencia) + ",'" +fecha_ingreso + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Ingreso Exitoso" << endl;
		}
		else {
			cout << " xxxx Error al Ingresar xxxx " << endl;

		}
		system("pause");
	}

	void eliminar_producto() {
		system("cls");
		int id_eliminar;
		string insert;
		int q_estado;
		cout << "Ingrese Id a eliminar: ";
		cin >> id_eliminar;
		insert = "delete from productos where id_producto = " + to_string(id_eliminar);
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Eliminado Exitoso" << endl;
		}
		else {
			cout << " xxxx Error al Eliminar xxxx " << endl;

		}
		system("pause");
	}

	void modificar_producto() {
		system("cls");
		string modifica_producto, modifica_descripcion, modifica_imagen, modifica_fecha_ingreso;
		int id_modifica, modifica_id_marca, modifica_precio_costo, modifica_precio_venta, modifica_existencia;
		string insert;
		int q_estado;
		cout << "Ingrese Id a modificar: ";
		cin >> id_modifica;
		cout << "Ingrese nombre del producto: ";
		cin >> modifica_producto;
		cout << "Ingrese el id de la marca: ";
		cin >> modifica_id_marca;
		cout << "Ingrese la descripcion del producto: ";
		cin >> modifica_descripcion;
		cout << "Ingrese la imagen del producto: ";
		cin >> modifica_imagen;
		cout << "Ingrese el precio costo del producto: ";
		cin >> modifica_precio_costo;
		cout << "Ingrese el precio venta del producto: ";
		cin >> modifica_precio_venta;
		cout << "Ingrese la cantidad del productos en existencia: ";
		cin >> modifica_existencia;
		cout << "Ingrese la fecha de ingreso: ";
		cin >> modifica_fecha_ingreso;
		insert = "update productos set producto = '" + modifica_producto + "', id_marca = " + to_string(modifica_id_marca)+", descripcion = '"+modifica_descripcion + "', imagen='" +modifica_imagen + "', precio_costo= "+to_string(modifica_precio_costo) + ", precio_venta="+ to_string(modifica_precio_venta) + ", existencia ="+to_string(modifica_existencia) + ", fecha_ingreso = '" + modifica_fecha_ingreso + "' where id_producto = " + to_string(id_modifica);
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Actualizado Exitoso" << endl;
		}
		else {
			cout << " xxxx Error al Actualizar xxxx " << endl;

		}
		system("pause");
	}

	void mostrar_productos() {
		system("cls");
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string consulta = "select * from productos";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << "," << fila[1] << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << endl;


				}
			}
		}
		else {
			cout << " xxxx Error al Consultar xxxx " << endl;

		}

		system("pause");

	}



	//menu marca
void menumarcas() {
		int numero;
		do
		{
			system("cls");
			numero = 0;
			cout << "*******\n";
			cout << "                  +------------------------+" << endl;
			cout << "                  |          Menu          |" << endl;
			cout << "                  +------------------------+" << endl;
			cout << "                  | Seleccione una Opcion  |" << endl;
			cout << "                  | 1.- Crear Marca        |" << endl;
			cout << "                  | 2.- Eliminar Marca     |" << endl;
			cout << "                  | 3.- Modificar Marca    |" << endl;
			cout << "                  | 4.- Ver Marcas         |" << endl;
			cout << "                  | 5.- Salir              |" << endl;
			cout << "                  +------------------------+" << endl;
			cout << "*******" << endl;
			cout << "Ingrese un numero ";
			cin >> numero;

			switch (numero) {
			case 1: crear_marca();
				break;
			case 2: eliminar_marca();
				break;
			case 3: modificar_marca();
				break;
			case 4: mostrar_marcas();
				break;
			}
		} while (numero != 5);

	}






	//menu producto
void menuproducto() {
		int numero;
		do
		{
			system("cls");
			numero = 0;
			cout << "*********************\n";
			cout << "                  +------------------------+" << endl;
			cout << "                  |          Menu          |" << endl;
			cout << "                  +------------------------+" << endl;
			cout << "                  | Seleccione una Opcion  |" << endl;
			cout << "                  | 1.- Crear Producto     |" << endl;
			cout << "                  | 2.- Eliminar Producto	|" << endl;
			cout << "                  | 3.- Modificar Producto	|" << endl;
			cout << "                  | 4.- Ver Productos		|" << endl;
			cout << "                  | 5.- Salir              |" << endl;
			cout << "                  +------------------------+" << endl;
			cout << "*********************" << endl;
			cout << "Ingrese un numero ";
			cin >> numero;

			switch (numero) {
			case 1: crear_producto();
				break;
			case 2: eliminar_producto();
				break;
			case 3: modificar_producto();
				break;
			case 4: mostrar_productos();
				break;
			}
		} while (numero != 5);

	}


//primer menu
void menuprincipal() {
		int numero;
		do
		{
			system("cls");
			numero = 0;
			cout << "*********************\n";
			cout << "                  +------------------------+" << endl;
			cout << "                  |          Menu          |" << endl;
			cout << "                  +------------------------+" << endl;
			cout << "                  | Seleccione una Opcion  |" << endl;
			cout << "                  | 1.- Tabla Productos    |" << endl;
			cout << "                  | 2.- Tabla Marcas		|" << endl;
			cout << "                  | 3.- Salir              |" << endl;
			cout << "                  +------------------------+" << endl;
			cout << "*********************" << endl;
			cout << "Ingrese un numero ";
			cin >> numero;

			switch (numero) {
			case 1: menuproducto();
				break;
			case 2: menumarcas();
				break;
			}

			} while (numero != 3);

	}

void main()
{
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "junio", "db_empresa", 3306, NULL, 0);
	if (conectar) {
		cout << "Conexion Exitosa..." << endl;
	}
	else {
		cout << "Error en la conexion..." << endl;
	}

	menuprincipal();

}

