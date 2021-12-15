#include <stdio.h>
#include <stdlib.h>
#include "fonction.c"


#include "init.c"


int main()
{
    

s_Neurone neurone;


neurone=init_neurone('R');

printf("%f\n", neurone.sortie);

return 0;

}
