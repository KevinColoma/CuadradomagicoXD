#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
class CuboMagico{
		public:
			CuboMagico();
			CuboMagico(int **);	
			void setCuboMagicoCuadrado(int **);
			int **getCuboMagicoCuadrado();
			void mostrar(int, int);
			void llenar(int, int);
		protected:	
		private:
			int **cuadrado;
	};
CuboMagico::CuboMagico( int **_cuadrado){
	cuadrado=_cuadrado;
}
void CuboMagico::setCuboMagicoCuadrado(int **_cuadrado){
	cuadrado=_cuadrado;
}
int **CuboMagico::getCuboMagicoCuadrado(){
	return cuadrado;
}
//
void CuboMagico::llenar(int a, int b){
	
	int x=0,t=0,s=0,d=0,p=4,k=0,j=0;
	x=(b-1)/2;
	t=((a+1)/2);
	s=(a-x-1)/2;
	d=x;
	for(int g=0;g<((a+1)/2);g++){
		j=g;
		k=g;
		for(int i=x;i>=j;i--){
			*(*(cuadrado+i)+k)=p;
			if(k<(d-s)){
				*(*(cuadrado+i)+(k+t))=p;
			}
			if(k>(d+s)){
				*(*(cuadrado+i)+(k-t))=p;
			}
			if(i>(d+s)){
				*(*(cuadrado+(i-t))+k)=p;
			}
			if(i<(d-s)){
				*(*(cuadrado+(i+t))+k)=p;
			}
			k++;
			p+=4;
		}
		x++;
	}
}
void CuboMagico::mostrar(int a, int b){
	system("cls");
	int x=0,t=0,s=0;
	x=(b-1)/2;
	t=((a+1)/2);
	s=(a-x-1)/2;
	for(int g=0;g<a;g++){
		printf("\n\t");
		for(int h=0;h<b;h++){	
			if(h>=(x-s)&&h<=(x+s)&&g<=(x+s)&&g>=(x-s)){
				printf("\t%d",*(*(cuadrado+g)+h));	
			}
		}
	}
}
int main(int argc, char** argv) {
	int **cuadrado, dim,num;
	printf("Ingrese la dimension ");
	scanf("%d",&dim);
	num=2*dim-1;
	cuadrado=(int**)calloc(num,sizeof(int*));
	for(int i=0;i<num;i++){
		*(cuadrado+i)=(int *)calloc(num,sizeof(int));
	}
	CuboMagico cubo=CuboMagico(cuadrado);
	cubo.llenar(num,num);
	cubo.mostrar(num,num);
	system("pause");
	return 0;
}
