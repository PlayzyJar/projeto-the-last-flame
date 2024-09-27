#ifndef CASACHAMINE_HPP
#define CASACHAMINE_HPP

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

class CasaChamine : public Fase
{
public:
	CasaChamine(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	CasaChamine(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~CasaChamine() {}
	
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

#endif // CASACHAMINE_HPP
