#include "Cjt_especie.hpp"
#include "Especie.hpp"
#include "Region.hpp"

Cjt_especie::Cjt_especie() {
    N = 0;
    C = 0;
    //pude quito estas dos variables de la classe y solo dejo los vectores
    
    ves = vector<Especie>(0);
    pricar = vector<Especie>(0);
        
}
    
Cjt_especie::leer_especies() {
    N = readint();
    C = readint();
    ves = vector<Especie>(N);
    for(int i = 0; i < N; ++i) ves[i].leer_especie();
    pricar = vector<Especie>(C);
    leer_prioridadEspecies();
}
    
void Cjt_especie::leer_prioridadEspecies() {
        for(int i = 0; i < C; ++i) pricar[i] = readint();
}
    
void Cjt_especie::modificar_pref(const int &e) {
    ves[e].modificar_pref();
}

int Cjt_especie::mida() {
    return N;
}


//creo que el primer bucle es para recorre los carnivoros el segundo para recorrer los atacados i dentro comporvaremos si se puede atacar en grupo 
//o hace falta que atacemos uno a uno.




void Cjt_especie::lluita(Region &reg) {
  for(int i = 0; i < C; ++i) {
    nc = reg.consultar_num_indiv(pricar[i]) //numero de atacans en la regio
    while(nc != 0) { //sabem que en la especie almenys hi ha un individuo
      int n = ves[pricar[i]].getNpres();//sabem el numero de presas
      int j = 0;
      bool ple = false;
      int comidonc = 0;
      while(j < n and not ple) {
    	int nind = reg.consultar_num_indiv(ves[pricar[i]].getIessimo(j));//nind = numero de individuos de presas de la especie en la region
    	if(nind > 0) {//sabem si hi ha preses
    	  int alatacat = ves[ves[pricar[i]].getIessimo(j)].getValorAlimento(); //valor alimenticio de la especie atacada
    	  int minataca = ves[pricar[i]].getMinAlimento(); //valor minimo a alimentarse
    	  int natacat = minataca/alatacat;//numero minimo de individuos de esa especie para rellenar el minimo de un atacante
    	  int nalimentados = nind/natacat;//numero maximo de carnivoros que se pueden alimentar
    	  
    	  
    	  if(nc >= nalimentados){
            nc -= nalimentados;
            reg.decrementar_especie(nalimentados,ves[pricar[i]].getIessimo(j));
            if(nc == nalimentados) ple = true;      
          }
          else{
            nc = 0;
            reg.decrementar_especie(nc,ves[pricar[i]].getIessimo(j)); 
            ple = true;
          }
          
          /*if(nc*minataca <= nind*alatacat) {//si lo que me queda de cjt.especie puede alimentarse de lo que queda de presasa atacan todos
    	    reg.decrementar_especie((nc*minataca/nind*alatacat),ves[pricar[i]].getIessimo(j));
    	    nc = 0;
    	    ple = true;
    	  }*/
    	  if(nc != 0) {
    	    if(comidonc != 0) { //significa que he comido de otra especio pero aun no e llegado al minimo
    	      int falt = minataca-comidonc/alatacat;//numero minimo de individuos de esa especie para rellenar el minimo de un atacante
    	      if(falt > nind) {
        		comidonc += nind*alatacat;
        		reg.decrementar_especie(nind,ves[pricar[i]].getIessimo(j));
    	      }
    	      else {
        		reg.decrementar_especie(falt,ves[pricar[i]].getIessimo(j));
        		--nc;
        		ple = true;
    	      }	
    	    }
    	    else if(natacat > nind) {//hay individuos pero no llega al minimo de alimento
    		comidonc = nind*alatacat;
    		reg.decrementar_especie(nind,ves[pricar[i]].getIessimo(j));
    	    }
    	    else { //el atacante nc a podido comer de una atacada de la misma especie
    		reg.decrementar_especie(natacat,ves[pricar[i]].getIessimo(j));
    		--nc;
    		ple = true;
    	    }  
    	  }
    	}
    	++j;
      }
    }
    //si nc != 0 significa que hem recorregut tot el vector de prioritats i no han pogut atacat
    reg.decrementar_especie(nc,pricar[i]);
  }
  
}
//Falta hacer!!!!!!!!!!!!!!! 
void Cjt_especie::lluita(Region &reg) {
  //hacer un empty en el  conjunto de region
  for(int i = 0; i < C; ++i) {
    //Especie ataca = ves[pricar[i]];//especie que ataca (si es necessario cambiamos v[pricar[i]] por ataca)
    int n = ves[pricar[i]].getNpres();//sabem el numero de presas
    bool ple = false;
    int j = 0;
    while(j < n and not ple) {
      //Especie esatacat = ves[ves[pricar[i]].getIessimo(j)];//especie que es atacada (si es necessario cambiamos ves[ves[pricar[i]].getIessimo(j)] por esatacada)
      int nind = reg.consultar_num_indiv(ves[pricar[i]].getIessimo(j));//nind = numero de individuos de presas de la especie en la region
      if(nind > 0) {//sabem si hi ha preses
	int natacat = ves[pricar[i]].getMinAlimento()/ves[ves[pricar[i]].getIessimo(j)].getValorAlimento();//numero minimo de individuos de esa especie para rellenar el minimo
	if(natacat <= nind) { //estic ple
	  ple = true;
	  
	}
	reg.decrementar_especie(natacat,ves[pricar[i]].getIessimo(j));
      }
      ++j;
    }
  }
}
    
