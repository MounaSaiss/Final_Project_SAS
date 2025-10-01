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
    afficheMenu();
    return 0;
}