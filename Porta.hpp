#ifndef PORTA_HPP
#define PORTA_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Porta : public ObjetoDeJogo
{
public:
	Porta(const ObjetoDeJogo &obj) : ObjetoDeJogo(obj), open(false), trancada(false) {}
	virtual ~Porta()	{}
	
	void abrirPorta() { if (!open) { ObjetoDeJogo::update(); this->open = true;} }
    void fecharPorta() { if (open) { ObjetoDeJogo::update(); this->open = false;} }
	bool isOpen() const { return this->open; }
	bool isTrancada() const {return this->trancada; }

	void destrancar() { this->trancada = false; }
	void trancar() {this->trancada = true; }
	
	virtual void update() { /* porta se mantem estática */ }
	
private:
	bool open;
	bool trancada;
};

#endif // DOOR_HPP