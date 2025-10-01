#include<stdio.h>
#include<stdlib.h>
#ifndef HEADER_H
#define HEADER_H
#define MAX_PRODUIT 50 




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


extern client CLIENTINFO;
extern produit PRODUIT[MAX_PRODUIT];
extern int nbrProduits;
extern int nbrClient;

/*Prototype des fonctions*/
void afficheMenu();
void creeProfil();
void FonctModifiProfi();

#endif