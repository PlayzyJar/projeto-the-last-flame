#ifndef ITEM_COMBATE_HPP
#define ITEM_COMBATE_HPP

#include "Item.hpp"

class ItemCombate : public Item {
public:
    ItemCombate(const ObjetoDeJogo &obj, int dano) 
        : Item(obj), dano(dano) {}

    virtual ~ItemCombate() {}

    void usar() override {
        // Lógica para usar o item de combate
        std::cout << getNome() << " usado! Causou " << dano << " de dano!" << std::endl;
    }

private:
    int dano;
};

#endif // ITEM_COMBATE_HPP
