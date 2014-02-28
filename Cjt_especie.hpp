#ifndef _CJTESPECIE_HPP_
#define _CJTESPECIE_HPP_
#include "Especie.hpp"
#include "Region.hpp"

/** @class Cjt_Especie
    @brief Representa un conjunto de especies. 
*/
class Cjt_especie {

private:
    /** @brief numero de especies*/
    int N;
    /** @brief numero de especies carnivoras*/
    int C;
    /** @brief vector de especies*/
    vector<Especie> ves;
    /** @brief vector de prioridad de especies carnivoras*/
    vector<int> pricar;

public:
    //Constructoras
    
    /** @brief Creadora por defecto. 
    Se ejecuta automaticamente al declarar un Cjt_especie .
    \pre: cierto
    \post: El resultado es un Cjt_especie  vacio
    */  
    Cjt_especie();
    
    //Destructora
    /** @brief Destructora. */
    ~Cjt_especie();
    
    //Modificadoras
    
    /** @brief Lee las especies
    \pre: cierto
    \post: cierto
    */
    void leer_especies();
    
    /** @brief Lee las prioridad especies
    \pre: cierto
    \post: cierto
    */
    void leer_prioridadEspecies();
    
    
    /** @brief modifica las preferencias de una especie(carnivora)
    \pre: 1 <= e <= N, m > 0
    \post: lista con los id
    */
    void modificar_pref(const int &e);
    
    /* Consultoras */
        
    /** @brief Consulta el mida del Cjt_especie
    \pre: cierto
    \post: mida del Cjt_especie
    */
    int mida();
    
    
    //lucha
    /** @brief lluita segons la regio
     * \pre: Region inicialicada
     * \post: cierto
     */
    void lluita(Region &reg);
};

#endif
