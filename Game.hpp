#ifndef GAME_HPP
#define GAME_HPP

#include "Sala.hpp"
#include "FaseInicial.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "CasaChamine.hpp"
#include "MiniCasa.hpp"
#include "EndDemo.hpp"

class Game
{
public:
    Game() {}
    ~Game() { delete mainC; /* Libere outros recursos conforme necessário */ }

    static void run() // Mantendo como estático
    {
        SpriteBuffer buffer(220, 50);
        FaseInicial salaInicial("SalaInicial", Sprite("rsc/HUD_bkg.img"));
        CasaChamine casaChamine("CasaChamine", Sprite("rsc/HUD_bkg.img"));
        MiniCasa miniCasa("MiniCasa", Sprite("rsc/HUD_bkg.img"));
        EndDemo endDemo("EndDemo", Sprite("rsc/HUD_bkg.img"));

        salaInicial.init();
        casaChamine.init();
        miniCasa.init();
        endDemo.init();

        int retornoSala = salaInicial.run(buffer);
        // int retornoSala = casaChamine.run(buffer);

        while (1)
        {
            if (retornoSala == Fase::END_GAME)
            {
                std::cout << "Saindo..." << std::endl;
                break;
            }
            else if (retornoSala == Fase::CASA_CHAMINE)
            {
                buffer.clear();
                retornoSala = casaChamine.run(buffer);
            }
            else if (retornoSala == Fase::FASE_INICIAL)
            {
                buffer.clear();
                retornoSala = salaInicial.run(buffer);
            }
            else if (retornoSala == Fase::MINI_CASA)
            {
                buffer.clear();
                retornoSala = miniCasa.run(buffer);
            }
            else if (retornoSala == Fase::END_DEMO)
            {
                buffer.clear();
                retornoSala = endDemo.run(buffer);
            }
        }
    }

private:
    static MainChar *mainC;         // Declare como estático
    static std::list<Sala *> salas; // Se necessário
};

// Defina o membro estático fora da classe
MainChar *Game::mainC = nullptr;

#endif // GAME_HPP
