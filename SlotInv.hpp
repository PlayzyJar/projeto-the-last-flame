#ifndef SLOTINV_HPP
#define SLOTINV_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Item.hpp"
#include "ASCII_Engine/TextSprite.hpp"
#include <string>

class SlotInv : public ObjetoDeJogo {
public:
    SlotInv(const ObjetoDeJogo &obj) 
        : ObjetoDeJogo(obj), filled(false) {}

    virtual ~SlotInv() {}

    std::string getNome() const { return nome; }
    
    void setNome(const std::string &nome) {
        this->nome = nome;
    }
    
    bool isFilled() const { return filled; }
    void fill() { this->filled = true; }

    void setItem(Item* newItem);

private:
    Item* item;
    std::string nome;
    bool filled;
};

#endif // SLOTINV_HPP