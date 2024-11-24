#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
    double x;
    double y;
};

float distancia_entre_puntos(Punto p1, Punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    float xmax, ymax, distancia_max = 0;
    float xmin = 0, ymin = 0;
    int n, all, cuadrante;

    cout << "CUADRANTES: 1(x,y)  2(-x,y)  3(-x,-y)  4(x,-y)\n";
    cout << "Ingrese el cuadrante (1-4): ";
    cin >> cuadrante;

    cout << "Ingrese el limite del cuadrante:\n";
    cout << "Coordenada en x: ";
    cin >> xmax;
    cout << "Coordenada en y: ";
    cin >> ymax;

    if (cuadrante == 1) {
        xmin = 0; ymin = 0;
    } else if (cuadrante == 2) {
        xmin = xmax; ymin = 0; xmax= abs(xmax);
    } else if (cuadrante == 3) {
        xmin = -xmax; ymin = -ymax;
    } else if (cuadrante == 4) {
        xmin = 0; ymin = -ymax;
    } else {
        cout << "Cuadrante no valido.\n";
        return 1;
    }

    cout << "Ingrese el numero de puntos: ";
    cin >> n;
    Punto puntos[n];

    for (int i = 0; i < n; ++i) {
        cout << "Ingrese el punto " << i + 1 << ":\n";
        cout << "Coordenada en x: ";
        cin >> puntos[i].x;
        cout << "Coordenada en y: ";
        cin >> puntos[i].y;
    }

    cout << "Ingrese el indice del punto para calcular su distancia a los demas puntos ";
    cin >> all;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (puntos[i].x >= xmin && puntos[i].x <= xmax && puntos[i].y >= ymin && puntos[i].y <= ymax && puntos[j].x >= xmin && puntos[j].x <= xmax && puntos[j].y >= ymin && puntos[j].y <= ymax) {
                float distancia = distancia_entre_puntos(puntos[i], puntos[j]);
                if (distancia > distancia_max) {
                    distancia_max = distancia;
                }
            }
        }
    }

    if (distancia_max > 0) {
        cout << "La mayor distancia entre dos puntos dentro del limite del cuadrante es: " << distancia_max << endl;
    } else {
        cout << "No se encontraron puntos dentro del cuadrante.\n";
    }
    cout << endl;
    cout << "Distancias desde el punto " << all << " al resto de puntos:\n";
    for (int i = 0; i < n; i++) {
        if (i != (all - 1) && puntos[i].x >= xmin && puntos[i].x <= xmax && puntos[i].y >= ymin && puntos[i].y <= ymax) {
            float distancia = distancia_entre_puntos(puntos[all - 1], puntos[i]);
            cout << "Distancia al punto (" << puntos[i].x << ", " << puntos[i].y << "): " << distancia << endl;
        }
    }


    return 0;
}