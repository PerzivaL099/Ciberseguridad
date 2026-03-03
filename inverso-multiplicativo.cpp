#include <iostream>
#include <iomanip>

using namespace std;

// Estructura para devolver múltiples valores del algoritmo extendido
struct Resultado {
    long long gcd;
    long long x;
    long long y;
};

// Función que realiza el Algoritmo de Euclides Extendido con traza
Resultado euclidesExtendido(long long a, long long m) {
    long long x = 0, y = 1, lastx = 1, lasty = 0;
    long long r = m, lastr = a;
    long long q, temp;

    cout << "\n--- Iniciando Procedimiento de Euclides ---\n";
    cout << left << setw(10) << "Cociente" << setw(10) << "Residuo" 
         << setw(10) << "x" << setw(10) << "y" << endl;

    while (r != 0) {
        q = lastr / r;

        // Guardar valores anteriores para el cálculo
        temp = r;
        r = lastr % r;
        lastr = temp;

        temp = x;
        x = lastx - q * x;
        lastx = temp;

        temp = y;
        y = lasty - q * y;
        lasty = temp;

        // Mostrar el paso actual
        cout << left << setw(10) << q << setw(10) << lastr 
             << setw(10) << lastx << setw(10) << lasty << endl;
    }

    return {lastr, lastx, lasty};
}

void resolverInverso(long long a_original, long long m) {
    cout << "\n========================================" << endl;
    cout << "Ejercicio: " << a_original << "x \u2261 1 mod " << m << endl;

    // 1. Obtener representante canónico
    long long a = a_original % m;
    if (a < 0) a += m; 

    cout << "Representante canonico: " << a << endl;

    // 2. Ejecutar Algoritmo
    Resultado res = euclidesExtendido(a, m);

    // 3. Verificar y Desplegar Resultado
    if (res.gcd != 1) {
        cout << "\nRESULTADO: No existe inverso multiplicativo ya que el MCD(" 
             << a << ", " << m << ") = " << res.gcd << " (distinto de 1)." << endl;
    } else {
        // Asegurarse de que el inverso sea positivo
        long long inverso = (res.x % m + m) % m;
        cout << "\nRESULTADO:" << endl;
        cout << "MCD: " << res.gcd << endl;
        cout << "Coeficiente x (inverso): " << res.x << endl;
        cout << "Inverso multiplicativo final: " << inverso << endl;
        cout << "Comprobacion: (" << a << " * " << inverso << ") mod " << m 
             << " = " << (a * inverso) % m << endl;
    }
}

int main() {
    // Ejemplos de la imagen
    resolverInverso(23, 7);
    resolverInverso(17, 43);
    resolverInverso(221, 26);  
    resolverInverso(785, 43);

    return 0;
}