#include <stdio.h>
#include <string.h>
#include "header.h"
int nbrClient = 0;
int nbrProduits = 10;

/*_________________Fonction de Menu______________*/
void afficheMenu()
{
        int choixMenu;
        int choixSMenu;
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
                                        break;
                                case 3:
                                        printf("==TRIE PRODUITS==\n");
                                        do
                                        {
                                                printf("Veuillez saisie methose de Trie :\n");
                                                printf("1.Alphabetique\n");
                                                printf("2.Prix croissante\n");
                                                printf("3.Prix decroissante\n");
                                                printf("0.Return\n");
                                                printf("Saisie votre choix :");
                                                scanf("%d", &ch);
                                                switch (ch)
                                                {
                                                case 1:
                                                        trieAlpaha(PRODUIT);
                                                        break;
                                                case 2:
                                                        triCroi(PRODUIT);
                                                        break;
                                                case 3:
                                                        triDEcroi(PRODUIT);
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
}
/*________________Creation de Profil________________*/
void creeProfil(client CLIENTINFO[])
{
        int idClient = 1;
        char nomClient[30], prenom[30], email[60];
        float sold;
        if (nbrClient < MAX_CLIENT)
        {
                printf("Veuillez saisir le nom :\n");
                scanf(" %[^\n]", nomClient);
                printf("Veuillez saisir le prenom :\n");
                scanf(" %[^\n]", prenom);
                sprintf(email, "%s.%s@email.com", prenom, nomClient);
                printf("Email de client est:%s\n", email);
                printf("Veuillez saisir votre sold:\n");
                scanf("%f", &sold);

                strcpy(CLIENTINFO[nbrClient].nomClient, nomClient);
                strcpy(CLIENTINFO[nbrClient].prenom, prenom);
                strcpy(CLIENTINFO[nbrClient].email, email);
                CLIENTINFO[nbrClient].sold = sold;
                CLIENTINFO[nbrClient].idClient = 1;
                printf("\033[35m"
                       "==Profil Cree Avec Succes!\n"
                       "\033[0m");
                nbrClient++;
        }
        else
        {
                printf("\033[35m"
                       "==Vous Avez daja un Profil!\n"
                       "\033[0m");
        }
}
/*_________modification de profil___________*/
void FonctModifiProfi(client CLIENTINFO[])
{
        int Idsaisie;
        int choix;
        char nomClient[30], prenom[30], email[60];

        if (nbrClient == 0)
        {
                printf("Aucun Profil a Afficher\n");
                return;
        }

        printf("Nouvelle Nom :");
        scanf(" %[^\n]", nomClient);
        strcpy(CLIENTINFO[nbrClient - 1].nomClient, nomClient);
        printf("Nouvelle Prenom:");
        scanf(" %[^\n]", prenom);
        strcpy(CLIENTINFO[nbrClient - 1].prenom, prenom);
        sprintf(CLIENTINFO[nbrClient - 1].email, "%s.%s@email.com", prenom, nomClient);
        printf("Email de client est:%s\n", CLIENTINFO[nbrClient - 1].email);
        printf("\033[32m"
               "___La modification fait Avec succes___\n"
               "\033[0m");
}
/*______________Affichage de profil______________*/
void consultProfil(client CLIENTINFO[])
{
        if (nbrClient == 0)
        {
                printf("==Aucun Profil a Afficher==\n");
                return;
        printf("Id  :%d\n", CLIENTINFO[nbrClient - 1].idClient);
        printf("Nom  : %s\n", CLIENTINFO[nbrClient - 1].nomClient);
        printf("Prenom : %s\n", CLIENTINFO[nbrClient - 1].prenom);
        printf("Email  : %s\n", CLIENTINFO[nbrClient - 1].email);
        printf("Solde  : %.2f\n", CLIENTINFO[nbrClient - 1].sold);
        printf("____________________________________________________\n");
}
}
/*_____Gestion de solde _____*/
void affichageMontant(client CLIENTINFO[])
{
        printf("==Sold Disponible : %.2f\n", CLIENTINFO[nbrClient - 1].sold);
}
void depotArgent(client CLIENTINFO[])
{
        float MAjoute;
        printf("--Saisir Montant a ajouter :");
        scanf("%f", &MAjoute);
        CLIENTINFO[nbrClient - 1].sold += MAjoute;
        printf("Votre nauveau Solde est :%.2f\n", CLIENTINFO[nbrClient - 1].sold);
}

/*__________catalogue des produits_____*/
void afficheProduit(produit PRODUIT[])
{
        for (int i = 0; i < nbrProduits; i++)
        {
                printf("ID Produit :%d\n", PRODUIT[i].idProduit);
                printf("Nom Produit :%s\n", PRODUIT[i].nomProduit);
                printf("Prix Produit : %.2f\n", PRODUIT[i].prix);
                printf("Stock :%d\n", PRODUIT[i].stock);
                printf("__________________________________________\n");
        }
}
/*___________ Trie ALphabitique___ ____________*/
void trieAlpaha(produit PRODUIT[])
{
        produit tmp;
        char nomProduits[30];
        for (int i = 0; i < nbrProduits - 1; i++)
        {
                for (int j = 0; j < nbrProduits - i - 1; j++)
                {
                        if (strcmp(PRODUIT[j].nomProduit, PRODUIT[j + 1].nomProduit) > 0)
                        {
                                tmp = PRODUIT[j];
                                PRODUIT[j] = PRODUIT[j + 1];
                                PRODUIT[j + 1] = tmp;
                        }
                }
        }
        afficheProduit(PRODUIT);
        printf("\033[32m"
               "Produits tries par modele (alphabetique).\n"
               "\033[0m");
}
/*___________trie croissante ___________*/
void triCroi(produit PRODUIT[])
{
        produit tmp;

        for (int i = 0; i < nbrProduits - 1; i++)
        {
                for (int j = 0; j < nbrProduits - 1 - i; j++)
                {
                        if (PRODUIT[j].prix > PRODUIT[j + 1].prix)
                        {
                                tmp = PRODUIT[j];
                                PRODUIT[j] = PRODUIT[j + 1];
                                PRODUIT[j + 1] = tmp;
                        }
                }
        }
        afficheProduit(PRODUIT);
        printf("\033[32m"
               "PRIX des produits  ordre croissante\n"
               "\033[0m");
}
/*___________trie decroissante ___________*/
void triDEcroi(produit PRODUIT[])
{
        produit tmp;

        for (int i = 0; i < nbrProduits - 1; i++)
        {
                for (int j = 0; j < nbrProduits - 1 - i; j++)
                {
                        if (PRODUIT[j].prix < PRODUIT[j + 1].prix)
                        {
                                tmp = PRODUIT[j];
                                PRODUIT[j] = PRODUIT[j + 1];
                                PRODUIT[j + 1] = tmp;
                        }
                }
        }
        afficheProduit(PRODUIT);
        printf("\033[32m"
                "PRIX des produits  ordre decroissante\n"
                "\033[0m");
}
/*____________Search by ID________*/
void RechId(produit PRODUIT[])
{
        int Idsearch;
        if (nbrProduits == 0)
        {
                printf("Aucun produits existe\n");
                return;
        }
        printf("Veuillez saisir l'Id de produits qui tu veux :");
        scanf("%d", &Idsearch);
        for (int i = 0; i <= nbrProduits; i++)
        {
                if (PRODUIT[i].idProduit == Idsearch)
                {
                        printf("\n");
                        printf("Id Produit :%d\n", PRODUIT[i].idProduit);
                        printf("Nom Produit :%s\n", PRODUIT[i].nomProduit);
                        printf("Categorie Produit :%s\n", PRODUIT[i].categorie);
                        printf("Prix Produit : %.2f\n", PRODUIT[i].prix);
                        printf("Stock :%d\n", PRODUIT[i].stock);
                        printf("Description :%s\n", PRODUIT[i].description);
                }
        }
        printf("\033[32m"
               "Search Done!!!!!"
               "\033[0m");

        printf("\n");
}
/*fonction procedure achat*/
void achat(int id ,int i)
{
        int nbrachat;
        printf("\n");
        printf("Veuillez saisr la quantite qui tu veux acheter:");
        scanf("%d", &nbrachat);
        if (nbrachat > PRODUIT[i].stock)
        {
                printf("Diminue la quantite!!!stock Insufisant\n");
                return;
        }
        float prixpayer=nbrachat*PRODUIT[i].prix;
        if (prixpayer>CLIENTINFO[nbrClient-1].sold){
                printf("SOLD Inssufisant\n");
                return;
        }
        if (prixpayer<=CLIENTINFO[nbrClient-1].sold){
                CLIENTINFO[nbrClient-1].sold -=prixpayer;
                PRODUIT[i].stock -= nbrachat;
                printf("le prix a payer :%.2f\n",prixpayer);
                printf("le nombre des produits acheter :%d\n",nbrachat);
                printf("le Sold Restant apres l'achat :%.2f\n",CLIENTINFO[nbrClient-1].sold);
                printf("le stock restant dans ce produit :%d\n",PRODUIT[i].stock);
                printf("L'Achat Effectuer Avec succes\n");
                printf("\n");
        }
}
/*_________________Fonction verifier processe d'achat __________*/
void fonAchat()
{
        int idSeaisie;
        int choi;
        afficheProduit(PRODUIT);
        printf("\nVeuillez saisir l'Id de produit qui tu veux:");
        scanf("%d", &idSeaisie);
        for (int i = 0; i <= nbrProduits; i++)
        {
                if (PRODUIT[i].idProduit == idSeaisie)
                {
                        printf("ID Produit :%d\n", PRODUIT[i].idProduit);
                        printf("Nom Produit :%s\n", PRODUIT[i].nomProduit);
                        printf("Categorie Produit :%s\n", PRODUIT[i].categorie);
                        printf("Prix Produit : %.2f\n", PRODUIT[i].prix);
                        printf("Stock :%d\n", PRODUIT[i].stock);
                        printf("Description :%s\n", PRODUIT[i].description);
                        printf("Veuillez Vraiment effectuer l'achate :\n");
                        printf("1.Oui\n");
                        printf("2.Non\n");
                        printf("Saisir le choix :");
                        scanf("%d",&choi);
                        switch (choi)
                        {
                        case 1:
                                achat(idSeaisie, i);
                                break;
                        case 2:
                                printf("\nRevenu au menu Principale\n");
                                break;
                        default:printf("Choix Introuvable");
                        }
                }
        }
}
