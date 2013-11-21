//
//  main.cpp
//  AjusteDeCurvas
//
//  Created by Gustavo Ferrufino on 11/20/13.
//  Copyright (c) 2013 Gustavo Ferrufino. All rights reserved.
//

#include <iostream>
using namespace std;

int datos, matrixSums[50][50] , grado, sumPotX[20], sumPotxY[20], x[50],y[50], sumY, matrixMontante[50][50];
int potX[50], matrixQ;
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
    
    
    for (int renglon=0; renglon<=grado; renglon++) {
        
        for (int colum=0; colum<=grado; colum++) {
            
            matrixSums[renglon][colum]=sumPotX[colum+i];
            
            
        }
        i+=1;
    }
    /*
    for (int i= 0; i<datos; i++) {
        matrixSums[i][datos]=sumPotxY[i];
    }
     */
    
}
void desplegarMatrix(){

    for (int i=0; i<grado+1; i++) {
        for (int j=0; j<=grado; j++) {
            cout<<matrixSums[i][j]<<" ";
            //cout<<matrixMontante[i][j]<<" ";
        }
        cout<<endl;
    }

}
void findQ(){

//tener una variable que defina el grado de cada ecuacion que estoy operando
// osea una relacion entre unos valores de un renglon de matrixEcuations con lo que vendriera hacer su ecuacion

//cada a, b, c, .. n-1,n serian representados como a + bx +cx^2...

    //entonces seria un for que por cada renglon en matrixQ, entra en otro for que suma la funcion del renglon de matrixEcuations multiplicado o sumado, para luego ser restado por yi del mismo nivel de xi. Para así, finalmente ser elevado al cuadrado. esto se guarda en una matrizSol que es de los renglones necesarios pero una sola columna.
    
    //busco el dato menor.. ya esta.


}

int main() {
	
   
	cout<<"Ingrese la cantidad de datos a ajustar: ";
	cin>>datos;
	cout<<"Ingrese los pares de numeros de [x,y]"<<endl;
	int n=datos;
	for(int i=0; i<datos; i++) {
		cin>>x[i];
        cin>>y[i];
		
	}
     setup();
    // desplegar();
	cout<<"Hasta que grado del polinomio quiere ajustar?: ";
	cin>>grado;
    int d=grado;
    
    Modelacion();
   
    implementIntoMatrix();
 
    // while (n > 0) {
        for (int r=0; r<n; r++) {
            for (int c=0; c<n+2; c++) {
                matrixMontante[r][c]= matrixSums[r][c];
            }
        }
        
        desplegarMatrix();
        //Hago Montante aqui
        //guardo ecuacion en una tercera matriz, llamada matrixEcuations
        
   //     n-=1;
   // }
    
    findQ(); //Q=sum of r^2 = sum of all (f(x)-yi)^2
    //hago Q
    
	return 0;
}
