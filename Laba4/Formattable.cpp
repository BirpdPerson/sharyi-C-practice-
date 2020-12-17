#include "Formattable.h"
#include <iostream>

std::string Formattable::Format(const std::vector<Card*>& cards)
{
    std::string result = "";

    for (auto card : cards)
    {
        result += card->ToString() + " ";
    }

    return result;
}
