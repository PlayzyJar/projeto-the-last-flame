#ifndef OVERPORTA_HPP
#define OVERPORTA_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include <string>

class OverPorta : public ObjetoDeJogo
{
public:
	OverPorta(const ObjetoDeJogo &obj, const std::string &anchor) : ObjetoDeJogo(obj), anchor(anchor) {}
	virtual ~OverPorta()	{}
	
	std::string getAnchor() {
        return this->anchor;
    }
	
	virtual void update() { }
	
private:
	std::string anchor;
};

#endif // OVEPORTA_HPP