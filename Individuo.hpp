#ifndef _INDIVIDUO_HPP_
#define _INDIVIDUO_HPP_
//#include "utils.PRO2"

class Individuo {
private:
    /** @brief identificador de individuo*/
    int id;
    /** @brief valor alimenticio del individuo*/
    int valorAliment;
    /** @brief valor consumido del individuo*/
    int consumido;
    
public:
    //Constructoras
    /** @brief Creadora por defecto. 
    
    Se ejecuta automáticamente al declarar un Individuo.
    \pre: cierto
    \post: El resultado es un Individuo sin parametros
    */  
    Individuo();
    
    /** @brief Creadora copiadora. 
    
    Permite declarar un Individuo nuevo como copia de otro ya existente.
    \pre: Individuo inicializado
    \post: El resultado es un Individuo igual que i
    */  
    Individuo(const Individuo& i);
    
    /** @brief Creadora con parametros. 
    
    Permite declarar un Individuo nuevo con parametros establecidos.
    \pre: id > 0, val > 0
    \post: El resultado es un Individuo con los parametros establecidos
    */  
    Individuo(const int &id,const int &val);
    
    //Destructora
    /** @brief Destructora. */
    ~Individuo();
    
    //Modificadoras
    
    /** @brief inserta un valor alimenticio a la variable
    \pre: v > 0
    \post:  cierto
    */
    void setValor(int &v);
    
    /** @brief inserta un valor consumido a la variable
    \pre: c > 0
    \post:  cierto
    */
    void setConsumido(int &c);
    
    /* Consultoras */
   
  /** @brief Consulta del ID del Individuo
      \pre: cierto
      \post: ID del Individuo
  */
  int getId() const;
  
  /** @brief Consulta el valor alimenticio del Individuo
      \pre: cierto
      \post: valor alimenticio
  */
  int getValorAliment() const;
  
  /** @brief Consulta el valor consumido del Individuo
      \pre: cierto
      \post: valor consumido
  */
  int getConsumido() const;  
};


#endif
