#include <iostream>
#include "HashTable.h"

int main() {
//
// Created by o2070696 on 04/12/18.
//
    HashTable<int, int> hashTable;
    hashTable.inserer(5, 25);
    hashTable.inserer(9, 81);
    hashTable.inserer(21, 441);
    hashTable.inserer(85, 7225);
    hashTable.inserer(4500, 20250000);
    int value = 0;
    cout << hashTable.getEmplacementsSize() << endl;
    hashTable.supprimer(9);
    hashTable.supprimer(22);
    cout << hashTable.getEmplacementsSize() << endl;
    if (hashTable.access(5, value))
        cout << value << endl;
    if (hashTable.access(22, value))
        cout << value << endl;
    hashTable.inserer(6, 35);
    if (hashTable.access(6, value))
        cout << value << endl;



    return 0;
}