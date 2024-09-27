#ifndef FASEINICIAL_HPP
#define FASEINICIAL_HPP

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
#include <algorithm>

#include "MainChar.hpp"

class FaseInicial : public Fase
{
public:
	FaseInicial(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseInicial(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseInicial() {}
	
	
	void init() override;
    unsigned run(SpriteBuffer &screen) override;
	
	bool colideComBloco() const;
	
private:
	MainChar *mainC;
	ObjetoDeJogo *menu;
	ObjetoDeJogo *inventario;
	ObjetoDeJogo *cursorMenu;
	ObjetoDeJogo *cursorInv;
	ObjetoDeJogo *carro_desligado;
	ObjetoDeJogo *carro_ligado;

	std::list<Porta*> portas;
	std::list<ObjetoDeJogo*> tapetesDePorta;
	std::list<OverPorta*> oversDePorta;
	std::list<Item*> itensFase;
	std::list<TextSprite*> spriteSlotsInv;
	std::list<ObjetoDeJogo*> colisoes;
};

#endif // FaseInicial_HPP
