#include "library/Library.h"
#include "gilded_rose/ItemUpdater.h"
#include <iostream>
#include <stdexcept>
#include <string>

namespace {
int passed = 0;
void check(bool condition, const std::string& name) {
    if (!condition) throw std::runtime_error("FAILED: " + name);
    ++passed;
    std::cout << "[OK] " << name << '\n';
}
class FakeRepository : public IBookRepository {
public: int saves = 0; void save(const Book&) override { ++saves; }
};
class FakeNotifier : public IBookNotifier {
public: int notifications = 0; void notifyNewBook(const Book&) override { ++notifications; }
};
}

int main() {
    try {
        FakeRepository repo; FakeNotifier notifier;
        Library library(repo, notifier);
        library.addBook(Book("Book A", "Author A"));
        check(library.books().size() == 1, "Library stores a new book");
        check(repo.saves == 1, "Repository receives save request");
        check(notifier.notifications == 1, "Notifier receives notification");

        ItemUpdater updater;
        Items normal = {{"Ordinary", 5, 10}}; updater.updateQuality(normal);
        check(normal[0].quality == 9 && normal[0].sellIn == 4, "Normal item decreases by one");
        Items expired = {{"Ordinary", 0, 10}}; updater.updateQuality(expired);
        check(expired[0].quality == 8 && expired[0].sellIn == -1, "Expired normal item decreases by two");
        Items minQuality = {{"Ordinary", 0, 1}}; updater.updateQuality(minQuality);
        check(minQuality[0].quality == 0, "Quality never becomes negative");
        Items brie = {{"Aged Brie", 2, 49}}; updater.updateQuality(brie);
        check(brie[0].quality == 50, "Aged Brie quality increases but is capped at 50");
        Items sulfuras = {{"Sulfuras, Hand of Ragnaros", 0, 80}}; updater.updateQuality(sulfuras);
        check(sulfuras[0].quality == 80 && sulfuras[0].sellIn == 0, "Sulfuras never changes");
        Items backstage = {{"Backstage passes to a TAFKAL80ETC concert", 5, 10}}; updater.updateQuality(backstage);
        check(backstage[0].quality == 13, "Backstage pass gains three within five days");
        Items backstageTen = {{"Backstage passes to a TAFKAL80ETC concert", 10, 10}}; updater.updateQuality(backstageTen);
        check(backstageTen[0].quality == 12, "Backstage pass gains two with ten days remaining");
        Items backstageEleven = {{"Backstage passes to a TAFKAL80ETC concert", 11, 10}}; updater.updateQuality(backstageEleven);
        check(backstageEleven[0].quality == 11, "Backstage pass gains one with more than ten days remaining");
        Items afterShow = {{"Backstage passes to a TAFKAL80ETC concert", 0, 40}}; updater.updateQuality(afterShow);
        check(afterShow[0].quality == 0, "Backstage pass quality drops to zero after event");
        Items conjured = {{"Conjured Mana Cake", 3, 10}}; updater.updateQuality(conjured);
        check(conjured[0].quality == 8, "Conjured item decreases by two");
        Items perishable = {{"Perishable", 2, 10}}; updater.updateQuality(perishable);
        check(perishable[0].quality == 7, "Extension: Perishable decreases by three before expiry");
        Items expiredPerishable = {{"Perishable", 0, 10}}; updater.updateQuality(expiredPerishable);
        check(expiredPerishable[0].quality == 4, "Extension: Perishable decreases by six after expiry");
        std::cout << "\nAll " << passed << " tests passed.\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
