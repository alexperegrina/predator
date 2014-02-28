#ifndef _REGION_HPP_
#define _REGION_HPP_
#include "utils.PRO2"
#include <vector>


/** @class Region
    @brief Representa una Region. 
*/
class Region {

private:
    /** @brief vector que contiene el numero de individuos de cada especie*/
    vector<int> vecind;//[cjt_especie.mida()][int]

public:
    //Constructoras
    /** @brief Creadora por defecto. 
    Se ejecuta automáticamente al declarar una Region.
    \pre: cierto
    \post: El resultado es una Region sin parametros
    */  
    Region();
    
    //Destructora
    /** @brief Destructora. */
    ~Region();
    
    //Modificadoras
    
    /** @brief Lee los parametros de la Region
    \pre: numero de especies
    \post:  cierto
    */
    void leer_region(const int &m);
    
    /** @brief incrementamos el numero de individuos 
    * /pre: m > 0, 1 <= e <= N
    * /post: cierto
    */
    void incrementar_especie(const int &m,const int &e);
    
    /** @brief decrementamos el numero de individuos 
    * /pre: m > 0, 1 <= e <= N
    * /post: cierto
    */
    void decrementar_especie(const int &m,const int &e);
    
    /** @brief lluita en la regio
    * \pre: Cjt_especie inicializado
    * \post: cierto
    */
    //void lluita(Cjt_especie &cjtesp);//mejor en cjtespecie
    
    //consultora
     
    //consultar numero de individuos
    /** @brief consulta el numero de individuos de una especie
    * \pre: 1 <= e <= N
    * \post: cierto
    */
    int consultar_num_indiv(const int &e);
    
    //escritura
    
    /** @brief escritura de las especies i els individuus que contenen
    * \pre: cierto
    * \post: cierto
    */
    void escribir_region();


};

#endif
