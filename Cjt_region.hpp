#ifndef _CJTREGION_HPP_
#define _CJTREGION_HPP_
#include "Region.hpp"
#include "Cjt_especie.hpp"
#include "Arbre.hpp"


/** @class Cjt_region
    @brief Representa un Conjunto de region. 
*/
class Cjt_region {

private:
    /** @brief numero de regiones*/
    int R;
    /** @brief Arbol que contiene la estructura de las regiones*/
    Arbre<int> estruct;
    /** @brief vector de regiones */
    vector<Region> vreg;
    
    /** @brief Lectura de la estructura del arbol de regiones
    *  \pre: marca de parade de lectura de regiones
    *  \post: a contiene la estructura de regiones
    */
    void leer_estructura_arbre(Arbre<int> &a,int marca,int &numreg);
    
    /** @brief Lectura de de las regiones
    * \pre: numesp es el numero de especies 
    * \post: cierto
    */
    void leer_region(const int &numesp);
    
    /** @brief metodo para emigrar a una periferica
    * \pre: Arbol inicializado, 1 <= idreg <= R, 1 <= idesp <= N,  1 <= h <= Region.numesp[].size(), g > 0 
    * \post: cierto  
    */
    void condicio1(Arbre<int> &a,const int &idreg, const int &idesp, const int &h, const int &g);
    
    /** @brief metodo para emigrar a una planicie central
    * \pre: Arbol inicializado, 1 <= idreg <= R, 1 <= idesp <= N,  1 <= h <= Region.numesp[].size(), g > 0 
    * \post: cierto
    */
    void condicio2(Arbre<int> &a,const int &idreg, const int &idesp, const int &h, const int &g);
    
    
    
public:
    //Constructoras
    /** @brief Creadora por defecto. 
    Se ejecuta automaticamente al declarar un Cjt_region.
    \pre: cierto
    \post: es un conjunto de regiones vacio
    */  
    Cjt_region();
    
    //destructora
    ~Cjt_region();
    
    //modificadoras
    
    /** @brief Lectura de la estructura del arbol y de las regiones
    * 
    * \pre: numesp = mida del Cjt_especie
    * \post: cierto
    */
    void leer_regiones(int numesp);
    
    /** @brief migracion de una region a otra de especies(realiza la migracion segun 2 condiciones)
    * \pre: (v == 1 o v == 2), 1 <= idreg <= R, 1 <= idesp <= N,  1 <= h <= Region.numesp[].size(), g > 0 
    * \post: cierto
    */
    void migracion(const int &v,const int &idreg, const int &idesp, const int &h, const int &g);
    
    /** @brief incrementamos el numero de individuos 
    * /pre: m > 0, 1 <= r <= R, 1 <= e <= N
    * /post: cierto
    */
    void anadir_individuos(const int &m,const int &r,const int &e);
    
    
    /** @brief lluita de totes les regions
    * \pre: Cjt_especie inicializado
    * \post: cierto
    */
    void lluita_regions(Cjt_especie &cjtesp);//luego como la lucha esta implementada en el cjt_especie le pasamos por parametro la region
    
    //escritura
    
    /** @brief escritura de les regions amb les especies i els individuus que contenen
    * \pre: cierto
    * \post: cierto
    */
    void escribir_poblacion();
    
};

#endif
