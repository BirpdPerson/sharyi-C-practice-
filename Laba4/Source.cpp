#include <iostream>
#include "Game.h"

int main()
{

    float balance, bet;

    std::cout << "your balance sheet: "; std::cin >> balance;

    auto player = new Player("PlayerName", balance);
    Game game(player);

    while (true)
    {
        if (player->GetBalance() <= 0.0f)
        {
            std::cout << "Your balance is empty!";
            break;
        }

        std::cout << "Your bet is: "; std::cin >> bet;
        std::cout << std::endl;

        try
        {
            game.Play(bet);
            game.Dispose();
        }
        catch (const std::exception& ex)
        {
            std::cout << ex.what() << std::endl;

            game.Dispose();
            break;
        }
    }

    delete player;
}
