//#include "utils.PRO2"
#include "Cjt_region.hpp"
#include "Cjt_especie.hpp"
/*#include "Especie.hpp"
#include "Region.hpp"
#include "Individuo.hpp"*/


int main() {
    Cjt_especies cjespecies;
    cjespecies.leer_especies();
    Cjt_regions areaGeo;
    areaGeo.leer_regiones(cjespecies.mida());
    int n = readint();
    while(n == -6) {
        if(n == -1) {
            //lluita
            areaGeo.lluita_regions(cjespecies);
        }
        else if(n == -2) {
            //migraciones
            //v=1 periferica, v=2 planicie central
            int v = readint();
            //1 <= idreg <= (R == areaGeo.mida()); 
            int idreg = readint();
            //1 <= idesp <= (N == cjespecies.mida());
            int idesp = readint();
            int h = readint(); //numeo de individuos que emigran
            int g = readint(); //factor
            areaGeo.migracion(v,idreg,idesp,h,g);//funcion recursiba
        }    
        else if(n == -3) {
            //nacimientos
            int m = readint(); //numero de especies a aumentar m > 0
            int r = readint(); //region a aumentar 1 <= r <= R
            int e = readint(); //1 <= e <= N
	    //cjespecies.anadir(e,m);
            areaGeo.anadir_individos(m,r,e);
        }
        else if(n == -4) {
        //actualizar sus preferencias de presas
            int e = readint(); //especie carnivora
            cjespecies.actualitzar_preferencies(e);//modificamos el vector de preferencias
        }
        else if(n == -5) {
            areaGeo.escribir_poblacion();
            //r1 -> 1 2 5
            //r2 -> 3 6 7
            //...
        }
        n = readint();
    }
}

