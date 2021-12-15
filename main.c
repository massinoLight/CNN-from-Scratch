#include <stdio.h>
#include <stdlib.h>



 double *init_rand_w(double tableau[],int tailleTableau) { 
//double *tableau=malloc(tailleTableau*sizeof(double));
    
    for (int i = 0 ; i < tailleTableau ; i++)
    {
       
        tableau[i]=((double)rand())/((double)RAND_MAX);
    }
   return  tableau;
}




int main()
{
srand(time(NULL));
double *t1=(double*)malloc(sizeof(double)*10);
double *t2=(double*)malloc(sizeof(double)*10);

t1=init_rand_w(t1,5);
t2=init_rand_w(t2,5);


    printf("***************************\n");
for (int x = 0; x <5; x++)
    {
        printf("%f  ,  %f \n", t1[x],t2[x]);
        
       
    }
}



