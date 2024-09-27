#include "FaseInicial.hpp"

void FaseInicial::init()
{
	// Criando o objeto do player
	mainC = new MainChar(ObjetoDeJogo("Main_Character", SpriteAnimado("rsc/MainChar.anm", 1), 10, 108));

	// Adicionando as casas da fase
	objs.push_back(new ObjetoDeJogo("Casa_Chamine", Sprite("rsc/casa_chamine.img"), 3, 150));
	colisoes.push_back(objs.back());

	objs.push_back(new ObjetoDeJogo("Mini_Casa", Sprite("rsc/mini_Casa.img"), 3, 2));
	colisoes.push_back(objs.back());

	// Adicionando ambientação (que NÃO cobre o player) e outros...

	objs.push_back(new ObjetoDeJogo("FlorVento_1", SpriteAnimado("rsc/flor_e_grama.anm", 15), 35, 175));

	objs.push_back(new ObjetoDeJogo("FlorVento_2", SpriteAnimado("rsc/flor_e_grama.anm", 12), 41, 4));

	objs.push_back(new ObjetoDeJogo("Grama_e_Pedras_2", SpriteAnimado("rsc/grama_e_pedras.anm", 15), 17, 3));

	// adicionando o carro

	// carro desligado
	carro_desligado = new ObjetoDeJogo("Carro_Desligado", Sprite("rsc/carro_desligado.img"), 35, 50);
	objs.push_back(carro_desligado);
	colisoes.push_back(objs.back());

	// carro ligado
	carro_ligado = new ObjetoDeJogo("Carro_Ligado", SpriteAnimado("rsc/carro_ligado.anm", 1), 35, 50);
	carro_ligado->desativarObj();
	objs.push_back(carro_ligado);

	// Adicionando as portas, tapetes e overs de porta a lista de objetos correspondentes

	// da Casa da Chamine
	oversDePorta.push_back(new OverPorta(ObjetoDeJogo("Porta_casaChamine", SpriteBuffer(1, 1), 14, 172), "CasaChamine"));
	portas.push_back(new Porta(ObjetoDeJogo("Porta_casaChamine", SpriteAnimado("rsc/porta_casaChamine.anm"), 10, 167)));
	tapetesDePorta.push_back(new ObjetoDeJogo("Porta_casaChamine", SpriteBuffer(1, 1), 25, 177));

	// da Mini Casa
	oversDePorta.push_back(new OverPorta(ObjetoDeJogo("Mini_Casa", SpriteBuffer(1, 1), 7, 8), "MiniCasa"));
	portas.push_back(new Porta(ObjetoDeJogo("Mini_Casa", SpriteAnimado("rsc/porta_miniCasa.anm"), 7, 8)));
	portas.back()->trancar();
	tapetesDePorta.push_back(new ObjetoDeJogo("Mini_Casa", SpriteBuffer(1, 1), 18, 13));

	// adicionando os overs aos objetos
	for (auto overDePorta : oversDePorta)
	{
		objs.push_back(overDePorta);
	}

	// adicionando tapetes aos objetos
	for (auto tapeteDePorta : tapetesDePorta)
	{
		objs.push_back(tapeteDePorta);
	}

	// adicionando portas aos objetos
	for (auto porta : portas)
	{
		objs.push_back(porta);
	}

	// Adicionando os slots de inventario a fase
	EstadoGlobal::getInstance().slotsinv.push_back(new SlotInv(ObjetoDeJogo("Slot_1", TextSprite("1. "), 35, 34)));
	EstadoGlobal::getInstance().slotsinv.push_back(new SlotInv(ObjetoDeJogo("Slot_2", TextSprite("2. "), 36, 34)));
	EstadoGlobal::getInstance().slotsinv.push_back(new SlotInv(ObjetoDeJogo("Slot_3", TextSprite("3. "), 37, 34)));
	EstadoGlobal::getInstance().slotsinv.push_back(new SlotInv(ObjetoDeJogo("Slot_4", TextSprite("4. "), 38, 34)));
	EstadoGlobal::getInstance().slotsinv.push_back(new SlotInv(ObjetoDeJogo("Slot_5", TextSprite("5. "), 39, 34)));
	EstadoGlobal::getInstance().slotsinv.push_back(new SlotInv(ObjetoDeJogo("Slot_6", TextSprite("6. "), 40, 34)));
	EstadoGlobal::getInstance().slotsinv.push_back(new SlotInv(ObjetoDeJogo("Slot_7", TextSprite("7. "), 41, 34)));
	EstadoGlobal::getInstance().slotsinv.push_back(new SlotInv(ObjetoDeJogo("Slot_8", TextSprite("8. "), 42, 34)));

	// Adicionando os ponteiros para os sprites de inventário a fase
	for (auto slotInv : EstadoGlobal::getInstance().slotsinv)
	{
		SpriteBase *tmp = const_cast<SpriteBase *>(slotInv->getSprite());
		spriteSlotsInv.push_back(dynamic_cast<TextSprite *>(tmp));
	}

	// adicionando os elementos de menu e inventário
	menu = new ObjetoDeJogo("Menu", Sprite("rsc/menu.img"), 37, 10);
	inventario = new ObjetoDeJogo("Inventario", Sprite("rsc/inventario.img"), 32, 30);

	cursorMenu = new ObjetoDeJogo("Cursor", Sprite("rsc/cursor.img"), 40, 12);
	cursorInv = new ObjetoDeJogo("Cursor", Sprite("rsc/cursor.img"), 35, 32);

	// Adicionando itens ao nível e a lista global de itens
	EstadoGlobal::getInstance().itens.push_back(new ItemCombate(ObjetoDeJogo("Faca de Brinquedo", Sprite("rsc/faca.img"), 14, 27), 15));

	itensFase.push_back(new ItemCombate(ObjetoDeJogo("Faca de Brinquedo", Sprite("rsc/faca.img"), 14, 27), 15));

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

	// colocando o personagem na tela
	objs.push_back(mainC);

	// Adicionando ambientação (que cobre o player) e outros...
	objs.push_back(new ObjetoDeJogo("Cerca_1", Sprite("rsc/cerca.img"), 9, 23));

	objs.push_back(new ObjetoDeJogo("Colisao_Cerca1", SpriteBuffer(36, 1), 16, 23));
	colisoes.push_back(objs.back());

	// Adiciona menu e inventário à lista de objetos
	objs.push_back(menu);
	menu->desativarObj();

	objs.push_back(inventario);
	inventario->desativarObj();

	objs.push_back(cursorMenu);
	cursorMenu->desativarObj();

	objs.push_back(cursorInv);
	cursorInv->desativarObj();

	// Adiciona os slots de inventario à lista de objetos
	for (auto slotInv : EstadoGlobal::getInstance().slotsinv)
	{
		objs.push_back(slotInv);
		slotInv->desativarObj();
	}
}

unsigned FaseInicial::run(SpriteBuffer &screen)
{
	char ent;

	if (EstadoGlobal::getInstance().estavaEm == Fase::CASA_CHAMINE)
	{
		for (auto porta : portas)
		{
			if (porta->getName() == "Porta_casaChamine")
			{
				porta->abrirPorta();
			}
		}

		mainC->setPosL(14);
		mainC->setPosC(172);
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

			mainC->moveDown(1); // movimento em direção à porta
			update();

			// desenha a tela para cada movimento
			screen.clear();
			draw(screen);
			system("cls");
			show(screen);
			Sleep(100); // pequena pausa para suavizar a animação

			if (mainC->getPosL() == 26)
			{
				break;
			}
		}
	}
	else if (EstadoGlobal::getInstance().estavaEm == Fase::MINI_CASA)
	{
		for (auto porta : portas)
		{
			if (porta->getName() == "Mini_Casa")
			{
				porta->abrirPorta();
			}
		}

		mainC->setPosL(7);
		mainC->setPosC(8);
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

			mainC->moveDown(1); // movimento em direção à porta
			update();

			// desenha a tela para cada movimento
			screen.clear();
			draw(screen);
			system("cls");
			show(screen);
			Sleep(80); // pequena pausa para suavizar a animação

			if (mainC->getPosL() == 18)
			{
				break;
			}
		}
	}

	// apos a cutscene, seta o local atual do personagem
	EstadoGlobal::getInstance().estavaEm = Fase::FASE_INICIAL;

	// padrão
	screen.clear();
	draw(screen);
	system("cls");
	show(screen);

	while (true)
	{
		// lendo entrada
		ent = _getch();

		// processando entradas
		int posL = mainC->getPosL(), posC = mainC->getPosC();

		if (ent == 'w' && mainC->getPosL() > 4)
			mainC->moveUp(2);
		else if (ent == 's' && mainC->getPosL() < screen.getAltura() - 13)
			mainC->moveDown(2);
		else if (ent == 'a' && mainC->getPosC() > 4)
			mainC->moveLeft(4);
		else if (ent == 'd' && mainC->getPosC() < screen.getLargura() - mainC->getSprite()->getLargura() - 15)
			mainC->moveRight(4);
		else if (ent == 'z')
		{
			// verifica qual porta está aberta
			for (auto porta : portas)
			{
				if (porta->isOpen())
				{
					// encontra o over correspondente à porta
					for (auto overDePorta : oversDePorta)
					{
						if (porta->getName() == overDePorta->getName())
						{
							// move o personagem em direção à porta
							while (!mainC->colideCom(*overDePorta))
							{
								if (mainC->getPosC() < overDePorta->getPosC())
								{
									mainC->moveRight(1); // movimento mais suave
									update();
								}
								else if (mainC->getPosC() > overDePorta->getPosC())
								{
									mainC->moveLeft(1); // movimento mais suave
									update();
								}

								// movimento vertical quando alinhado horizontalmente
								if (mainC->getPosC() == overDePorta->getPosC())
								{
									mainC->moveUp(1); // movimento em direção à porta
									update();
								}

								// desenha a tela para cada movimento
								screen.clear();
								draw(screen);
								system("cls");
								show(screen);
								Sleep(100); // pequena pausa para suavizar a animação
							}

							// Após o personagem chegar ao overPorta
							if (overDePorta->getName() == "Porta_casaChamine")
							{
								return Fase::CASA_CHAMINE;
							}
							else if (overDePorta->getName() == "Mini_Casa")
							{
								return Fase::MINI_CASA;
							}
							else
							{
								return Fase::END_GAME;
							}
						}
					}
				}
			}
		}
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
							(*itSlot)->setItem(item);								   // Associa o item ao slot
							(*itSprite)->setText(slotNumber + ". " + item->getName()); // Atualiza o sprite do slot com o nome do item
							(*itSlot)->fill();										   // Marca o slot como preenchido
							added = true;											   // Atualiza a variável 'added'
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
						}
					}
					else if (opt == 42)
					{
						return Fase::END_GAME;
					}
				}
			}
		}

		if (mainC->colideCom(*carro_desligado))
		{
			int cont = 0;

			for (auto item : EstadoGlobal::getInstance().itensColetados)
			{
				if (item->getName() == "Galao de Gasolina" || item->getName() == "Chave do Carro")
				{
					cont++;
				}
			}

			if (cont == 2)
			{
				carro_ligado->ativarObj();
				mainC->desativarObj();
				carro_desligado->desativarObj();

				screen.clear();
				draw(screen);
				system("cls");
				show(screen);

				for (int i = 0; i < 15; i++)
				{
					screen.clear();
					draw(screen);
					system("cls");
					show(screen);

					carro_ligado->moveLeft(2);
					update();

					Sleep(80);
				}

				return Fase::END_DEMO;
			}
		}

		if (colideComBloco())
		{
			mainC->moveTo(posL, posC);
		}

		for (auto tapeteDePorta : tapetesDePorta)
		{
			if (mainC->colideCom(*tapeteDePorta))
			{
				for (auto porta : portas)
				{
					if (tapeteDePorta->getName() == porta->getName())
					{
						if (porta->isTrancada())
						{
							for (auto item : EstadoGlobal::getInstance().itensColetados)
							{
								if (item->getName() == "Chave do Deposito")
								{
									porta->destrancar();
									porta->abrirPorta();
								}
							}
						}
						else
						{
							porta->abrirPorta();
						}
					}
				}
				break;
			}
			else
			{
				for (auto porta : portas)
				{
					if (tapeteDePorta->getName() == porta->getName())
					{
						porta->fecharPorta();
					}
				}
			}
		}

		// padrão
		screen.clear();
		update();
		draw(screen);
		system("cls");
		// std::cout << mainC->getPosC() << std::endl;
		// std::cout << mainC->getPosL() << std::endl;
		show(screen);
	}
}

bool FaseInicial::colideComBloco() const
{
	for (auto it = colisoes.begin(); it != colisoes.end(); ++it)
		if (mainC->colideCom(**it))
		{
			return true;
		}

	return false;
}
