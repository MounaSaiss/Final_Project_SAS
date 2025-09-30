#include<stdio.h>
#include<string.h>
#include "header.h"


/*_________________Fonction de Menu______________*/
void afficheMenu(){
int choixMenu;
int choixSMenu;

do {
    printf("=== SYSTEME D'ACHAT CLIENT ===\n");
    printf("1.  Gestion du profil client\n");
    printf("2.  Gestion du solde virtuel\n");
    printf("3.  Consultation des produits\n");
    printf("4.  Effectuer un achat\n");
    printf("5.  Mes statistiques\n");
    printf("0.  Quitter l'application\n"); 
    printf("\033[33m"
                "::::Veuillez saisie votre choix :"
                "\033[0m");
    scanf("%d",&choixMenu);
    switch(choixMenu){
        case 1 :do {
                    printf("\n_____Gestion du profil client_____\n");
                    printf("\n===Choisir l'Option===\n");
                    printf("1.Creation de profil\n");
                    printf("2.Modification du profil\n");
                    printf("3.Consultation du profil\n");
                    printf("4.Generation email\n");
                    printf("0.Retour au menu principal\n");
                    printf("\033[33m"
                    "::::Veuillez saisie votre choix :"
                    "\033[0m");
                    scanf("%d",&choixSMenu);
                    switch(choixSMenu){
                        case 1:printf("==CREE PROFIL==\n");
                                creeProfil();
                                break;
                        case 2:printf("==MODIFIEE PROFIL==\n");
                                break;
                        case 3:printf("==CONSULT PROFIL==\n");
                                break;
                        case 4:printf("==GENERER EMAIL==\n");
                                break;
                        case 0 :printf("\n");
                                break; 
                        default : printf("=Choix Invalide=\n");
                                break;
                    }
                }while(choixSMenu!=0);
        break;
        case 2 :do {
                    printf("\n_____Gestion du solde virtuel_____\n");
                    printf("\n===Choisir l'Option===\n");
                    printf("1.Consultation du solde\n");
                    printf("2.Depot d'argent\n");
                    printf("3.Verification automatique\n");
                    printf("0.Retour au menu principal\n");
                    printf("\033[33m"
                    "::::Veuillez saisie votre choix :"
                    "\033[0m");
                    scanf("%d",&choixSMenu);
                    switch(choixSMenu){
                        case 1:printf("==CONSULTER SOLDE==\n");
                                break;
                        case 2:printf("==DEPOT ARGENT==\n");
                                break;
                        case 3:printf("==VERIFIER AUTOMATIQUE==\n");
                                break;
                        case 0 :printf("SORTIR!!!!!\n");
                                break;
                        default:printf("==CHOIX Invalide!!!==\n");
                                break; 
                    }
                }while(choixSMenu!=0);
        break;
        case 3 :do{
                    printf("\n_____ Consultation des produits_____\n");
                    printf("\n===Choisir votre Option===\n");
                    printf("1.Affichage catalogue\n");
                    printf("2.Recherche produits\n");
                    printf("3.Tri des produits\n");
                    printf("4.Details produit \n");
                    printf("5.Produits predefinis\n");
                    printf("0.Retour au menu principal\n");
                    printf("\033[33m"
                    "::::Veuillez saisie votre choix :"
                    "\033[0m");
                    scanf("%d",&choixSMenu);
                    switch(choixSMenu){
                        case 1:printf("==AFFICHE CATALOGUE==\n");
                                break;
                        case 2:printf("==RECHERCHE PRODUITS==\n");
                                break;
                        case 3:printf("==TRIE PRODUITS==\n");
                                break;
                        case 4:printf("==DETAILS PRODUITS==\n");
                                break;
                        case 5:printf("==PRODUIT PREDIFINIES==\n");
                                break;
                        case 0 :printf("==SORTIR!!!!!==\n");
                                break; 
                        default :printf("Choix Invalide\n");
                                break;
                    }
                }while(choixSMenu!=0);
        break;
        case 4 :printf("\n_____Effectuer un achat_____\n");
                break;
        case 5 :printf("\n_____Mes statistiques_____\n");
                break;
        case 0 :printf("\n_____Quitter l'application_____\n");
                break;
        default:printf("Se choix n'existe Pas\n");
                break;
    }
}while(choixMenu != 0);

}
/*________________Creation de Profil________________*/
void creeProfil(){
    int idClient=1;
    char nomClient[30],prenom[30],email[60];
    float sold;
    
    printf("Veuillez saisir le nom :\n");
    scanf(" %[^\n]",nomClient);
    printf("Veuillez saisir le prenom :\n");
    scanf(" %[^\n]",prenom);
    sprintf(email, "%s.%s@email.com", prenom, nomClient);
    printf("Email de client est:%s\n",email);
    printf("Veuillez saisir votre sold:\n");
    scanf("%f",&sold);

    strcpy(CLIENTINFO.nomClient,nomClient);
    strcpy(CLIENTINFO.prenom,prenom);
    strcpy(CLIENTINFO.email,email);
    CLIENTINFO.sold=sold;
printf("\033[35m"
                "==Profil Cree Avec Succes!\n"
                "\033[0m");
}