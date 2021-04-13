#include <iostream>
#include<stdlib.h>
#include <fstream>

using namespace std;

int main(){

	int V[5];
	ifstream fe;
	
	fe.open("D:\\hola.txt");
	
	for(int i=0; i<5; i++){
		fe >> V[i];
	}
	
	fe.close();
	
	for(int i=0; i<5; i++){
		cout << V[i]<<" "<<endl;
	}

	system("PAUSE");
}
/*
int main(){

	int V[4,5,5,2,3];
    ofstream fe;
    fe.open("D:\\hola1.txt");

    for(int i=0; i<5; i++){
		fe << V[i]<<endl;
	}

	fe.close();

	system("PAUSE");
}
*/
