#include <stdio.h>
#include <stdlib.h>
#include "fonction.c"
#include "init.c"







int main()
{
srand(time(NULL));
double input[] = {0.0, 1.0};  
int length = sizeof(input)/sizeof(input[0]); 
int profondeurReseau=2;  
int nbNeuroneParCouche=2;
//double otput[10] = {1.0, 3.0, 7.0, 3.0,2.0,7.0,4.0,2.0,1.0,0.0}; 
//on initalise la taille du vecteur d'entre je met 10 au depart mais on va recup ca selon les images dentrées  
init_n_conf(length);
s_Reseau perceptron=init_perceptron(input,profondeurReseau,nbNeuroneParCouche,ReLU);



return 0;

}



