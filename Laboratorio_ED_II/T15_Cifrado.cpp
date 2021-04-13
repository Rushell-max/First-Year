/*//////////////   CIFRADO  //////////////////////////////
    
    Trabajo presentado por:

        -RUSHELL VANESSA ZAVALAGA OROZCO 
  
*/

#include <iostream>

using namespace std;

void euclides(int a, int b){
    int u = 1, d = a, v1 = 0, v3 = b;
    while(v3 > 0){
        int q = d/v3;
        int t3 = d%v3;
        int t1 = u-q*v1;
        u = v1;
        d = v3;
        v1 = t1;
        v3 = t3;
    }
    int v = (d-u*a)/b;
    cout<<u<<" "<<v<<" "<<d<<endl;
}

int main(){
    int n1, n2;
    cout<<" 1: ";cin>>n1;
    cout<<" 2: ";cin>>n2;
    euclides(n1,n2);
}