/*
    Glavni dio posla zapocinjemo tek kada napravimo main.h i ubacimo ga unutar main.c (#nclude)
*/

#pragma once // Sluzi i kao obicni include guard -> ifndef...


// Umjesto njihovog zadatka koji su nam dali, idemo korak naprijed i dodajemo jos funkcionalnosti

#define MAX_INGRIDIENT_STOCK 100
#define MAX_INGRIDIENTS 10

int sifraNarudzbe = 0;

char menuItems[10][50];
float menuPrices[10];

int ingridientQuantities[10];
int orders[10][10];

int numOfMenuItems;
int numOfIngridients;
int ingridientIndex;

void addMenuItem(char name[], float price);                 // opcija 1
void displayMenu();                                         // opcija 2
void addOrder(int tableID, int menuItemID, int quantity);   // opcija 3
void displayOrdersPerTable(int tableID);                    // opcija 4
void addIngridient(int ingridientIndex, int quantity);         // opcija 5
void checkIngridientStock();                                // opcija 6
void updateIngridientQuantity(char name[], int quantity);    // opcija 7
                                                            /* opcija 8 je da se napusti program */

int ingridientStock[MAX_INGRIDIENTS] = {0};

const char *ingridientNames[MAX_INGRIDIENTS] = {

    "Krastavci", "Kupus", "Sir", "Hljeb", "Piletina",
    "Avocado", "Sunka", "Masline", "Svjezi sir", "Mix za corbu"
};

void initializeIngridients() {

    ingridientStock[0] = 10;
    ingridientStock[1] = 9;
    ingridientStock[2] = 8;
    ingridientStock[3] = 5;
    ingridientStock[4] = 22;
    ingridientStock[5] = 12;
    ingridientStock[6] = 17;
    ingridientStock[7] = 5;
    ingridientStock[8] = 4;
    ingridientStock[9] = 0;
}



// dodaje novu stavku i njenu cijenu na postojeci meni
void addMenuItem(char name[], float price) {

    strcpy(menuItems[numOfMenuItems], name);

    menuPrices[numOfMenuItems] = price;

    numOfMenuItems = numOfMenuItems + 1;

    system("cls");
}

void displayMenu() {

    printf("--- Meni ---");
    printf("\n\n\n");

    for(int index = 0; index < numOfMenuItems; index++) {

        printf("%d. %s - $%.2f\n", index + 1, menuItems[index], menuPrices[index]);
    }

    printf("\n\n\n--- Kraj ---");
    printf("\n\n\n");

}

void addOrder(int tableID, int menuItemID, int quantity) {

    if(tableID < 0 || tableID >= 10) {

        printf("--- Nepostojeci ID stola. ---\n");
        printf("\n\n\n");

    } else {

        sifraNarudzbe = sifraNarudzbe + 1;

        orders[tableID][menuItemID] += quantity;
        printf("--- Dodano %d jedinica %s za stol ID %d narudzbu. ---", quantity, menuItems[tableID], tableID);
        printf("\n\n\n");
    }
}

void displayOrdersPerTable(int tableID) {

    if(tableID < 0 || tableID >= 10) {

        printf("--- Unijeli ste nepostojeci broj stola. ---\n");
        printf("\n\n\n");
        return;

    } else {

        printf("--- Narudzbe za stol %d: ---\n\n\n", tableID);

        printf("--- Stol id -> %d | Sifra narudzbe -> %d \n\n\n---\n\n\n", orders[tableID][tableID], sifraNarudzbe);
    }
}

void addIngridient(int ingridientIndex, int quantity){

    if(quantity <= 0){
        printf("---Invalidna kolicina sastojka.---\n\n\n");
        return;
    }

    if(ingridientIndex < 0 || ingridientIndex >= MAX_INGRIDIENTS) {

        printf("--- Invalidan unos indeksa sastojka ---\n\n\n");
        return;
    }

    ingridientStock[ingridientIndex] += quantity;

    printf("--- Dodano %d kolicina sastojka na indeksu %d, trenutno ima %d u zalihama.---\n\n\n", quantity, ingridientIndex, ingridientStock[ingridientIndex]);
}

void checkIngridientStock() {

    printf("--- Stanje kolicine zaliha za ID %d ---\n\n\n", ingridientIndex);
    for(int i = 0; i < MAX_INGRIDIENTS; i++) {
        printf("%s: %d kolicina\n", ingridientNames[i], ingridientStock[i]);
    }
    printf("\n\n\n--- Kraj ---\n\n\n");
}

void updateIngridientQuantity(char name[], int quantity) {

    for(int i = 0; i < numOfIngridients; i++) {

        if(strcmp(ingridientNames[i], name) == 0) {
            ingridientQuantities[i] += quantity;

            if(ingridientQuantities[i] < 0) {

                ingridientQuantities[i] = 0;
            }
            printf("--- Azurirana kolicina za %s i sada iznosi %d\n\n\n---\n\n\n", name, ingridientQuantities[i]);
            return;
        }
    }
    printf("--- Sastojak nije pronadjen! ---\n");
    printf("\n\n\n");
}
