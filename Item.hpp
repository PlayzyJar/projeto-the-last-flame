#ifndef ITEM_HPP
#define ITEM_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Item : public ObjetoDeJogo {
public:
    Item(const ObjetoDeJogo &obj) 
        : ObjetoDeJogo(obj), coletado(false) {}

    virtual ~Item() {}

    virtual void usar() = 0;  // Método virtual puro para o uso do item

    std::string getNome() const { return nome; }
    
    bool isColetado() const { return coletado; }

    void coletar() { coletado = true; }

private:
    std::string nome;
    bool coletado;
};

#endif // ITEM_HPP