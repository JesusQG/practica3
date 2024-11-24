#include<iostream>
#include<math.h>
using namespace std;

struct Punto{
    float x;
    float y;
};
struct ecuacion_recta{
    float pendiente;
    float b;
};
void colineales(Punto a, Punto b, Punto c);
void colineales_n(Punto a[], int n);
int main(){
    int n;
    cout<<"Cuantos puntos desea ingresar:"<<endl;
    cin>>n;
    Punto p[n];
    for(int i=0; i<n; i++){
        cout<<"PUNTO "<<i<<endl;
        cout<<"Ingrese la coordenada x: "<<endl;
        cin>>p[i].x;
        cout<<"Ingrese la coordenada y: "<<endl;
        cin>>p[i].y;
    } 
    cout<<"\nCuadrantes:\n";
    for (int i=0; i<n; i++){
        cout<<"PUNTO "<<i<<":";
        if(p[i].x==0 && p[i].y!=0){
            cout<<" se encuentra en el eje Y";
        }
        if(p[i].x!=0 && p[i].y==0){
            cout<<" se encuentra en el eje X";
        }
        if(p[i].x>0 && p[i].y>0){
            cout<<" se encuentra en el cuadrante I ";
        }
        if(p[i].x<0 && p[i].y>0){
            cout<<" se encuentra en el cuadrante II";
        }
        if(p[i].x<0 && p[i].y<0){
            cout<<" se encuentra en el cuadrante III";
        }
         if(p[i].x>0 && p[i].y<0){
            cout<<" se encuentra en el cuadrante IV";
        }
        if(p[i].x==0 && p[i].y==0){
            cout<<" se encuentra en el origen";
        }   
        cout<<endl;
    }
    
    if (n==2){
        float pendiente,b;
        pendiente= (p[1].y - p[0].y)/(p[1].x - p[0].x);
        b = p[1].y-pendiente*p[1].x;
        cout<<"La ecuacion de la linea que pasa por los dos puntos es: Y = "<<pendiente<<"x + "<<b;
    }
    if (n==3){
        colineales(p[0],p[1],p[2]);
    } else {
        colineales_n(p,n);
    }
}

void colineales(Punto a, Punto b, Punto c){
    float distab, distbc, distotal;
    distab = sqrt(pow((b.x - a.x),2) + pow((b.y - a.y),2));
    distbc = sqrt(pow((c.x - b.x),2) + pow((c.y - b.y),2));
    distotal = sqrt(pow((c.x - a.x),2) + pow((c.y - a.y),2));
    if (distab + distbc == distotal){
        float pendiente,d;
        pendiente = (b.y - a.y)/(b.x - a.x);
        d = b.y-pendiente*b.x;
        cout<<"La ecuacion de la linea que pasa por los puntos es: Y = "<<pendiente<<"*X + "<<d;
    } else {
        cout<<"Las coordenadas no son colineales";
    }
}

void colineales_n(Punto a[], int n) {
    float pendientes[n];
    float cortes_en_y[n];
    for (int i = 0; i < n - 1; i++) {
        pendientes[i] = (a[i + 1].y - a[i].y) / (a[i + 1].x - a[i].x);
        cortes_en_y[i] = a[i].y - pendientes[i] * a[i].x;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (pendientes[i] == pendientes[j] && cortes_en_y[i] == cortes_en_y[j]) {
                cout << "Los puntos " << i << ", " << i + 1   << " y " << j + 1 << " son colineales." << "Ecuacion de la recta: " << "Y = " << pendientes[i]<<"x + "<<cortes_en_y[i];
                cout<<endl;
            }
        }
    }
}