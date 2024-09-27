#include "CasaChamine.hpp"

void CasaChamine::init()
{
    // Criando o objeto do player
    mainC = new MainChar(ObjetoDeJogo("Main_Character", SpriteAnimado("rsc/MainChar_big.anm", 1), 10, 108));

    for (int i = 1; i < 9; i++)
    {
        optsInv.push_back(std::to_string(i) + ". ");
    }

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

    // adicionando paredes

    // parede 1
    objs.push_back(new ObjetoDeJogo("colisao_parede_1", SpriteBuffer(1, 9), 3, 91));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("parede_1", Sprite("rsc/parede_vertical.img"), 3, 90));

    // parede 2
    objs.push_back(new ObjetoDeJogo("colisao_parede_2", SpriteBuffer(21, 1), 30, 1));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("parede_2", Sprite("rsc/parede_horizontal.img"), 30, 1));

    // parede 3
    objs.push_back(new ObjetoDeJogo("colisao_parede_3", SpriteBuffer(21, 1), 30, 42));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("parede_3", Sprite("rsc/parede_horizontal.img"), 30, 42));

    // parede 4
    objs.push_back(new ObjetoDeJogo("colisao_parede_4", SpriteBuffer(21, 1), 30, 66));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("parede_4", Sprite("rsc/parede_horizontal.img"), 30, 66));

    // parede 5
    objs.push_back(new ObjetoDeJogo("colisao_parede_5", SpriteBuffer(1, 9), 30, 91));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("parede_5", Sprite("rsc/parede_vertical.img"), 30, 90));

    // parede 6
    objs.push_back(new ObjetoDeJogo("colisao_parede_6", SpriteBuffer(1, 9), 39, 91));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("parede_6", Sprite("rsc/parede_vertical.img"), 39, 90));

    // parede 7
    objs.push_back(new ObjetoDeJogo("colisao_parede_7", SpriteBuffer(1, 5), 12, 91));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("parede_7", Sprite("rsc/parede_vertical.img"), 12, 90));

    // adicionando ambientação e móveis
    objs.push_back(new ObjetoDeJogo("colisao_balcao", SpriteBuffer(89, 1), 4, 1));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("Balcao_Cozinha", Sprite("rsc/balcao_cozinha.img"), 1, 1));

    objs.push_back(new ObjetoDeJogo("Pia_Cozinha", SpriteAnimado("rsc/pia.anm", 2), 3, 30));

    objs.push_back(new ObjetoDeJogo("Liquidificador", Sprite("rsc/liquidificador.img"), 3, 1));

    objs.push_back(new ObjetoDeJogo("Papel_Toalha", Sprite("rsc/papel_toalha.img"), 3, 60));

    objs.push_back(new ObjetoDeJogo("Tapete_Sala", Sprite("rsc/tapete_sala.img"), 27, 131));

    objs.push_back(new ObjetoDeJogo("colisao_cama", SpriteBuffer(18, 10), 35, 1));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("cama", Sprite("rsc/cama.img"), 32, 1));

    objs.push_back(new ObjetoDeJogo("colisao_rack_sala", SpriteBuffer(40, 1), 7, 93));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("Rack_Sala", Sprite("rsc/rack_sala.img"), 9, 93));

    objs.push_back(new ObjetoDeJogo("Caixa_De_Som", SpriteAnimado("rsc/caixa_de_som.anm", 3), 4, 94));

    objs.push_back(new ObjetoDeJogo("colisao_banquinha", SpriteBuffer(20, 1), 32, 69));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("Banquinha", Sprite("rsc/banquinha.img"), 32, 68));

    objs.push_back(new ObjetoDeJogo("Tapete_Quarto", Sprite("rsc/tapete_quarto.img"), 36, 23));

    // adicionando a nota sobre o deposito (pista da chave)

    notaDeposito = (new ObjetoDeJogo("Sobre o Depósito...", Sprite("rsc/nota.img"), 33, 72));
    objs.push_back(notaDeposito);

    // adicionando a chave do deposito

    EstadoGlobal::getInstance().itens.push_back(new ItemMiscelaneo(ObjetoDeJogo("Chave do Deposito", Sprite("rsc/chave.img"), 15, 158)));

	itensFase.push_back(new ItemMiscelaneo(ObjetoDeJogo("Chave do Deposito", Sprite("rsc/chave.img"), 15, 158)));

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

    // colocando TV da sala
    objs.push_back(new ObjetoDeJogo("colisao_TV", SpriteBuffer(13, 1), 21, 151));
    colisoes.push_back(objs.back());

    objs.push_back(new ObjetoDeJogo("TV_Sala", SpriteAnimado("rsc/TV_sala.anm", 1), 10, 150));

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

    // configurando dialogos
    caixaDialogo = new ObjetoDeJogo("CaixaDialogo", Sprite("rsc/caixa_dialogo.img"), 43, 80); 
    objs.push_back(caixaDialogo);

    caixaDialogo->desativarObj();

    textoDialogo = new ObjetoDeJogo("TextoDialogo", TextSprite(""), 44, 83);
    objs.push_back(textoDialogo);
    
    textoDialogo->desativarObj();

    SpriteBase *tmp = const_cast<SpriteBase *>(textoDialogo->getSprite());
    spriteTextoDialogo = dynamic_cast<TextSprite *>(tmp);
}

unsigned CasaChamine::run(SpriteBuffer &screen)
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

    EstadoGlobal::getInstance().estavaEm = Fase::CASA_CHAMINE;

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
            if (mainC->colideCom(*notaDeposito))
            {
                std::string frase = "As vezes a musica nos leva a lugares esquecidos...";

                caixaDialogo->ativarObj();
                textoDialogo->ativarObj();

                for (int i = 0; i <= frase.size(); i++) {
                    screen.clear();
                    draw(screen);
                    system("cls");
                    show(screen);

                    spriteTextoDialogo->setText(frase.substr(0, i));

                    Sleep(30);
                }

                screen.clear();
                draw(screen);
                system("cls");
                show(screen);

                caixaDialogo->desativarObj();
                spriteTextoDialogo->setText("");
                textoDialogo->desativarObj();

                ent = _getch();
            }

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

bool CasaChamine::colideComBloco() const
{
    for (auto it = colisoes.begin(); it != colisoes.end(); ++it)
        if (mainC->colideCom(**it))
        {
            return true;
        }

    return false;
}
