#ifndef ITEM_MEDICO_HPP
#define ITEM_MEDICO_HPP

#include "Item.hpp"

class ItemMedico : public Item {
public:
    ItemMedico(const ObjetoDeJogo &obj, int cura) 
        : Item(obj), cura(cura) {}

    virtual ~ItemMedico() {}

    void usar() override {
        // Lógica para usar o item médico
        std::cout << getNome() << " usado! Curou " << cura << " pontos de vida!" << std::endl;
    }

private:
    int cura;
};

#endif // ITEM_MEDICO_HPP
