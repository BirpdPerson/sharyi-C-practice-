#pragma once
#include "PlayerBase.h"
#include "Deck.h"

class Dealer : public PlayerBase
{
public:
	void Move(Deck* deck);
};

