#include <stdio.h>
#include <stdlib.h>
#include "fonction.c"


#include "init.c"


int main()
{
    

s_Neurone neurone;


init_n_conf();
neurone.x=(double*)malloc(sizeof(double)*Reseau.n);



for (int j=0;j<4;j++)
		{

			neurone.x[j]=random_w();
			
		}


 int i;
 
    for (i = 0 ; i < 4 ; i++)
    {
        printf("%f\n", neurone.x[i]);
    }



    return 0;
}



