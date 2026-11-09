#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "class.h"

std::unordered_map<std::string, Flashcards> card;
std::vector<Flashcards> cards = {};


void CardGenerator(int m) {
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

