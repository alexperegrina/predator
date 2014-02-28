#include "Especie.hpp"

Especie::Especie() {
    //id = 0;
    npres = 0;
    valorAlimento = 0;
    minAlimento = 0;
}

Especie::Especie(const Especie& e) {
    id = e.getId();
    npres = getNpres();
    valorAlimento = getValorAliment();
    minAlimento = getMinAlimento();
}
    
void Especie::leer_especie() {
    valorAlimento = readint();
    npres = readint();
    presas = vector<int>(npres);
    for(int i = 0; i < npres; ++i) presas[i] = readint();
    if(npres != 0) minAlimento = readint();
    else minAlimento = 0;
    
}
    
void Especie::modificar_pref() {
    npres = readint();
    for(int i = 0; i < npres; ++i) presas[i] = readint();
}

/*int Especie::getId() {
    return id;
}*/
    
int Especie::getNpres() {
    return npres;
}
    
int Especie::getValorAlimento() {
    return valorAlimento;
}
    
int Especie::getMinAlimento() {
    return minAlimento;
}
    
int Especie::getIessimo(const int &i) {
    return presas[i];
}
