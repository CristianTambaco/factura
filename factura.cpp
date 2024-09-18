#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

string encabezado() {
    string nombre, ruc, fecha;
    ostringstream encabezado;

    cout << "Ingrese nombre: "; getline(cin, nombre);
    cout << "Ingrese ruc: "; cin >> ruc;
    cout << "Ingrese fecha: "; cin >> fecha;
    cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
    encabezado << "\n--------------------------------"
        << "\n          FACTURA"
        << "\n--------------------------------"
        << "\nN.- de factura   001"
        << "\nFecha de emision: " << fecha
        << "\n--------------------------------"
        << "\n       DATOS DEL CLIENTE"
        << "\n--------------------------------"
        << "\nNombre: " << nombre
        << "\nRUC: " << ruc
        << "\n--------------------------------";

    return encabezado.str();
}

string detalle() {
    int cantidad;
    string detalle;
    double precio;
    ostringstream cadena;
    cout << "Ingrese cantidad: "; cin >> cantidad;
    cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
    cout << "Ingrese detalle (producto): "; getline(cin, detalle);
    cout << "Ingrese precio: "; cin >> precio;
    cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
    cadena << cantidad << " " << detalle << " $" << precio;
    return cadena.str();
}

vector<string> detalles_factura() {
    vector<string> detalles;
    bool opcion = true;
    ostringstream aux;
    aux << "\n    DETALLE DE LA FACTURA  "
        << "\n---------------------------";
    detalles.push_back(aux.str());
    int contador = 0;
    while (opcion) {
        detalles.push_back(detalle());
        cout << "Desea ingresar otro detalle (producto), presione (1): si o (0): no? "; cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
        contador++;
    }
    return detalles;
}

int main() {
    string factura = encabezado();
    vector<string> detalles = detalles_factura();
    double subtotal[10] = {0}; // Inicializar el arreglo a 0
    double suma = 0;
    int k = 0;
    cout << factura << endl;
    for (size_t i = 0; i < detalles.size(); i++) {
        cout << detalles[i] << endl;
        size_t pos = detalles[i].find("$");
        string aux = detalles[i].substr(pos + 1);
        size_t pos1 = detalles[i].find(" ");
        string cant = detalles[i].substr(0, pos1);
        subtotal[k] = atof(cant.c_str()) * atof(aux.c_str());
        k++;
    }
    for (int z = 0; z < k; z++) { // Solo iterar hasta k, que representa el número de elementos en subtotal
        suma += subtotal[z];
    }
    cout << "\n----------------------------" << endl;
    cout << "Subtotal:    " << suma << endl;
    cout << "IVA:         " << suma * 0.15 << endl;
    cout << "Total a pagar: " << suma * 1.15 << endl;

    return 0;
}


