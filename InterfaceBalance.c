#include "main.h"
#include "piloteSerieUSB.h"

//Definitions privees
#define INTERFACEBalance_LONGUEUR_MAXIMALE_DES_COMMANDES 64
#define INTERFACEBalance_LONGUEUR_MAXIMALE_DES_REPONSES 64

//Declarations de fonctions privees:
int interfaceBalance_ecritUneCommande(char *Commande, unsigned char Longueur);
int interfaceBalance_recoitUneReponse(char *Reponse, unsigned char LongueurMaximale);

//Definitions de variables privees
unsigned char interfaceBalance_commande[INTERFACEBalance_LONGUEUR_MAXIMALE_DES_COMMANDES];
unsigned char interfaceBalance_reponse[INTERFACEBalance_LONGUEUR_MAXIMALE_DES_REPONSES];

//Definitions de fonctions privees:
int interfaceBalance_ecritUneCommande(char *Commande, unsigned char Longueur)
{
int retour;
  retour = piloteSerieUSB_ecrit(Commande, Longueur);
  if (retour != (int)Longueur)
  {
    return -1;
  }
  piloteSerieUSB_attendLaFinDeLEcriture();
  return retour;
}

int interfaceBalance_recoitUneReponse(char *Reponse, unsigned char LongueurMaximale)
{
  return piloteSerieUSB_lit(Reponse, LongueurMaximale);  
}

//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
int interfaceBalance_initialise(void)
{
  return 0;
}