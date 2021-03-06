#pragma once
#include <vector>
#include "Card.h"

class Hand
{
public:
	virtual ~Hand();

	void AddCard(Card* card);
	void ClearĐards();

	const std::vector<Card*>& GetCards();
	int GetTotal() const;

private:
	std::vector<Card*> cards;
};

