#ifndef MAINCHAR_HPP
#define MAINCHAR_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "SlotInv.hpp"

class MainChar : public ObjetoDeJogo
{
public:
	MainChar(const ObjetoDeJogo &obj, int life=100, int dano=10) : ObjetoDeJogo(obj), life(life), dano(dano) {}

	virtual ~MainChar()	{}
	
	bool isAlive() const { return life != 0; }
	int getLife() const { return life; }
	void curar(int qtdCura) 
	{ 
		this->life = this->life + qtdCura >= 100 ? 100 : this->life + qtdCura;
	}
	int getDano() const { return dano; }
	void setDano(int dano) {this->dano = dano; }
	
	void sofrerAtaque(int ataque) { life = (life - ataque >= 0)?(life - ataque):0; }
	int atacar() const { return dano; }

private:
	int life;
	int dano;
};

#endif // HERO_HPP
