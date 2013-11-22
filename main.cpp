//
//  main.cpp
//  AjusteDeCurvas
//
//  Created by Gustavo Ferrufino on 11/20/13.
//  Copyright (c) 2013 Gustavo Ferrufino. All rights reserved.
//


#include <iostream>
#include <math.h>

using namespace std;
int datos, matrixSums[50][50] , grado, sumPotX[20], sumPotxY[20], x[50],y[50], sumY, matrixMontante[50][50];
int potX[50], matrixQ, pivAct, pivAnt = 1, renEc = 0, colEc = 0, d, contI = 1, contError2;
double matrixEc[10][10], num, num2, Errores[10], sumaError = 0, mejor = 100000000;
bool despl = true, unica = true;
int posNounica;
string NoUnicaAns;
bool noUnica=false;
void cambiarRenglon(int temp, int a){
    
    int arr[10];
    
    for (int i =0; i<=d; i++) {
        
        arr[i] = matrixMontante[a][i];
        
        matrixMontante[a][i] = matrixMontante[temp][i];
        
        matrixMontante[temp][i] = arr[i];
    }
    pivAct= matrixMontante[a][a];
    //desplegar();
}
bool checaArriba(int p){
	if (p != 0) {
		return true;
	}
	return false;
}
bool checaAbajo(int p) {
	if (p <= d+1 - 1) {
		return true;
	}
	return false;
}
void montanteCuarto(int p){
	int b = 1;
	int a = 1;
	int i = p + 1;
	int j = p + 1;
    //cout<<"DEBUG:: Entra opercion Montante Cuarto"<<endl;
	while(i < d+1) {
		while(j < d+1+1) {
			matrixMontante[p + b][p + a] = (matrixMontante[p][p] * matrixMontante[p + b][p + a] - matrixMontante[p + b][p] * matrixMontante[p][p + a]) / pivAnt;
			a++;
			j++;
		}
		j = p + 1;
		b++;
		a = 1;
		i++;
	}
	
	int h = p + 1;
	while(h < d+1){
		matrixMontante[h][p] = 0;
		h++;
	}
	
}
void montantePrimer(int p) {
	int f = 1;
	int g = 1;
	int b = p + 1;
	
    //cout<<"DEBUG:: Entra opercion Montante Primer"<<endl;
    for(int i = 0; i < p; i++){
		matrixMontante[i][i] = pivAct;
		
	}
    
    
	for(int i = 0; i < p; i++){
		while(b < d+1 + 1){
            
			matrixMontante[p - f][p + g] = ((matrixMontante[p][p] * matrixMontante[p -f][p + g]) - (matrixMontante[p - f][p] * matrixMontante[p][p + g])) / pivAnt;
			g++;
			b++;
			
		}
		b = p + 1;
		g = 1;
		f++;
        
	}
    
	for(int i = 0; i < p; i++){
		
		matrixMontante[i][p] = 0;
	}
    
}
void respuesta(){
    int cont=0;
    int x1,x2;
    //cout<< "DEBUG:: RESPUESTA:";
    
    for (int i = 0; i<d+1; i++) {
        x2=matrixMontante[cont][i];
        x1=matrixMontante[cont][d+1];
		num=x1*1.0;
		num2=x2*1.0;
		matrixEc[renEc][colEc] = num/num2;
		colEc++;
        //cout  << x1 << "/" << x2 << " ";
        cont+=1;
    }
	colEc = 0;
	renEc++;
    cout<<endl;
}
void montante(){
    
    //cout<<"DEBUG:: Entra opercion Montante"<<endl;
    int x;
    bool check=false;
    
    
    for (int p = 0; p < d+1; p++)
    {
        pivAct = matrixMontante[p][p];
        
        x=p+1;
        if (pivAct == 0) {
            while (x<d+1 && check == false) {
                if (matrixMontante[x][p] !=0) {
                    cambiarRenglon(x,p);
                    check = true;
                    
                    
                }
                x++;
            }
            
            
        }
        
        if (matrixMontante[p][p] == 0) {
            noUnica=true;
            posNounica=d;
            pivAnt=1;
            //despl=false;
			unica = false;
            break;
        }
        else{
            
            if(checaAbajo(p)){
                montanteCuarto(p);
            }
            
            if(checaArriba(p)){
                montantePrimer(p);
            }
            pivAnt = pivAct;
        }
        
    }
    
    if (matrixMontante[d][d] == 0 && unica) {
        noUnica=true;
        //despl=false;
        
    }
    else if(despl) {
        
		respuesta();
    }
    
    unica = true;
    
}
void setup(){
    for (int i=0; i<10; i++) {
        sumPotX[i]=0;
        potX[i]=1;
        sumY+=y[i];
    }
}
void desplegar(){
    for (int i=0; i<d+1; i++) {
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
    
    for (int i= 0; i<=grado; i++) {
        matrixSums[i][grado+1]=sumPotxY[i];
    }
    
    
}
void desplegarMatrix(){
    for (int i=0; i<grado+1; i++) {
        for (int j=0; j<=grado+1; j++) {
            //cout<<matrixSums[i][j]<<" ";
            cout<<matrixMontante[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Ecuaciones(){
	int a = 1;
  
    
	for(int i = grado - 1; i >= 0; i--){
        
        cout<<"P("<<a<<") = ";
        
      
        for(int j = 0; j < grado + 1; j++){
            if(matrixEc[i][j] != 0){
                
                cout<<matrixEc[i][j];
            }
            if(j != 0 && matrixEc[i][j] != 0){
                cout<<"x"<<j;
            }
            if(matrixEc[i][j + 1] < 0){
                cout<<" ";
            }
            if(matrixEc[i][j + 1] != 0 && matrixEc[i][j + 1] > 0){
                cout<<" + ";
            }
       
        }
        a++;
        cout<<endl;
        }
        
    
   
    
    

}
void Error(int z){
	double error = 0, error2, a, b;
	for(int i = 0; i < datos; i++){
		for(int j = 0; j < grado + 1; j++){
			a = x[i]*1.0;
			b = j * 1.0;
			if(j == 0){
				error = error + matrixEc[z][j];
			}
			else{
				error = error + (matrixEc[z][j] * pow(a,b) );
			}
			
		}
		error2 = (error - y[i]) * (error - y[i]);
		error = 0;
		Errores[i] = error2;
	}
}
void DespliegaError(int contError){
	for(int i = 0; i < datos; i++){
		sumaError += Errores[i];
	}
	cout<<"Error del polinomio("<<contI<<") = "<<sumaError<<endl;
	contI++;
	if(sumaError<mejor){
		mejor = sumaError;
		contError2 = contError;
	}
}

int main() {
	
    bool n= true;
    bool e= false;
    char ans;
    cout<<"Bienvenido"<<endl;
    while (n == true || ans == 'e') {
	cout<<"Ingrese la cantidad de datos a ajustar: ";
	cin>>datos;
    
        cout<<"Ingrese los pares de numeros de [x,y]"<<endl;
        cout<<"X Y"<<endl;
        
        for(int i=0; i<datos; i++) {
            cin>>x[i];
            cin>>y[i];
            n=false;
        }
        for (int i=0; i<datos; i++) {
            for (int j=i+1; j<datos; j++) {
                if (x[i] == x[j]) {
                    if (y[i] != y[j]) {
                        n=true;
                        
                    }
                }
            }
        
        }
        if (n == true) {
            cout<<"No tiene solucion"<<endl;
            cout<<"Desea salir [s] o empezar nuevamente [e]? "<<endl;
            cin>>ans;
            if (ans == 's') {
                n=false;
            }
        }
        

        cout<<"Hasta que grado del polinomio quiere ajustar?: ";
        cin>>grado;
        d=grado;
        if (grado>= datos) {
            cout<<"Operacion invalida, favor de empezar devuelta"<<endl;
            n=true;
        }
    
    }
    
    if (n==false) {
        
        setup();
       
        
                Modelacion();
        
        implementIntoMatrix();
        
        
        for (int r=0; r<=d; r++) {
            for (int c=0; c<=d+1; c++) {
                matrixMontante[r][c]= matrixSums[r][c];
            }
		}
    //     desplegarMatrix();
        int contUn=0;
		while(d > 0){
			montante();
			
            contUn++;
			for (int r=0; r<=grado; r++) {
				for (int c=0; c<=grado+1; c++) {
					matrixMontante[r][c]= matrixSums[r][c];
				}
			}
			
			for (int r=0; r<=d; r++) {
				matrixMontante[r][d]= matrixMontante[r][d + contUn];
			}
			pivAnt = 1;
			d--;
		}
		
		Ecuaciones();
		int z = grado-1, contError = 1;
		for(int i = 0; i < grado; i++){
			Error(z);
			DespliegaError(contError);
			z--;
			sumaError = 0;
			contError++;
		}
		cout<<"El polinomio que mejor se ajusta es P("<<contError2<<")";
    }
    return 0;
}
