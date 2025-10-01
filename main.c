#include <stdio.h>
#include <string.h>
#include "header.h"

client CLIENTINFO[MAX_CLIENT];
produit PRODUIT[MAX_PRODUIT] = {
    {1, "Gaming Keyboard", "Electronics", 89.99, 80, "Mechanical RGB keyboard with programmable keys"},
    {2, "Fitness Tracker", "Electronics", 49.99, 200, "Waterproof activity tracker with heart rate monitor"},
    {3, "Desk Organizer", "Office Supplies", 15.99, 150, "Multi-compartment desk organizer set"},
    {4, "Stainless Steel Bottle", "Home & Kitchen", 18.99, 180, "Double-walled insulated stainless steel bottle"},
    {5, "Basketball", "Sports & Outdoors", 29.99, 95, "Official size 7 basketball for indoor/outdoor"},
    {6, "Wireless Earbuds", "Electronics", 79.99, 120, "True wireless earbuds with charging case"},
    {7, "Desk Chair", "Office Supplies", 129.99, 45, "Ergonomic office chair with lumbar support"},
    {8, "Cookware Set", "Home & Kitchen", 199.99, 30, "10-piece non-stick cookware set"},
    {9, "Tennis Racket", "Sports & Outdoors", 89.99, 60, "Professional tennis racket with bag"},
    {10, "Tablet Stand", "Electronics", 12.99, 220, "Adjustable aluminum stand for tablets"},
};

int main()
{
    afficheMenu();
    return 0;
}