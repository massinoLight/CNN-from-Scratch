/*
 Structure d'un neurone
 
 
 x1___
      \   __________
 x2____\ |          |
 ._____  |somme | f | _______    Y
 ._____/ |          |           
 .____/  |__________|
 xn__/
 
 
 */
 
struct neurone
{
  double *x;//vecteur d'entré
  double *w;//les poids synaptiques
  char fonction; // Fonction d'activation 1 2 3 4 selon le fichier fonction.h.

  double *sortie;//vecteur de sortie retournée par le neurone
};

