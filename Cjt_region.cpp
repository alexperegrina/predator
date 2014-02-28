#include "Cjt_region.hpp"
#include "Region.hpp"
#include "Cjt_especie.hpp"



//Public
Cjt_region::Cjt_region() {
    R = 0;//pude quito la variable
    vreg = vector<Region>(R);
    Arbre<int> estruct; 
}

void Cjt_region::leer_regiones(int numesp) {   
    R = readint();
    vreg = vector<Region>(R);
    int numreg = 0;//variable per contar el numero de region introduit
    leer_estructura_arbre(estruct,0,numreg);
    leer_region(numesp);
}
    
void Cjt_region::migracion(const int &v,const int &idreg, const int &idesp, const int &h, const int &g);
    
void Cjt_region::anadir_individuos(const int &m,const int &r,const int &e) {
    vreg[r].incrementar_especie(m,e);  
}

void Cjt_region::lluita_regions(Cjt_especie &cjtesp) {
    for(int i = 0; i < vreg.size(); ++i) {
        cjtesp.lluita(vreg[i]);
        //vreg[i].lluita(cjtesp);    
    }
}
    
void Cjt_region::escribir_poblacion() {
    for(int i = 0; i < vreg.size(); ++i) {
        vreg[i].escribir_region();
	cout << endl;
    }    
}

//Private
void Cjt_region::leer_estructura_arbre(Arbre<int> &a,int marca,int &numreg) {
    Arbre<int>a1;
    Arbre<int>a2;
    int x = readint();
    if(x != marca and numreg <= R) {
        ++numreg;
        leer_estructura_arbre(a1,marca,numreg);
        leer_estructura_arbre(a2,marca,numreg);
        a.plantar(x,a1,a2);
    }        
}

void Cjt_region::leer_region(const int &numesp) {
    for(int i = 0; i < vreg.size(); ++i) {
        vreg[i].leer_region(numesp);    
    }
}
    
Cjt_region::condicio1(Arbre<int> &a,const int &idreg, const int &idesp, const int &h, const int &g)
    
Cjt_region::condicio2(Arbre<int> &a,const int &idreg, const int &idesp, const int &h, const int &g)

