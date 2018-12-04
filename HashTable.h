//
// Created by o2070696 on 04/12/18.
//
//  Le détail du code de la classe template doit être dans le hpp ou dans un fichier avec toute autre extension que .cpp
//
//

#ifndef UNTITLED1_HASHTABLE_H
#define UNTITLED1_HASHTABLE_H

#include <string>
#include <vector>
#include "Emplacement.h"

using namespace std;



template <class V, class W>


class HashTable {

    vector<Emplacement<V, W>> emplacements;
    int n = 50;

public:
    HashTable();
    ~HashTable();
    bool access(const V &cle, W &value);
    bool inserer(const V &cle, const W &valeur);
    bool supprimer(const V & cle);

    V hash(const V &cle);

    int getEmplacementsSize();

};

#endif //UNTITLED1_HASHTABLE_H
template <class V, class W>

        int HashTable<V, W>::getEmplacementsSize() {
            return emplacements.size();
        }

template <class V, class W>
HashTable<V, W>::HashTable() = default;

template <class V, class W>

HashTable<V, W>::~HashTable<V, W>(){

}

template <class V, class W>

V HashTable<V, W>::hash(const V &cle) {

    return cle % n;
}

template <class V, class W>

typename vector<Emplacement<V, W>>::iterator it;

template <class V, class W>

bool HashTable<V, W>::inserer(const V &cle, const W &valeur) {
    V cleTmp = hash(cle);

    for (it<V, W> = emplacements.begin(); it<V, W> < emplacements.end(); ++it<V, W>){
        //cout << "clé :" << it<V, W>.base()->getCle() << " valeur :" << it<V, W>.base()->getValeur() << endl;
        if (it<V, W>.base()->getCle() == cleTmp) {

            Emplacement<V, W> emplacementPrecedent(valeur, cleTmp);
            it<V, W>.base()->setSuivant(&emplacementPrecedent);
            return true;
        }
    }

        Emplacement<V, W> emplacement(cleTmp, valeur);
        if (emplacements.size() > 0) {
            Emplacement<V, W> emplacementPrecedent = emplacements.back();
            emplacementPrecedent.setSuivant(&emplacement);
        }
        emplacements.push_back(emplacement);
        emplacement.setSuivant(nullptr);
        return true;
    }

template <class V, class W>

bool HashTable<V, W>::access(const V &cle, W &value) {
    V cleTmp = hash(cle);
    for (it<V, W> = emplacements.begin(); it<V, W> < emplacements.end(); ++it<V, W>){
        //cout << "clé :" << it<V, W>.base()->getCle() << " valeur :" << it<V, W>.base()->getValeur() << endl;
        if (it<V, W>.base()->getCle() == cleTmp){
            value = it<V, W>.base()->getValeur();
            cout << "La clé est :" << it<V, W>.base()->getCle() << " et la valeur associée est " << it<V, W>.base()->getValeur();
            return true;
        }
    }

        cout << "La clé n'existe pas" << endl;
        return false;

}

template <class V, class W>

bool HashTable<V, W>::supprimer(const V &cle) {
    V cleTmp = hash(cle);
    for (it<V, W> = emplacements.begin(); it<V, W> < emplacements.end(); ++it<V, W>){
        if (it<V, W>.base()->getCle() == cleTmp){
            emplacements.erase(it<V, W>);
            cout << "La clé " << cle << "a été supprimée" << endl;
            return true;
        }
    }
        cout << "La clé n'existe pas" << endl;
        return false;
}





