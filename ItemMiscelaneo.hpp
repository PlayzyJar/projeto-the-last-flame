#ifndef ITEMMISCELANEO_HPP
#define ITEMMISCELANEO_HPP

#include "Item.hpp"

class ItemMiscelaneo : public Item
{
public:
    ItemMiscelaneo(const ObjetoDeJogo &obj) 
        : Item(obj), descricao("Descrição padrão") {}

    void setDescricao(const std::string &desc) { descricao = desc; }
    std::string getDescricao() const { return descricao; }
    
    virtual void usar() override
    {
        // Implementar a lógica específica para o uso de itens misc.
        std::cout << "Usando " << getNome() << ": " << descricao << std::endl;
    }

private:
    std::string descricao; // Descrição adicional do item
};

#endif // ITEMMISCELANEO_HPP
