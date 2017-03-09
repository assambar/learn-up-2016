#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Product {
    const char* name;
    unsigned int quantity;
    unsigned int price;
};

void printProduct(const Product& p) {
    cout << setw(30) << p.name
         << setw(8) << p.quantity
         << setw(5) << p.price/100
         /*width=3*/<< "." << setfill('0') << setw(2) << p.price%100 << endl;
    cout << setfill(' ');
}

void printProducts(Product products[], const unsigned int size) {
    cout << setw(30) << "NAME"
         << setw(8) << "QTY"
         << setw(8) << "PRICE" << endl;
    for (unsigned int i=0; i<size; i++) {
        printProduct(products[i]);
    }
}

void sortByQuantity(Product products[], const unsigned int size) {
    for (int i=0; i<size-1; i++) {
        int minPos = i;
        for (int j=i+1; j<size; j++) {
            if (products[j].quantity < products[minPos].quantity) {
                minPos = j;
            }
        }
        if(minPos != i) {
            Product tmp;
            memcpy(&tmp, &products[minPos], sizeof(Product));
            memcpy(&products[minPos], &products[i], sizeof(Product));
            memcpy(&products[i], &tmp, sizeof(Product));
        }
    }
}

void sortByPrice(Product products[], const unsigned int size) {
    for (int i=0; i<size-1; i++) {
        int minPos = i;
        for (int j=i+1; j<size; j++) {
            if (products[j].price < products[minPos].price) {
                minPos = j;
            }
        }
        if(minPos != i) {
            Product tmp;
            memcpy(&tmp, &products[minPos], sizeof(Product));
            memcpy(&products[minPos], &products[i], sizeof(Product));
            memcpy(&products[i], &tmp, sizeof(Product));
        }
    }
}

void sortByName(Product products[], const unsigned int size) {
    for (int i=0; i<size-1; i++) {
        int minPos = i;
        for (int j=i+1; j<size; j++) {
            if (strcmp(products[j].name, products[minPos].name) < 0) {
                minPos = j;
            }
        }
        if(minPos != i) {
            Product tmp;
            memcpy(&tmp, &products[minPos], sizeof(Product));
            memcpy(&products[minPos], &products[i], sizeof(Product));
            memcpy(&products[i], &tmp, sizeof(Product));
        }
    }
}


int main() {
    Product stuffForSale[] = {
      {"Wooden chair", 30, 1250},
      {"Wooden table", 5, 3000},
      {"Glass vase", 34, 1000},
      {"Porcelain bowl", 23, 1450}
    };
    const unsigned int count = 4;
    printProducts(stuffForSale, count);
    
    sortByName(stuffForSale, count);
    cout << "\nSorted by name:" << endl;
    printProducts(stuffForSale, count);
    
    sortByPrice(stuffForSale, count);
    cout << "\nSorted by price:" << endl;
    printProducts(stuffForSale, count);
    
    sortByQuantity(stuffForSale, count);
    cout << "\nSorted by quantity" << endl;
    printProducts(stuffForSale, count);
    return 0;
}