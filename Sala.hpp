#ifndef SALA_HPP
#define SALA_HPP

#include <string>

class Sala {
    public:
        Sala(const std::string &nome) : nome(nome) {}

        std::string getNome() { return this->nome; }

        void setNome(const std::string &nome) { this->nome = nome; }
    private:
        std::string nome;
};

#endif