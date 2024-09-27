#ifndef MINICASA_HPP
#define MINICASA_HPP

#include "EstadoGlobal.hpp"
#include "ASCII_Engine/Fase.hpp"
#include "Item.hpp"
#include "Porta.hpp"
#include "ItemCombate.hpp"  
#include "SlotInv.hpp"
#include "ItemMedico.hpp"     
#include "ItemMiscelaneo.hpp"  
#include "OverPorta.hpp"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <list>

#include "MainChar.hpp"

class MiniCasa : public Fase
{
public:
	MiniCasa(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	MiniCasa(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~MiniCasa() {}
	
    virtual void init();

	virtual unsigned run(SpriteBuffer &screen) override;
	
	bool colideComBloco() const;
	
private:
    MainChar *mainC;
    ObjetoDeJogo *inventario;
    ObjetoDeJogo *notaDeposito;
    ObjetoDeJogo *menu;
    ObjetoDeJogo *cursorMenu;
    ObjetoDeJogo *cursorInv;
    Porta *porta;
    ObjetoDeJogo *overPorta;
    ObjetoDeJogo *tapetePorta;
    ObjetoDeJogo *caixaDialogo;
    ObjetoDeJogo *textoDialogo;
    TextSprite *spriteTextoDialogo;


	std::list<ObjetoDeJogo*> colisoes;
    std::list<Item*> itensFase;
    std::list<TextSprite*> spriteSlotsInv;
    std::list<std::string> optsInv; 
};

#endif // MINICASA_HPP
