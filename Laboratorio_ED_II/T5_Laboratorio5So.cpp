#include<iostream>
#include <ctime>
#include<cstdlib>
#include <cmath>

using namespace std;

typedef int entero;

struct coord{
    int x, y;
};

coord inicializa_punto1(){
    coord t0;
    t0.x = rand()%1024;
    t0.y = rand()%768;
    return t0;
}

coord inicializa_punto2(int x, int y){
    coord t0;
    t0.x = x;
    t0.y = y;
    return t0;
}

float distancia(coord pt1, coord pt2){
    float a, b, c;

    a = pt1.x-pt2.x;
    b = pt1.y-pt2.y;
    c = sqrt((a*a) + (b*b));
    return c;
}


int main(){
    coord pt1, pt2;
    srand((unsigned)time(0));

    pt1 = inicializa_punto1();
    pt2 = inicializa_punto2(40,40);

    cout<< " pt1.x=" << pt1.x << " pt1y=" << pt1.y << endl;
    entero x,y;
    x = pt2.x;
    y = pt2.y;
    cout << " pt2.x=" << x << " pt2.y=" << y << endl;

    float c;
    cout<<"Distancia entre puntos: "<<endl;
    c = distancia(pt1, pt2);
    cout<<c;

    return 0;

}
