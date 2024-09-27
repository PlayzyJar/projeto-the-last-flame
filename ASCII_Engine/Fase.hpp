#ifndef FASE_HPP
#define FASE_HPP

#include "SpriteBase.hpp"
#include "SpriteBuffer.hpp"
#include "ObjetoDeJogo.hpp"
#include "Sprite.hpp"
#include "SpriteAnimado.hpp"
#include <list>
#include <string>
#include <iostream>

//Abstrata
class Fase : public RenderBase
{
public:

	enum {		
		GAME_OVER,
		END_GAME,
		END_DEMO,
		CASA_CHAMINE,
		FASE_INICIAL,
		MINI_CASA		
	};


	Fase(std::string name, const Sprite &bkg) : name(name),background(new Sprite(bkg)) {}
	Fase(std::string name, const SpriteAnimado &bkg) : name(name),background(new SpriteAnimado(bkg)) {}
	virtual ~Fase();
	
	Fase(const Fase &f);
	
	const Fase &operator=(const Fase &);
	
	std::string getName() { return name;}
	
	virtual unsigned run(SpriteBuffer &screen) = 0; //cada derivada tem de implementar sua lógica nesse método
	void show(SpriteBuffer &screen) const {std::cout << screen << std::endl;};
	
	//RenderBase
	virtual void init() = 0;
	virtual void update();
	virtual void draw(SpriteBase &screen, unsigned x = 0, unsigned y = 0);

protected:
	std::string name;
	SpriteBase *background;
	std::list<ObjetoDeJogo*> objs;
};

#endif // FASE_HPP