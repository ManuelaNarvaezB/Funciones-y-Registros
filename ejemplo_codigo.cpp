#include <iostream>
#include <string>

using namespace std;

// 1. DEFINICIÓN DEL REGISTRO (STRUCT)
// Agrupa variables de diferentes tipos bajo un mismo nombre
struct Estudiante {
    string nombre;
    int edad;
    float notaFinal;
};

// 2. PROTOTIPOS DE FUNCIONES
// Paso por referencia (&): permite modificar los datos originales del arreglo
void ingresarGrupo(Estudiante grupo[], int cantidad);

// Paso por referencia constante (const &): lee datos sin duplicar memoria ni alterarlos
void mostrarEstudiante(const Estudiante &e);
void mostrarReporte(const Estudiante grupo[], int cantidad);

// Funciones con retorno y paso por valor
bool estaAprobado(float nota);
float calcularPromedio(const Estudiante grupo[], int cantidad);

int main() {
    const int MAX_ESTUDIANTES = 50; // Capacidad máxima (como sugiere el documento)
    Estudiante curso[MAX_ESTUDIANTES];
    int n;

    cout << "--- SISTEMA DE GESTION DE ESTUDIANTES ---" << endl;
    cout << "Ingrese la cantidad de estudiantes (max " << MAX_ESTUDIANTES << "): ";
    cin >> n;

    // Validación básica
    if (n <= 0 || n > MAX_ESTUDIANTES) {
        cout << "Cantidad no valida." << endl;
        return 1;
    }

    // Llamada a funciones modulares
    ingresarGrupo(curso, n);
    mostrarReporte(curso, n);

    return 0;
}

// 3. IMPLEMENTACIÓN DE FUNCIONES

// Función sin retorno (void) que modifica los registros mediante referencia (&)
void ingresarGrupo(Estudiante grupo[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "\n--- Datos del Estudiante #" << (i + 1) << " ---" << endl;
        cin.ignore(); // Limpia el buffer antes de usar getline
        cout << "Nombre: ";
        getline(cin, grupo[i].nombre);
        cout << "Edad: ";
        cin >> grupo[i].edad;
        cout << "Nota Final (0.0 - 5.0): ";
        cin >> grupo[i].notaFinal;
    }
}

// Función con retorno (bool) y paso por valor
bool estaAprobado(float nota) {
    return nota >= 3.0;
}

// Función sin retorno (void) con paso por referencia constante (const &)
void mostrarEstudiante(const Estudiante &e) {
    cout << "Nombre: " << e.nombre 
         << " | Edad: " << e.edad << " anos"
         << " | Nota: " << e.notaFinal 
         << " | Estado: " << (estaAprobado(e.notaFinal) ? "APROBADO" : "REPROBADO") << endl;
}

// Función con retorno (float) que procesa el arreglo de registros
float calcularPromedio(const Estudiante grupo[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += grupo[i].notaFinal;
    }
    return suma / cantidad;
}

// Función sin retorno (void) que integra las demás funciones para el reporte
void mostrarReporte(const Estudiante grupo[], int cantidad) {
    cout << "\n=========================================" << endl;
    cout << "           REPORTE DEL CURSO             " << endl;
    cout << "=========================================" << endl;
    
    for (int i = 0; i < cantidad; i++) {
        mostrarEstudiante(grupo[i]);
    }
    
    cout << "-----------------------------------------" << endl;
    cout << "Promedio general del grupo: " << calcularPromedio(grupo, cantidad) << endl;
    cout << "=========================================" << endl;
}