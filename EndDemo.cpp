#include "EndDemo.hpp"

void EndDemo::init()
{
    vela = new ObjetoDeJogo("Vela - The Last Flame", SpriteAnimado("rsc/vela.anm", 1), 35, 100);

    title = new ObjetoDeJogo("Vela - The Last Flame", Sprite("rsc/TheLastflame-Title.img"), 20, 66);

    objs.push_back(vela);
    objs.push_back(title);
}

unsigned EndDemo::run(SpriteBuffer &screen)
{
    for (int cee = 0; cee < 125; cee++) {
        screen.clear();
        draw(screen);
        system("cls");
        show(screen);
        update();
        Sleep(100);
    }

    return Fase::END_GAME; 
}