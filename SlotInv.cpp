#include "SlotInv.hpp"

void SlotInv::setItem(Item* newItem) {
    if (newItem != nullptr) {
        item = newItem;

        // Modifica o sprite do slot para mostrar o nome do item
        TextSprite* spriteTexto = const_cast<TextSprite*>(dynamic_cast<const TextSprite*>(getSprite()));
        if (spriteTexto != nullptr) {
            // Define o texto do sprite para o nome do item
            spriteTexto->setText(newItem->getNome());  // getNome() retorna o nome do item
        }
    }
}

