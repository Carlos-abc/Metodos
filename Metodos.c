/*Realizar un programa en C que resuelva el método de Bisección para estimar la raíz de la
función f(x) = e^x - 3x^2, considerando los siguientes intervalos [0.5,1], [-2,0] y una tolerancia
del error relativo porcentual del 0.5 %, en ambos casos. Nota: El programa no solicitará datos
de entrada al usuario, así mismo deberá imprimir la tabla de cálculos como en la siguiente imagen
y al finalizar el número de iteraciones que se realizaron y la raíz aproximada. El código deber
tener comentarios donde se expliquen las operaciones importantes.*/

/*El método de bisección se usa para encontrar la raíz de una función f(x) = 0 la cual se encuentra
entre un intervalo [Xl, Xu]. Se empieza asignando los valores iniciales (Xl, Xu). el punto medio del
intervalo se define como Xr. la cual será la primera estimación de la solución numérica. Si la
solución obtenida no es suficientemente precisa, se define un nuevo intervalo si f(Xl) * f(Xr) <
0 la raíz se encuentra en el subintervalo inferior o izquierdo por lo tanto Xu = Xr, si f(Xl) *
f(Xr) > 0 la raíz se encuentra en el subintervalo superior o derecho por lo tanto Xl = Xr, o si
f(Xl) * f(Xr) = 0 el método encuentra la solución*/

#include<stdio.h>
#include<math.h>

void Calcular(float, float, float, float, float);
float evaluacion(float);

int main(){
	
	
	printf("METODO DE BISECCION para f(x) = e^x - 3x^2");
	
	
	printf("\n\nIteracion |  Xl       |     Xu   |         Xr      |   Ea");
	printf("\n -------------------------------------------------------------");
	
	Calcular(0.5, 1.0, 0.0, 0.0,0.0); // Intervalo de [ 0.5 ,1 ]
	printf("\n");
	
	printf("\n\nIteracion |    Xl     |     Xu      |      Xr      |       Ea");
	printf("\n ------------------------------------------------------------------");
	
	Calcular(-2.0, 0.0, 0.0, 0.0,0.0); // Intervalo de [ -2 ,0 ]
	
	
	return 0;
}
// Funcion que hace los calculos e imprime valores
void Calcular(float Xl, float Xu, float Xr, float XrAnterior, float Ea){
	
	int i = 0;
	
	do{
		
		i++; // Va aumentando las iteraciones
		
		
		//Comprobacion de Xl * Xr
		if(evaluacion(Xl) * evaluacion(Xr) < 0){
			
			Xu = Xr;
		} 
		else if(evaluacion(Xl) * evaluacion(Xr) > 0){
			
			Xl = Xr;
			
		} else{
			
			Ea = 0;
		}
		
		
		XrAnterior = Xr; //Guarda el valor de Xr anterior en Xr, para determinar el Ea
		
		Xr = (Xl + Xu)/2; 
		
		Ea = fabs((Xr - XrAnterior)/Xr) * 100; //Determina el Ea
		
		
		//if para el acomodo en la impresion de los datos
		if(i < 10){
			
			printf("\n   %d        %.5f      %.5f       %.5f      %.5f",i,Xl,Xu,Xr,Ea);
			
		}else printf("\n  %d        %.5f      %.5f       %.5f      %.5f",i,Xl,Xu,Xr,Ea);
			
		
	}while(Ea > 0.5); //Sale del ciclo hasta que Ea sea menor que 0.5%
	
	}

//Funcion que evalua f(x) = e^x - 3x^2
float evaluacion(float x){
		
		float resultado;
		
		resultado = exp(x) - 3*pow(x,2);
		
		return resultado;
		
	}
