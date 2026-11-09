#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "class.h"

void CardGenerator(int m, std::unordered_map<std::string, Flashcards> &card, std::vector<Flashcards> &cards) {
        for(int i = 1; i < m + 1; i++){
        std::string n = std::to_string(i);
        card[n] = Flashcards();

        std::cout << "What is the definition?: ";
        std::getline(std::cin, card[n].definition);

        std::cout << "What is the answer?: ";
        std::getline(std::cin, card[n].answer);

        cards.insert(cards.begin() + (i -1), card[n]);
    }
}

void DeckView(const std::vector<Flashcards> &cards) {
    for(size_t i = 0; i < cards.size(); i++){
    std::cout << i + 1 << ") " << cards[i].definition << " - " << cards[i].answer << std::endl;
    }
}