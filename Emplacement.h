//
// Created by o2070696 on 04/12/18.
//

#ifndef UNTITLED1_EMPLACEMENT_H
#define UNTITLED1_EMPLACEMENT_H


template <class T, class U>

class Emplacement {

    T cle;
    U valeur;
    Emplacement* suivant;

public:

    Emplacement(T key, U value) : cle(key), valeur(value){}
    ~Emplacement();

    T getCle() const{ return cle;}
    U getValeur() const{return valeur;}
    Emplacement *getSuiv() const {return suivant;}

    void setSuivant(Emplacement*);
    void setValeur(U value){valeur = value;}
    void setCle(T key){cle = key;}

};

#endif //UNTITLED1_EMPLACEMENT_H

template <class T, class U>

void Emplacement<T, U>::setSuivant(Emplacement * emp) {
    suivant = emp;
}

template <class T, class U>

Emplacement<T, U>::~Emplacement() = default;