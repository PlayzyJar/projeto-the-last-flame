#include "MiniCasa.hpp"

void MiniCasa::init()
{
    // Criando o objeto do player
    mainC = new MainChar(ObjetoDeJogo("Main_Character", SpriteAnimado("rsc/MainChar_big.anm", 1), 10, 108));


    // Adicionando os ponteiros para os sprites de inventário a fase
    for (auto slotInv : EstadoGlobal::getInstance().slotsinv)
    {
        SpriteBase *tmp = const_cast<SpriteBase *>(slotInv->getSprite());
        spriteSlotsInv.push_back(dynamic_cast<TextSprite *>(tmp));
    }

    // Criando o menu e o cursor do menu
    menu = new ObjetoDeJogo("Menu", Sprite("rsc/menu.img"), 37, 10);
    cursorMenu = new ObjetoDeJogo("Cursor", Sprite("rsc/cursor.img"), 40, 12);

    // Criando o inventário e o cursor do inventário
    inventario = new ObjetoDeJogo("Inventario", Sprite("rsc/inventario.img"), 32, 30);
    cursorInv = new ObjetoDeJogo("Cursor", Sprite("rsc/cursor.img"), 35, 32);

    // adicionando ambientação e tralhas

    // aparador de grama
    objs.push_back(new ObjetoDeJogo("Cortador de Grama", Sprite("rsc/aparador_de_grama.img"), 7, 139));
    colisoes.push_back(objs.back());

    // coruja
    objs.push_back(new ObjetoDeJogo("Coruja", SpriteAnimado("rsc/coruja.anm", 4), 4, 148));
    colisoes.push_back(objs.back());

    // vassoura
    objs.push_back(new ObjetoDeJogo("Vassoura", Sprite("rsc/vassoura.img"), 35, 155));
    colisoes.push_back(objs.back());


    //banquinha
    objs.push_back(new ObjetoDeJogo("Banquinha", SpriteBuffer(20, 1), 3, 42));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("Banquinha", Sprite("rsc/banquinha.img"), 3, 43));
    

    // galao de gasolina
    EstadoGlobal::getInstance().itens.push_back(new ItemMiscelaneo(ObjetoDeJogo("Galao de Gasolina", Sprite("rsc/galao_gasolina.img"), 15, 100)));

	itensFase.push_back(new ItemMiscelaneo(ObjetoDeJogo("Galao de Gasolina", Sprite("rsc/galao_gasolina.img"), 35, 44)));

    // chave do carro
    EstadoGlobal::getInstance().itens.push_back(new ItemMiscelaneo(ObjetoDeJogo("Chave do Carro", Sprite("rsc/chave_carro.img"), 7, 52)));

	itensFase.push_back(new ItemMiscelaneo(ObjetoDeJogo("Chave do Carro", Sprite("rsc/chave_carro.img"), 7, 52)));

    // shadows
    objs.push_back(new ObjetoDeJogo("Shadow_1", Sprite("rsc/shadow_deposito.img"), 3, 1));
    objs.push_back(new ObjetoDeJogo("Shadow_2", Sprite("rsc/shadow_deposito.img"), 3, 165));

    // Adicionando itens da sala a lista de objetos
    for (auto item : EstadoGlobal::getInstance().itens)
    {
        for (auto itemFase : itensFase)
        {
            if (itemFase->getName() == item->getName())
            {
                if (!item->isColetado())
                {
                    objs.push_back(itemFase);
                }
            }
        }
    }

    // Verifica na lista global de itens se foram coletados, se não, adiciona-os a lista de objetos
    for (auto item : EstadoGlobal::getInstance().itens)
    {
        for (auto itemFase : itensFase)
        {
            if (itemFase->getName() == item->getName())
            {
                if (!item->isColetado())
                {
                    objs.push_back(itemFase);
                }
            }
        }
    }

    // Criando a porta, tapete e o over
    porta = new Porta(ObjetoDeJogo("Porta_1", SpriteAnimado("rsc/porta_dentro_casaChamine.anm"), 43, 95));

    tapetePorta = new ObjetoDeJogo("Tapete_porta", SpriteBuffer(1, 1), 41, 99);

    overPorta = new ObjetoDeJogo("OverPorta", SpriteBuffer(1, 1), 46, 97);

    // Adicionando os objetos da porta: tapete, over e porta
    objs.push_back(overPorta);

    objs.push_back(tapetePorta);

    objs.push_back(new ObjetoDeJogo("colisao_Porta", SpriteBuffer(13, 2), 45, 95));
    colisoes.push_back(objs.back());

    objs.push_back(porta);

    objs.push_back(mainC);

    // colocando menu e outras coisas do HUD
    objs.push_back(menu);
    menu->desativarObj();

    objs.push_back(cursorMenu);
    cursorMenu->desativarObj();

    // Adicionando o inventario a lista de objetos
    objs.push_back(inventario);
    inventario->desativarObj();

    objs.push_back(cursorInv);
    cursorInv->desativarObj();

    // Adiciona os slots de inventario à lista de objetos
    for (auto slotInv : EstadoGlobal::getInstance().slotsinv)
    {
        objs.push_back(slotInv);
        slotInv->desativarObj();
    }
}

unsigned MiniCasa::run(SpriteBuffer &screen)
{
    char ent;

    porta->abrirPorta();

    mainC->setPosL(38);
    mainC->setPosC(97);
    update();

    // padrão
    screen.clear();
    draw(screen);
    system("cls");
    show(screen);

    // cutscene do começo do jogo

    // move o personagem em direção à porta
    while (1)
    {

        mainC->moveUp(1); // movimento em direção à porta
        update();

        // desenha a tela para cada movimento
        screen.clear();
        draw(screen);
        system("cls");
        show(screen);
        Sleep(200); // pequena pausa para suavizar a animação

        if (mainC->getPosL() == 32)
        {
            break;
        }
    }

    EstadoGlobal::getInstance().estavaEm = Fase::MINI_CASA;

    while (true)
    {
        // lendo entrada
        ent = _getch();

        // processando entradas
        int posL = mainC->getPosL(), posC = mainC->getPosC();

        if (ent == 'w' && mainC->getPosL() > 4)
            mainC->moveUp(2);
        else if (ent == 's' && mainC->getPosL() < screen.getAltura() - 15)
            mainC->moveDown(2);
        else if (ent == 'a' && mainC->getPosC() > 4)
            mainC->moveLeft(4);
        else if (ent == 'd' && mainC->getPosC() < screen.getLargura() - mainC->getSprite()->getLargura() - 15)
            mainC->moveRight(4);

        else if (ent == 'e')
        {
            for (auto item : itensFase)
            {
                if (mainC->colideCom(*item) && item->isActive())
                {
                    item->desativarObj(); // Desativa o objeto do mapa
                    item->coletar();
                    EstadoGlobal::getInstance().itensColetados.push_back(item);
                    bool added = false;

                    // Itera pelos slots de inventário
                    auto itSlot = EstadoGlobal::getInstance().slotsinv.begin();
                    auto itSprite = spriteSlotsInv.begin();

                    for (; itSlot != EstadoGlobal::getInstance().slotsinv.end() && itSprite != spriteSlotsInv.end(); ++itSlot, ++itSprite)
                    {
                        if (!(*itSlot)->isFilled())
                        {
                            std::string slotNumber = std::to_string(std::distance(EstadoGlobal::getInstance().slotsinv.begin(), itSlot) + 1); // pega o número do slot

                            // Verifica se o slot está vazio
                            (*itSlot)->setItem(item);                                  // Associa o item ao slot
                            (*itSprite)->setText(slotNumber + ". " + item->getName()); // Atualiza o sprite do slot com o nome do item
                            (*itSlot)->fill();                                         // Marca o slot como preenchido
                            added = true;                                              // Atualiza a variável 'added'
                            break;
                        }
                    }

                    // Se o item não foi adicionado, significa que o inventário está cheio
                    if (!added)
                    {
                        std::cout << "Inventário cheio!" << std::endl;
                    }
                    break;
                }
            }
        }
        else if (ent == 'm')
        {
            menu->ativarObj();
            cursorMenu->ativarObj();

            while (1)
            {
                screen.clear();
                draw(screen);
                system("cls");
                show(screen);

                ent = _getch();

                if (ent == 'x')
                {
                    menu->desativarObj();
                    cursorMenu->desativarObj();
                    break;
                }
                else if (ent == 'w' && cursorMenu->getPosL() > 40)
                {
                    cursorMenu->moveUp(1);
                }
                else if (ent == 's' && cursorMenu->getPosL() < 42)
                {
                    cursorMenu->moveDown(1);
                }
                else if (ent == 'z')
                {
                    int opt = cursorMenu->getPosL();

                    if (opt == 40)
                    {
                        menu->desativarObj();
                        cursorMenu->desativarObj();

                        break;
                    }
                    else if (opt == 41)
                    {
                        inventario->ativarObj();
                        cursorInv->ativarObj();

                        for (auto slotInv : EstadoGlobal::getInstance().slotsinv)
                        {
                            slotInv->ativarObj();
                        }

                        while (1)
                        {
                            screen.clear();
                            draw(screen);
                            system("cls");
                            show(screen);

                            ent = _getch();

                            if (ent == 'x')
                            {
                                inventario->desativarObj();
                                cursorInv->desativarObj();

                                for (auto slotInv : EstadoGlobal::getInstance().slotsinv)
                                {
                                    slotInv->desativarObj();
                                }

                                break;
                            }
                            else if (ent == 'w' && cursorInv->getPosL() > 35)
                            {
                                cursorInv->moveUp(1);
                            }
                            else if (ent == 's' && cursorInv->getPosL() < 42)
                            {
                                cursorInv->moveDown(1);
                            }
                            else if (ent == 'z')
                            {
                                // int opt = cursorInv->getPosL(), optOK = 1;

                                // for (int i = 35; i < 43; i++)
                                // {
                                //     if (i == opt)
                                //         break;
                                //     optOK++;
                                // }

                                // for (auto slotInv : EstadoGlobal::getInstance().slotsinv)
                                // {
                                //     if (slotInv->getNome().substr(0, 1) == std::to_string(optOK))
                                //     {
                                //         slotInv->getItem()->usar(*mainC);
                                //     }
                                // }
                            }
                        }
                    }
                    else if (opt == 42)
                    {
                        return Fase::END_GAME;
                    }
                }
            }
        }
        else if (ent == 'z')
        {
            if (porta->isOpen())
            {
                while (!mainC->colideCom(*overPorta))
                {
                    if (mainC->getPosC() < overPorta->getPosC())
                    {
                        mainC->moveRight(1);
                        update();
                    }
                    else if (mainC->getPosC() > overPorta->getPosC())
                    {
                        mainC->moveLeft(1);
                        update();
                    }
                    else
                    {
                        mainC->moveDown(1);
                        update();
                    }

                    screen.clear();
                    draw(screen);
                    system("cls");
                    show(screen);
                    Sleep(200);
                }

                return Fase::FASE_INICIAL;
            }
        }

        if (colideComBloco())
        {
            mainC->moveTo(posL, posC);
        }

        // Verifica se o mainC pisou no tapete da porta
        if (mainC->colideCom(*tapetePorta))
        {
            porta->abrirPorta();
        }
        else
        {
            porta->fecharPorta();
        }

        // padrão
        screen.clear();
        update();
        draw(screen);
        system("cls");
        show(screen);
    }
}

bool MiniCasa::colideComBloco() const
{
    for (auto it = colisoes.begin(); it != colisoes.end(); ++it)
        if (mainC->colideCom(**it))
        {
            return true;
        }

    return false;
}
