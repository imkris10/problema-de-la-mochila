#include <iostream>

using namespace std;

struct mochila {
	float valor; // este es el precio del objeto
	float peso; // peso del objeto
	float indice; // indice del objeto => valor/peso
};

int main () {
	
	int n,i,max,j,cont;
	float wmax,valmax=0;
	
	cout<<"Ingresa el numero de elementos en la mochila: ";
	cin>>n;
	mochila elemento[n], aux;
	
	cout<<"\n Ingresa los elemento de la mochila: \n";
	
	for (i=0;i<n;i++) {
		cout<<"Valor del elemento "<<i+1<<": $";
		cin>>elemento[i].valor;
		cout<<"Peso del elemento "<<i+1<<": ";
		cin>>elemento[i].peso;
		elemento[i].indice=elemento[i].indice=elemento[i].valor/elemento[i].peso;  //método para calcular el indice de cada objeto
	}
	
	// ordenamos los objetos de mayor a menor según sus indices
	
	for (i=0;i<n;i++) { // podemos usar cualquier algoritmo de ordenamiento
	    max=i;
	    for (j=i+1;j<n;j++) {
	    	if (elemento[j].indice>elemento[max].indice) {
	    		max=j;
			}
			cont++;
		}
		aux=elemento[i];
		elemento[i]=elemento[max];
		elemento[max]=aux; 
	}
	
	cout<<endl;
	
	// verificamos que los objetos se han ordenado de mayor a menor indice
	
	for (i=0;i<n;i++) {
		cout<<"Objeto "<<i+1<<": ";
		cout<<"El indice es de "<<elemento[i].indice<<", ";
		cout<<"el peso es de "<<elemento[i].peso<<" kg y ";
		cout<<"el valor es de $"<<elemento[i].valor<<endl;
	}
	
	cout<<endl;
	
	cout<<"Cual es el peso maximo de la mochila?: \n";
	cin>>wmax;
	
	// ingresamos los objetos dentro de la mochila
	
	i=0;
	while (wmax>0) {
		if (wmax>elemento[i].peso) {
			wmax=wmax-elemento[i].peso;
			valmax=valmax+elemento[i].valor;
		}
		else {
			valmax=valmax+(elemento[i].valor*(wmax/elemento[i].peso));
			wmax=0;
		}
		i++;	
	}
	
	cout<<"\n El valor maximo de que podemos llevar en la mochila es: $"<<valmax;
}
