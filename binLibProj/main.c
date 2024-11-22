#include <stdio.h>

#include "main.h"

/*
    Napravite program koji simulira osnovni sistem za upravljanje restoranom,
    uključujući praćenje jela, dostupnih porcija i ukupne zarade.
    Program treba imati meni kroz koji korisnik bira opcije.
*/

/*
    Kako bi podesili neku drugu temu, potrebno je sljedece:
        Settings, editor -> syntax highlighting
*/

int main() {

    initializeIngridients();

    //  -   -   -   -   -   -   -   -   -   -   //

    int
        choiceNum,
        tableIDNum,
        menuItemIDNum,
        quantity,
        indexOfIngridient,
        quantityOfIngridient;

    char name[50];

    float price;

    //  -   -   -   -   -   -   -   -   -   -   //

    while(1) {

        // zelimo da se program vrti beskonacno, zato koristimo while(true)

        printf("Sistem za upravljanje PinRow restoranom\n");

        // dajemo trenutnom korisniku priliku da odabere potrebnu funkcionalnost

        printf("1. Dodaj stavku u meni\n");
        printf("2. Prikazi meni\n");
        printf("3. Dodaj narudzbu\n");
        printf("4. Prikazi narudzbe za ID svog stola\n");
        printf("5. Dodaj sastojak\n");
        printf("6. Provjeri zalihe sastojaka\n");
        printf("7. Azuriraj stanje zaliha\n");
        printf("8. Napusti\n");

        // korisnik obavlja odabir nakon revizije ponudjenih opcija

        printf("Unesite cijeli broj kao svoj odabir (1-8) -> ");
        scanf("%d", &choiceNum);

        // sada kada imamo neki int za izbor, mozemo napraviti mali padajuci menu pomocu switch case-a

        switch(choiceNum) {

            case 1:

                system("cls");

                printf("Unesite naziv imena stavke -> ");
                scanf(" %[^\n]s", name);

                printf("Unesite punu cijenu stavke -> ");
                scanf("%f", &price);

                addMenuItem(name, price);

                break;

            case 2:

                system("cls");
                displayMenu();

                break;

            case 3:

                system("cls");

                printf("Unesite ID stola (od 0 do 9)                -> ");
                scanf("%d", &tableIDNum);

                printf("Unesite ID stavke sa menija (od 0 do %d)    -> ", numOfMenuItems - 1);
                scanf("%d", &menuItemIDNum);

                printf("Unesite kolicinu                            -> ");
                scanf("%d", &quantity);

                addOrder(tableIDNum, menuItemIDNum, quantity);

                printf("--- Dodali ste narudzbu za stol %d sa sifrom %d ---\n\n\n--- KRAJ ---\n\n\n", tableIDNum, sifraNarudzbe);

                break;

            case 4:

                system("cls");

                printf("Unesite ID stola (0-9) -> ");
                scanf("%d", &tableIDNum);

                displayOrdersPerTable(tableIDNum);

                break;

            case 5:

                system("cls");

                printf("Unesite index sastojka                     -> ");
                scanf("%d", &indexOfIngridient);
                printf("Unesite dodanu vrijednost kolicine sastojka -> ");
                scanf("%d", &quantityOfIngridient);

                addIngridient(indexOfIngridient, quantityOfIngridient);

            case 6:

                system("cls");

                checkIngridientStock();

                break;

            case 7:

                printf("Unesite naziv sastojka                             -> ");
                scanf("%[^\n]s", name);

                printf("Unesite kolicinu kako bi je promijenili (- ili + ) -> ");
                scanf("%d", &quantity);

                updateIngridientQuantity(name, quantity);
                break;

            case 8:

                exit(0);
        }

    }

    return 0;
}
