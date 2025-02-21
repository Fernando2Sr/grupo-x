#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
	string nombre;
	int ano;

public:
	Cliente(string _nombre, int _ano) {
		nombre = _nombre;
		ano = _ano;
	}

	void mostrarDatos() {
		cout << "Nombre: " << nombre << endl << "Edad: " << ano << endl;
	}
};

class numTelefono : public Cliente {
private:
	int numCelular;

public:
	numTelefono(string _nombre, int _ano, int _numCelular) :
		Cliente(_nombre, _ano) {
		numCelular = _numCelular;
	}

	void mostrarnumeroCelular() {
		cout << "Su numero es: " << numCelular << endl;
	}
};

class correoElec : public Cliente {
private:
	string correoElectronico;

public:
	correoElec(string _nombre, int _ano, string _correoElectronico) :
		Cliente(_nombre, _ano) {
		correoElectronico = _correoElectronico;
	}

	void mostrarCorreoElec() {
		cout << "Su correo electronico es: " << correoElectronico << endl;
	}
};

class DPI : public Cliente {
private:
	int dpi;

public:
	DPI(string _nombre, int _ano, int _dpi) :
		Cliente(_nombre, _ano) {
		dpi = _dpi;
	}

	void mostrardpi() {
		cout << "Su num de dpi es: " << dpi << endl;
	}
};

int main() {
	string nombre, correoElectronico;
	int ano, numCelular, dpi;

	cout << "Ingrese su nombre: ";
	cin >> nombre;
	cout << "Ingrese su edad: ";
	cin >> ano;
	if (ano >= 18) {
		cout << "Ingrese su numero de celular: ";
		cin >> numCelular;
		cout << "Ingrese su correo electronico: ";
		cin >> correoElectronico;
		cout << "Ingrese su numero de dpi: ";
		cin >> dpi;
		system("cls");

		Cliente clienteBase(nombre, ano);
		clienteBase.mostrarDatos();

		numTelefono clienteTelefono(nombre, ano, numCelular);
		correoElec clienteCorreo(nombre, ano, correoElectronico);
		DPI clienteDPI(nombre, ano, dpi);

		clienteTelefono.mostrarnumeroCelular();
		clienteCorreo.mostrarCorreoElec();
		clienteDPI.mostrardpi();
	}
	else {
		system("cls");
		cout << "Usted es menor de edad regrese cuando sea mayor.";
	}


	return 0;
}