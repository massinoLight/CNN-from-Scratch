/*typedef enum fonctionActivation fonctionActivation;
enum Volume
{
    ReLU, sigmoide, Heaviside
};
*/


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
 
 
 struct Neurone
{
  double *x;//vecteur d'entré
  double *w;//les poids synaptiques
  char fonction; // Fonction d'activation 1 2 3 4 selon le fichier fonction.h.

  double sortie;//vecteur  position du neurone qui va étre ajustable
};
typedef struct Neurone s_Neurone;





/*
 Structure de notre réseau de neurons
 */
struct s_Reseau
{
  int n;  // Taille du vecteur d'entré
  
  s_Neurone chouche[3]; // une chouche de neurone 
  
} s_Reseau;


 
 
 
/*typedef struct neurone neurone; 
 
struct neurone
{
  double *x;//vecteur d'entré
  double *w;//les poids synaptiques
  fonctionActivation fonction; // Fonction d'activation selon le fichier le enum.
  double sortie;//valeur de sortie retournée par le neurone
  neurone *connection; //tout les neurones qui sont reliés a ce dernier 
   
};*/

