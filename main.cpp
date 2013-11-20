//
//  main.cpp
//  AjusteDeCurvas
//
//  Created by Gustavo Ferrufino on 11/20/13.
//  Copyright (c) 2013 Gustavo Ferrufino. All rights reserved.
//

#include <iostream>
using namespace std;

int datos, matriz[10][2], matrizRecta[2][3], matrizAjuste[10][10], grado, sumX=0, sumY=0, sumX2=0, sumXY=0, pivAct, pivAnt=1;
bool despl = true;
bool unica = true;

//void cambiarRenglon(int temp, int a){
//
//    int arr[10];
//
//    for (int i =0; i<datos+1; i++) {
//
//        arr[i] = matrizRecta[a][i];
//
//        matrizRecta[a][i] = matrizRecta[temp][i];
//
//        matrizRecta[temp][i] = arr[i];
//    }
//    pivAct= matrizRecta[a][a];
//    //desplegar();
//}
//
//
//
//bool checaArriba(int p){
//	if (p != 0) {
//		return true;
//	}
//	return false;
//}
//bool checaAbajo(int p) {
//	if (p <= datos - 1) {
//		return true;
//	}
//	return false;
//}
//void montanteCuarto(int p){
//	int b = 1;
//	int a = 1;
//	int i = p + 1;
//	int j = p + 1;
//    //cout<<"DEBUG:: Entra opercion Montante Cuarto"<<endl;
//	while(i < datos) {
//		while(j < datos+1) {
//			matrizRecta[p + b][p + a] = (matrizRecta[p][p] * matrizRecta[p + b][p + a] - matrizRecta[p + b][p] * matrizRecta[p][p + a]) / pivAnt;
//			a++;
//			j++;
//		}
//		j = p + 1;
//		b++;
//		a = 1;
//		i++;
//	}
//
//	int h = p + 1;
//	while(h < datos){
//		matrizRecta[h][p] = 0;
//		h++;
//	}
//
//}
//void montantePrimer(int p) {
//	int f = 1;
//	int g = 1;
//	int b = p + 1;
//
//    //cout<<"DEBUG:: Entra opercion Montante Primer"<<endl;
//    for(int i = 0; i < p; i++){
//		matrizRecta[i][i] = pivAct;
//
//	}
//
//
//	for(int i = 0; i < p; i++){
//		while(b < datos + 1){
//
//			matrizRecta[p - f][p + g] = ((matrizRecta[p][p] * matrizRecta[p -f][p + g]) - (matrizRecta[p - f][p] * matrizRecta[p][p + g])) / pivAnt;
//			g++;
//			b++;
//
//		}
//		b = p + 1;
//		g = 1;
//		f++;
//
//	}
//
//	for(int i = 0; i < p; i++){
//
//		matrizRecta[i][p] = 0;
//	}
//
//}
//void respuesta(){
//    int cont=0;
//    int x1,x2;
//    //cout<< "DEBUG:: RESPUESTA:";
//    for (int i = 0; i<datos; i++) {
//        x2=matrizRecta[cont][i];
//        x1=matrizRecta[cont][datos];
//        cout  << x1 << "/" << x2 << " ";
//        cont+=1;
//    }
//    cout<<endl;
//}
//
//void montante(){
//
//    //cout<<"DEBUG:: Entra opercion Montante"<<endl;
//int x;
//bool check=false;
//
//
//    for (int p = 0; p < datos; p++)
//    {
//        pivAct = matrizRecta[p][p];
//
//        x=p+1;
//        if (pivAct == 0) {
//            while (x<datos && check == false) {
//                if (matrizRecta[x][p] !=0) {
//                    cambiarRenglon(x,p);
//                    check = true;
//
//
//                }
//                x++;
//            }
//
//
//        }
//
//        if (matrizRecta[p][p] == 0) {
//            cout<<"NO UNICA"<<endl;
//            pivAnt=1;
//            despl=false;
//			unica = false;
//            break;
//        }
//        else{
//
//        if(checaAbajo(p)){
//            montanteCuarto(p);
//        }
//
//        if(checaArriba(p)){
//            montantePrimer(p);
//        }
//        pivAnt = pivAct;
//        }
//
//    }
//
//    if (matrizRecta[datos-1][datos-1] == 0 && unica) {
//        cout<<"NO UNICA"<<endl;
//        despl=false;
//
//    }
//    else if(despl) {
//
//		respuesta();
//    }
//
//    unica = true;
//
//}

void Recta() {
	for(int i=0; i<datos; i++) {
		sumX+=matriz[i][0];
		sumY+=matriz[i][1];
		sumX2+=matriz[i][0]*matriz[i][0];
		sumXY+=matriz[i][0]*matriz[i][1];
	}
	matrizRecta[0][0]=datos;
	matrizRecta[0][1]=sumX;
	matrizRecta[0][2]=sumY;
	matrizRecta[1][0]=sumX;
	matrizRecta[1][1]=sumX2;
	matrizRecta[1][1]=sumXY;
	
	//montante();
}

void Ajuste(){
	int a = 0;
	for(int i=0; i<grado; i++){
        
		for(int r=grado+1-a; r>0; r--){
			for(int c=0; c<grado+2-a; c++){
				//matrizAjuste[r][c] =
			}
		}
	}
}


int main() {
	
	cout<<"Ingrese la cantidad de datos a ajustar: ";
	cin>>datos;
	cout<<"Ingrese los pares de numeros"<<endl;
	
	for(int i=0; i<datos; i++) {
		
		for(int j=0; j<2; j++) {
			cin>>matriz[i][j];
		}
	}
    
	cout<<"Hasta que grado del polinomio quiere ajustar?: ";
	cin>>grado;
    
	Recta();
    
	cout<<sumX<<", "<<sumY<<", "<<sumX2<<", "<<sumXY;
	
	
	return 0;
}
