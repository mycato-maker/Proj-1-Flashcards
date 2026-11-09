#ifndef CLASS_H
#define CLASS_H
#include <string>
#include <vector>
#include <unordered_map>

struct Flashcards
{
    std::string definition;
    std::string answer;
    std::string result;
}; 

void CardGenerator(int m, std::unordered_map<std::string, Flashcards> &card, std::vector<Flashcards> &cards);

#endif