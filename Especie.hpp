#ifndef _ESPECIE_HPP_
#define _ESPECIE_HPP_
//#include "utils.PRO2"
//#include <list>
//#include <vector>

/** @class Especie
    @brief Representa una Especie. 
*/
class Especie {

private:
    /** @brief Identificador para los individuos */
    int id;
    /** @brief numero de presas */
    int npres;
    /** @brief vector de presas de la especie, preferencias de presas*/
    vector<int> presas; 
    /** @brief valor alimenticio de la especie inicial*/
    int valorAlimento;
    /** @brief valor minimo a consumir de la especie*/
    int minAlimento;

public:
    //Constructoras
    /** @brief Creadora por defecto. 
    Se ejecuta automáticamente al declarar una Especie.
    \pre: cierto
    \post: El resultado es una Especie sin parametros
    */  
    Especie();
    
    /** @brief Creadora copiadora. 
    Permite declarar una Especie nueva como copia de otra ya existente.
    \pre: especie inicializada
    \post: El resultado es una Especie igual que e
    */  
    Especie(const Especie& e);
    
    //Destructora
    /** @brief Destructora. */
    ~Especie();
    
    //Modificadoras
    
    /** @brief Lee los parametros de la Especie
    \pre: ciertos
    \post:  cierto
    */
    void leer_especie();
    
    
    /** @brief modifica las preferencias de presas
    \pre: cierto
    \post:  cierto
    */
    void modificar_pref();
    
    //Consultoras
    
    /** @brief consulta id Especie
    \pre: cierto
    \post:  cierto
    */
     int getId() const;
     
    /** @brief consulta el numero de presas
    \pre: cierto
    \post:  cierto
    */
     int getNpres() const;
     
    /** @brief consulta el Valor Alimenticio
    \pre: cierto
    \post:  cierto
    */
     int getValorAlimento() const;
     
    /** @brief consulta el minimo Alimento a consumir
    \pre: cierto
    \post:  cierto
    */
    int getMinAlimento() const;
    
    /** @brief consulta el iessimo
    \pre: 0 <= i <= N
    \post:  cierto
    */
    int getIessimo(const int &i) const;

};

#endif
