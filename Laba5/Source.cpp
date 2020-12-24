#include <iostream>
#include "Lab_5.1/DataManager.cpp"
#include "Lab_5.2/Reader.h"
#include "Lab_5.3-5.4/Book.h"
#include "Lab_5.5/Cache.h"

int main()
{

    DataManager<int> i;
    int mass[3] = { 1, 2, 3 };
    i.push(mass, 3);
    auto value1 = i.peek();

    DataManager<char> c;
    char mass2[3] = { 1, 2, 3 };
    c.push('T');
    auto value2 = c.popLower();

    Reader r;
    auto map = r.reade();

    for (auto mass_it = map.begin(); mass_it != map.end(); ++mass_it)
    {
        std::cout << mass_it->first << ":(" << mass_it->second << ")" << std::endl;
    }


    std::vector<Book> books{ Book("Улисс", "Джеймс Джойс", 2001), Book("Звук и ярость", "Уильям Фолкнер", 2002), Book("Человек-невидимка", "Ральф Эллисон", 2003) };
    std::sort(books.begin(), books.end(), [](Book f, Book l) { return f.year > l.year; });

    for (auto book : books)
    {
        std::cout << book.author << std::endl;
    }

    std::vector<Book>::iterator finder = std::find_if(books.begin(), books.end(), [](Book book)
    {
        if (2001 < book.year && book.year < 2003)
        {
            return true;
        }

        return false;
    });

    int mycount = std::count_if(books.begin(), books.end(), [](Book book) { return book.year > 2009; });


    Cache<int> cache;
    cache.put(1);
    cache.put(2);
    cache.put(3);
    cache += 5;

    Cache<std::string> voc;
    voc.put("ooooo");

    std::cout << voc.contains("o") << std::endl;
    std::cout << cache.contains(5) << std::endl;
}
