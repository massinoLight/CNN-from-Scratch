/*
On déclare les fonctions d'actiovations sous forme d'énum pour faire plus propre 
*/

typedef enum fonctionActivation fonctionActivation;
enum fonctionActivation
{
    ReLU, sigmoide, tangante,Identite,Marche
};


/*
 Structure d'un neurone
 
 
 x1___
      \w1 __________
 x2____\ |          |
 ._____  |somme | f | _______    Y
 ._____/ |          |           
 .____/wn|__________|
 xn__/
 
 
 */
 
 
 struct Neurone
{
  double *x;//vecteur d'entré
  double *w;//les poids synaptiques
  double sortie;//valeur en sorite du neurone 
};
typedef struct Neurone s_Neurone;





/*
 Structure de notre réseau de neurons
 */
struct s_Reseau
{
  int n;  // nb de couche que comporte le rx 
  
  s_Neurone couche[3]; // une couche de neurone 
  
} s_Reseau;


/*
 Structure d'couche
 */
struct s_Layer
{
   const int n;  // Nb de neurone que comporte la couche 
  
  s_Neurone *couche; // une couche de neurone 
  
} s_Layer;
