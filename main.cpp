#include "library/Book.h"
#include "library/Library.h"
#include "library/ConsoleBookRepository.h"
#include "library/ConsoleBookNotifier.h"
#include "gilded_rose/ItemUpdater.h"
#include <iostream>

int main() {
    std::cout << "=== PART 1: LIBRARY ===\n";
    ConsoleBookRepository repository;
    ConsoleBookNotifier notifier;
    Library library(repository, notifier);
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));
    std::cout << "Books in library:\n";
    for (const auto& book : library.books()) book.display(std::cout);

    std::cout << "\n=== PART 2: GILDED ROSE KATA ===\n";
    Items items = {
        {"+5 Dexterity Vest", 10, 20},
        {"Aged Brie", 2, 0},
        {"Sulfuras, Hand of Ragnaros", 0, 80},
        {"Backstage passes to a TAFKAL80ETC concert", 5, 45},
        {"Conjured Mana Cake", 3, 6},
        {"Perishable", 2, 10}
    };
    ItemUpdater updater;
    updater.updateQuality(items);
    for (const auto& item : items)
        std::cout << item.name << " | SellIn=" << item.sellIn
                  << " | Quality=" << item.quality << '\n';
    return 0;
}
