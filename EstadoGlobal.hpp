#ifndef ESTADOGLOBAL_HPP
#define ESTADOGLOBAL_HPP

#include <iostream>
#include <list>
#include "Item.hpp"
#include "ItemMedico.hpp"     
#include "ItemMiscelaneo.hpp"
#include "ItemCombate.hpp"
#include "SlotInv.hpp"

class EstadoGlobal {
public:
    static EstadoGlobal& getInstance() {
        static EstadoGlobal instance;
        return instance;
    }

    std::list<SlotInv*> slotsinv;
    std::list<Item*> itens;
    std::list<Item*> itensColetados;
    int estavaEm;

private:
    EstadoGlobal() {} // Construtor privado para evitar múltiplas instâncias
};

#endif // ESTADOGLOBAL_HPP