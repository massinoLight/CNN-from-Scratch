#include <stdio.h>
#include <stdlib.h>
#include "fonction.c"


#include "init.c"


int main()
{
    

s_Neurone neurone;

double vecteur[10] = {0.0, 0.0, 0.0, 3.0,2.0,7.0,4.0,2.0,1.0,0.0};

neurone=init_neurone(&vecteur ,ReLU);

printf("%f\n", neurone.sortie);

return 0;

}
