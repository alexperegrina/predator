#include "Region.hpp"

Region::Region() {
    vecind = vector<int>(0);
}
    
void Region::leer_region(const int &m) {
    vecind = vector<int>(m);
    for(int i = 0; i < m; ++i) {
        vecind[i] = readint();
    }  
}
    
void Region::incrementar_especie(const int &m,const int &e) {
    vecind[e] += m;    
}

void Region::decrementar_especie(const int &m,const int &e){
    vecind[e] -= m;    
}

/*int Region::consultar_num_esp() {
    return vecind.size();
}*/

int Region::consultar_num_indiv(const int &e) {
    return vecind[e];
}
    
void Region::escribir_region() {
    for(int i = 0; i < vecind.size(); ++i) {
        cout << vecind[i] << " ";
    } 
}
