#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

/* prototipos de funcoes */
int generate_numbers(int upper,int lower);
void bubble_sort(int a[], int n);
void conta_frequencia(int a[],int upper,int lower,int step, int tamanho);

int main()
{
    srand(time(0));
    int upper = 255;
    //int upper = 16;
    int lower = 0;
    int upperInterval = 31;
    int lowerInterval = 0;
    int step = 32;
    int multiplicador = 1;
    int nNumeros = 2560*multiplicador;
    //int nNumeros = 16*multiplicador;
    int numeros[nNumeros];
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;

   // printf("teste");


    for (i = 0; i < nNumeros; i++)
    {
        
        numeros[i] = generate_numbers(upper,lower);
        //printf("%d\n",numeros[i]);


    }

    bubble_sort(numeros,sizeof(numeros)/sizeof(numeros[0]));

        for (i = 0; i < nNumeros; i++)
    {

        //printf("%d\n",numeros[i]);


    }

    conta_frequencia(numeros,upperInterval,lowerInterval,step,upper);
    


 /*   for ( i = 0; i < nFaixas; i++)
    {
        for (j = 0; j < step; j++)
        {
            (rand() % (upper - lower + 1)) + lower; 
        }
        upper += step;
        lower += step;
    }*/
    
    

    


    return 0;   
}

/* demais funcoes */

int generate_numbers(int upper,int lower){
    int num = (rand() % (upper - lower + 1)) + lower; 
    return num;
}

void bubble_sort(int a[], int n) {
    
    int i = 0, j = 0, tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (a[j] > a[j + 1]) {  // swop if order is broken
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void conta_frequencia(int a[],int upper,int lower,int step, int tamanho){
    //printf("teste\n");
    int i=0,j=0, k=0, iteracoes=0,temp=0,temp2=0;
    //int tamanho = 15;
    int auxInf=0, auxSup=tamanho;
    int stop=1;
    int flag = 0;
    int contador = 0;
    int ultimoj = 0;
    iteracoes = ((tamanho-0)+1)/step;
    for (i = 0; i < iteracoes; i++)
    
    {
        //printf("teste %d \n",i);
        printf("valores entre %d e %d\n",lower,upper);
        do
        {
            temp = (auxSup-auxInf)/2;
            
            if ((temp)%2) //impar
            {
                j = temp + 1 + auxInf;
            }
            else{
                j = temp + auxInf;
            }

            //printf("j %d\n",j);

            if(a[j]<upper){
                auxInf= j;
            }
            
            else if(a[j]>upper){
                auxSup = j;
            }
/*            else if(a[j]==upper){
                stop = 0
            }*/

            if(a[j]<lower){
                auxInf= j;
            }
            
            else if(a[j]>lower){
                auxSup = j;
            }
            //printf("valor de j%d\n",j);

            if((auxSup-auxInf)<=2){
               // printf("upper %d\n",upper);
               // printf("a[j] %d\n",a[j]);

                if(a[j]>upper){
                    temp = a[j];
                    while(temp==a[j]){
                        j--;
                        temp2++;
                    }
                    if(a[j]<lower){
                        j+=temp2;
                        temp2=0;
                    }
                }

                
                if(a[j]<=upper){

                    while(a[j]<=upper){
                        j++;
                    }
                    stop = 0;
                }
                else{
                    if(a[j]>upper){
                        contador = -1;
                    }
                    stop = 0;
                }
            }
            
        }while(stop);
        if(contador>=0){
            temp = j - ultimoj;
            printf("%d ocorrencias\n",temp);
            ultimoj=j;
           /* for (k = 0; k < j; k++)
            {
               
                printf("%d\n",a[k]);
                
            }*/
        }
        else{
                printf("0 ocorrencias\n");
        }

        stop = 1;
        lower=lower+step;
        upper=upper+step;
        auxInf=0;
        auxSup = tamanho;
        contador = 0;
       
    }
    
}

