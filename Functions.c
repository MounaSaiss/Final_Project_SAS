#include <stdio.h>
#include <string.h>
#include "header.h"
int nbrClient = 0;
int nbrProduits = 7;

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
        }
        printf("Id  :%d\n", CLIENTINFO[nbrClient - 1].idClient);
        printf("Nom  : %s\n", CLIENTINFO[nbrClient - 1].nomClient);
        printf("Prenom : %s\n", CLIENTINFO[nbrClient - 1].prenom);
        printf("Email  : %s\n", CLIENTINFO[nbrClient - 1].email);
        printf("Solde  : %.2f\n", CLIENTINFO[nbrClient - 1].sold);
        printf("____________________________________________________\n");

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
                printf("Categorie :%s\n", PRODUIT[i].categorie);
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
                        if (strcasecmp(PRODUIT[j].nomProduit, PRODUIT[j + 1].nomProduit) > 0)
                        {
                                tmp = PRODUIT[j];
                                PRODUIT[j] = PRODUIT[j + 1];
                                PRODUIT[j + 1] = tmp;
                        }
                }
        }

}
/*_____________trie par categorie_____________ */
void trieCatego(produit PRODUIT[])
{
        produit tmp;
        char categorie[30] ;
        for (int i = 0; i < nbrProduits - 1; i++)
        {
                for (int j = 0; j < nbrProduits - i - 1; j++)
                {
                        if (strcasecmp(PRODUIT[j].categorie, PRODUIT[j + 1].categorie) > 0)
                        {
                                tmp = PRODUIT[j];
                                PRODUIT[j] = PRODUIT[j + 1];
                                PRODUIT[j + 1] = tmp;
                        }
                }
        }
        afficheProduit(PRODUIT);
        printf("\033[32m"
                "Produits tries par categorie (alphabetique).\n"
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
        printf("\n");
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
/* ------------------ recherche par nom ------------------------ */
void rechNom(produit PRODUIT[])
{
        int estTrouver = 0;
        char nomSearch[30];
        trieAlpaha(PRODUIT); 
        printf("Veuilez Saisir le nom du produit a chercher: ");
        scanf(" %[^\n]", nomSearch);
        printf("\n");


        int start = 0, end = nbrProduits - 1, center;
        while (start <= end)
        {
                center = (start + end) / 2; 
                if (strcasecmp(nomSearch, PRODUIT[center].nomProduit) == 0)
                {
                printf("ID Produit :%d\n", PRODUIT[center].idProduit);
                printf("Nom Produit :%s\n", PRODUIT[center].nomProduit);
                printf("Categorie :%s\n", PRODUIT[center].categorie);
                printf("Prix Produit : %.2f\n", PRODUIT[center].prix);
                printf("Stock :%d\n", PRODUIT[center].stock);
                estTrouver ++;

                break;
                }
                else if (strcasecmp(nomSearch, PRODUIT[center].nomProduit) > 0)
                {
                        start = center + 1;
                }
                else
                {
                        end = center - 1;
                }
        }
        if(estTrouver == 0)
                printf("Aucun Produits est trouvee\n");
}
/* ------------------ recherche par categorie ------------------------ */
/*
void rechCatego(produit PRODUIT[]){
        int estTrouve = 0;
        int i = 0;
        char categoSearch[30];

        printf("\nVeuilez Saisir la categorie des produits a chercher: ");
        scanf(" %[^\n]", categoSearch);
        printf("\n");

        do{
                printf("ID Produit :%d\n", PRODUIT[i].idProduit);
                printf("Nom Produit :%s\n", PRODUIT[i].nomProduit);
                printf("Categorie :%s\n", PRODUIT[i].categorie);
                printf("Prix Produit : %.2f\n", PRODUIT[i].prix);
                printf("Stock :%d\n", PRODUIT[i].stock);
                estTrouve ++;
                i++;
                printf("\n----------------------------------------\n");
        }while(strcasecmp(categoSearch, PRODUIT[i].categorie)==0);
        if(estTrouve == 0)
                printf("Aucun produits est trouve\n");
}
*/
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
