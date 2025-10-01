#include <stdio.h>
#include <string.h>
#include "header.h"

client CLIENTINFO[MAX_CLIENT];
produit PRODUIT[MAX_PRODUIT] = {
    {1, "Keyboard", "Electronics", 89.99, 80, "Mechanical RGB keyboard with programmable keys"},
    {2, "Iphone", "Electronics", 49.99, 200, "Waterproof activity tracker with heart rate monitor"},
    {3, "Desk", "Office Supplies", 15.99, 150, "Multi-compartment desk organizer set"},
    {4, "Chair", "Home & Kitchen", 18.99, 180, "Double-walled insulated stainless steel bottle"},
    {5, "Basketball", "Sports & Outdoors", 29.99, 95, "Official size 7 basketball for indoor/outdoor"},
    {6, "Tennis", "Sports & Outdoors", 89.99, 60, "Professional tennis racket with bag"},
    {7, "Table", "Home & Kitchen", 199.99, 30, "10-piece non-stick cookware set"},
};

int main()
{
    
        int choixMenu;
        int choixSMenu;
        int chose;
        int ch;
        do
        {
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
                scanf("%d", &choixMenu);
                switch (choixMenu)
                {
                case 1:
                        system("cls");
                        do
                        {
                                printf("\n_____Gestion du profil client_____\n");
                                printf("\n===Choisir l'Option===\n");
                                printf("1.Creation de profil\n");
                                printf("2.Modification du profil\n");
                                printf("3.Consultation du profil\n");
                                printf("0.Retour au menu principal\n");
                                printf("\033[33m"
                                        "::::Veuillez saisie votre choix :"
                                        "\033[0m");
                                scanf("%d", &choixSMenu);
                                switch (choixSMenu)
                                {
                                case 1:
                                        printf("==CREE PROFIL==\n");
                                        creeProfil(CLIENTINFO);
                                        break;
                                case 2:
                                        printf("==MODIFIEE PROFIL==\n");
                                        FonctModifiProfi(CLIENTINFO);
                                        break;
                                case 3:
                                        printf("==CONSULT PROFIL==\n");
                                        consultProfil(CLIENTINFO);
                                        break;
                                case 0:
                                        printf("\n");
                                        break;
                                default:
                                        printf("=Choix Invalide=\n");
                                        break;
                                }
                        } while (choixSMenu != 0);
                        break;
                case 2:
                        system("cls");
                        do
                        {
                                printf("\n_____Gestion du solde virtuel_____\n");
                                printf("\n===Choisir l'Option===\n");
                                printf("1.Consultation du solde\n");
                                printf("2.Depot d'argent\n");
                                // printf("3.Verification automatique\n");
                                printf("0.Retour au menu principal\n");
                                printf("\033[33m"
                                        "::::Veuillez saisie votre choix :"
                                        "\033[0m");
                                scanf("%d", &choixSMenu);
                                switch (choixSMenu)
                                {
                                case 1:
                                        printf("==CONSULTER SOLDE==\n");
                                        affichageMontant(CLIENTINFO);
                                        break;
                                case 2:
                                        printf("==DEPOT ARGENT==\n");
                                        depotArgent(CLIENTINFO);
                                        break;
                                // case 3:
                                //         printf("==VERIFIER AUTOMATIQUE==\n");
                                //         break;
                                case 0:
                                        printf("Revenu au menu principale\n");
                                        break;
                                default:
                                        printf("==CHOIX Invalide!!!==\n");
                                        break;
                                }
                        } while (choixSMenu != 0);
                        break;
                case 3:
                        system("cls");
                        do
                        {
                                printf("\n_____ Consultation des produits_____\n");
                                printf("\n===Choisir votre Option===\n");
                                printf("1.Affichage catalogue\n");
                                printf("2.Recherche produits\n");
                                printf("3.Tri des produits\n");
                                printf("4.Details produit \n");
                                printf("0.Retour au menu principal\n");
                                printf("\033[33m"
                                        "::::Veuillez saisie votre choix :"
                                        "\033[0m");
                                scanf("%d", &choixSMenu);
                                switch (choixSMenu)
                                {
                                case 1:
                                        printf("==AFFICHE CATALOGUE==\n");
                                        afficheProduit(PRODUIT);
                                        break;
                                case 2:
                                        printf("==RECHERCHE PRODUITS==\n");
                                        printf("1.Recherche par Nom \n");
                                        printf("2.Recherche par Categorie\n");
                                        printf("3.Recherche par Prix \n");
                                        printf("0.Revenu au menu Principale \n");
                                        printf("Veuillez saisir la methode de Recherche: ");
                                        scanf("%d",&chose);
                                        switch(chose){
                                                case 1 :rechNom(PRODUIT);
                                                        break;
                                                /*case 2: rechCatego(PRODUIT);
                                                        break;*/
                                                case 0: printf("Retourner au menu principal\n");
                                                        break;
                                                
                                        }
                                        break;
                                case 3:
                                        printf("==TRIE PRODUITS==\n");
                                        do
                                        {
                                                printf("Veuillez saisie methose de Trie :\n");
                                                printf("1.Nom Produits\n");
                                                printf("2.Prix croissante\n");
                                                printf("3.Prix decroissante\n");
                                                printf("4.Categorie\n");
                                                printf("0.Return\n");
                                                printf("Saisie votre choix :");
                                                scanf("%d", &ch);
                                                switch (ch)
                                                {
                                                case 1:
                                                        trieAlpaha(PRODUIT);
                                                        afficheProduit(PRODUIT);
                                                        break;
                                                case 2:
                                                        triCroi(PRODUIT);
                                                        break;
                                                case 3:
                                                        triDEcroi(PRODUIT);
                                                        break;
                                                case 4:trieCatego(PRODUIT);
                                                        break;
                                                case 0:
                                                        printf("Retourn Au menu principale!!\n");
                                                        break;
                                                default:
                                                        printf("choix invalide!!\n");
                                                        break;
                                                }
                                        } while (ch != 0);
                                        break;
                                case 4:
                                        system("cls");
                                        printf("==DETAILS PRODUITS==\n");
                                        RechId(PRODUIT);
                                        break;
                                case 0:
                                        system("cls");
                                        printf("==SORTIR!!!!!==\n");
                                        break;
                                default:
                                        printf("Choix Invalide\n");
                                        break;
                                }
                        } while (choixSMenu != 0);
                        break;
                case 4:
                        printf("\n_____Effectuer un achat_____\n");
                        fonAchat();
                        break;
                case 5:
                        printf("\n_____Mes statistiques_____\n");
                        break;
                case 0:
                        printf("\n_____Quitter l'application_____\n");
                        break;
                default:
                        printf("Se choix n'existe Pas\n");
                        break;
                }
        } while (choixMenu != 0);



    return 0;
}