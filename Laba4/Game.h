#pragma once
#include <iostream>
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include "IFormattable.h"
#include "Formattable.h"

class Game
{
public:
	Game(Player* player);
	~Game();

	void Play(const float& bet);
	void Dispose();

private:
	Deck* deck;
	Dealer* dealer;
	Player* player;

	void PrettyPrint(IFormattable& format);

	bool IsWinner(const Hand* player, const Hand* dealer);
	bool ExcessScore(const Hand* hand);
};

