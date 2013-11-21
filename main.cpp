//
//  main.cpp
//  AjusteDeCurvas
//
//  Created by Gustavo Ferrufino on 11/20/13.
//  Copyright (c) 2013 Gustavo Ferrufino. All rights reserved.
//

#include <iostream>
using namespace std;

int datos, matrixSums[10][10] , grado, sumPotX[10], sumPotxY[10], x[50],y[50], sumY;
int potX[50];
void setup(){

    for (int i=0; i<10; i++) {
        sumPotX[i]=0;
        potX[i]=1;
        sumY+=y[i];
    }


}

void desplegar(){

    for (int i=0; i<datos; i++) {
        //cout<<x[i]<<" "; //valores de X
        //cout<<y[i]<<" "; //valores de Y
        //cout<<sumPotX[i]<<" ";
    }
    cout<<sumY;
    cout<<endl;
}

void Modelacion(){


    sumPotxY[0]=sumY;
    for (int i=0; i<=grado+datos; i++) {
        for (int j=0; j<datos; j++) {
            
            sumPotX[i]+=potX[j];
            
            potX[j]*=x[j];
            
            sumPotxY[i+1]+=(potX[j]*y[j]);
        
        }

       
    }
  

}
void implementIntoMatrix(){

    int i=0;
    
    
    for (int renglon=0; renglon<datos; renglon++) {
        
        for (int colum=0; colum<datos; colum++) {
            
            matrixSums[renglon][colum]=sumPotX[colum+i];
            
            
        }
        i+=1;
    }

    for (int i= 0; i<datos; i++) {
        matrixSums[i][datos]=sumPotxY[i];
    }
    
}
void desplegarMatrix(){

    for (int i=0; i<datos; i++) {
        for (int j=0; j<=datos; j++) {
            cout<<matrixSums[i][j]<<" ";
        }
        cout<<endl;
    }

}


int main() {
	
   
	cout<<"Ingrese la cantidad de datos a ajustar: ";
	cin>>datos;
	cout<<"Ingrese los pares de numeros de [x,y]"<<endl;
	
	for(int i=0; i<datos; i++) {
		cin>>x[i];
        cin>>y[i];
		
	}
     setup();
    // desplegar();
	cout<<"Hasta que grado del polinomio quiere ajustar?: ";
	cin>>grado;
    
    Modelacion();
   
    implementIntoMatrix();
    desplegarMatrix();
    
	return 0;
}
