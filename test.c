#include <stdio.h>
#include <stdlib.h>
#include "fonction.c"


#include "init.c"


int main()
{
    
init_n_conf();
s_Neurone neurone1;

double vecteur[10] = {1.0, 3.0, 7.0, 3.0,2.0,7.0,4.0,2.0,1.0,0.0};

neurone1=init_neurone(neurone1,vecteur ,ReLU);


for (int j=0;j<s_Reseau.n;j++)
{
    printf("%f  ,  %f \n", neurone1.w[j],neurone1.x[j]);

}


printf("%f\n", neurone1.sortie);

return 0;

}
