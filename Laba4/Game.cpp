#include "Game.h"

Game::Game(Player* player)
{
	this->player = player;

	this->dealer = new Dealer();
	this->deck = new Deck();
}

Game::~Game()
{
	delete this->dealer;
	delete this->deck;
}

void Game::Play(const float& bet)
{
	if (player->GetBalance() < bet)
		throw std::exception("Not enough money!");

	this->deck->FillDeck();

	Formattable format;
	std::string command = "";

	deck->Shuffle();

	do
	{
		player->GetHand()->AddCard(deck->GetCard());
		PrettyPrint(format);

		std::cout << "To continue? "; std::cin >> command; std::cout << std::endl;

	} while(command != "no");


	dealer->Move(deck);
	PrettyPrint(format);

	bool playerIsWinner = this->IsWinner(this->player->GetHand(), this->dealer->GetHand());

	if (playerIsWinner)
	{
		std::cout << "You won!"<< std::endl;
		this->player->Award(bet * 2);
	}
	else
	{
		std::cout << "You lost!" << std::endl;
		this->player->Collect(bet);
	}

	std::cout << "Youre balance: " << player->GetBalance() << std::endl << std::endl;
}

bool Game::IsWinner(const Hand* playerHand, const Hand* dealerHand)
{
	if (this->ExcessScore(playerHand))
		return false;

	if (this->ExcessScore(dealerHand))
		return true;

	return playerHand->GetTotal() > dealerHand->GetTotal();
}

bool Game::ExcessScore(const Hand* hand)
{
	return hand->GetTotal() > 21;
}

void Game::Dispose()
{
	this->player->GetHand()->Clear—ards();
	this->dealer->GetHand()->Clear—ards();

	this->deck->Clear—ards();
}

void Game::PrettyPrint(IFormattable& formattable)
{
	std::cout << "Pack:	   " << "[" << deck->GetCount()<< "]" << std::endl;
	std::cout << "Dealer:  " << formattable.Format(dealer->GetHand()->GetCards()) << " : " << dealer->GetHand()->GetTotal() << std::endl;
	std::cout << "You:      " << formattable.Format(player->GetHand()->GetCards()) << " : " << player->GetHand()->GetTotal() << std::endl;
}