#include<stdio.h>
#include<stdlib.h>
#ifndef HEADER_H
#define HEADER_H
#define MAX_PRODUIT 50 
#define MAX_CLIENT 1





typedef struct{
    int idClient ;
    char nomClient[30];
    char prenom[30];
    char email[60];
    float sold;

}client;

typedef struct{
    int idProduit;
    char nomProduit[30];
    char categorie[30] ;
    float prix;
    int stock;
    char description[100]; 
}produit;


extern client CLIENTINFO[MAX_CLIENT];
extern produit PRODUIT[MAX_PRODUIT];
extern int nbrProduits;
extern int nbrClient;

/*Prototype des fonctions*/
void afficheMenu();
void creeProfil(client CLIENTINFO[]);
void FonctModifiProfi(client CLIENTINFO[]);
void consultProfil(client CLIENTINFO[]);
void affichageMontant(client CLIENTINFO[]);
void depotArgent(client CLIENTINFO[]);
void afficheProduit(produit PRODUIT[]);
void triDEcroi(produit PRODUIT[]);
void triCroi(produit PRODUIT[]);
void trieAlpaha(produit PRODUIT[]);
void RechId(produit PRODUIT[]);
void achat(int id,int i);
void fonAchat();

#endif