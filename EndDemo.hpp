#ifndef ENDDEMO_HPP
#define ENDDEMO_HPP

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

class EndDemo : public Fase
{
public:
	EndDemo(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	EndDemo(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~EndDemo() {}
	
    virtual void init();

	virtual unsigned run(SpriteBuffer &screen) override;
	
private:
    ObjetoDeJogo *vela;
    ObjetoDeJogo *title;
};

#endif // ENDDEMO_HPP
