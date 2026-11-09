#include <iostream>
#include <string>
#include <unordered_map>
#include <random>
#include <vector>
#include <algorithm>
#include "class.h"

int main(){
    std::unordered_map<std::string, Flashcards> card;
    std::vector<Flashcards> cards = {};

    int m;
    while (true) {
        std::cout << "How many cards?: ";
        std::cin >> m;
        std::cin.ignore();

            if(m >= 1){
                break;
            }
            else{
                std::cout << "just say you dont wanna study gang" << std::endl;
            }
    }

    
    std::string definition;
    std::string answer;

    CardGenerator(m, card, cards);

    int mode;
    while (true)
    {
        std::cout << "Do you want to show answer or definition \ntype 1 for answer, type 2 for definition" << std::endl;
        std::cin >> mode;
        std::cin.ignore();
            if(mode >=1 && mode <=2){
                break;
            }
            else{
                std::cout << "enter a valid mode BITCH" << std::endl;
            }
    }
    


    std::random_device random;
    std::mt19937 rng(random());
    std::shuffle(cards.begin(), cards.end(), rng);


    int score = 0;

    //GIVE ME THE FUCKING DEFINITION BITCH
    if(mode == 1){
        int mode2;

        while (true){
        std::cout << "Multiple Choice or Identification\ntype 1 for Choices, type 2 for Identification" << std::endl;
        std::cin >> mode2;
        std::cin.ignore();
            if(mode2 >=1 && mode2 <=2){
                break;
            }
            else{
                std::cout << "enter a valid mode BITCH" << std::endl;
            }
        }
            
        for(Flashcards &show : cards){
        std::cout << "What is: "<< show.answer << std::endl;
        
        if (mode2 == 1 && m >= 4) {
            char ans;
            definition = show.definition;
            auto correct = std::find_if(cards.begin(), cards.end(), [&](const Flashcards &c){ //honestly dont know how this works dont ping this and the other one, if not needed, only ping if its unnecesarry or broken
                return c.definition == definition;
            });

            std::vector<Flashcards> answers;

            int index = std::distance(cards.begin(), correct);

            for(int i = 2; i >= 0; i--){
                if(i == index){
                        answers.push_back(cards[3]); //this is intentional so stop pinging this, only ping if this actually breaks the code
                }
                else{
                    answers.push_back(cards[i]);
                }
            }
            answers.push_back(cards[index]);

            std::shuffle(answers.begin(), answers.end(), rng);
            auto key = std::find_if(answers.begin(), answers.end(), [&](const Flashcards &k){
                return k.definition == definition;
            });
            int idx = std::distance(answers.begin(), key);

            for(int u = 0; u < 4; u++){
            std::cout << char('a' + u) << ") " << answers[u].definition << std::endl;
            }
            std::cout << " " << std::endl;
            std::cin >> ans;
            std::cin.ignore();

                if(ans - 'a' == idx){
                    std::cout << "correct" << std::endl;
                    score += 1;
                    show.result = "correct";
                }
                else{
                    std::cout << "incorrect, correct answer was " << char('a' + idx) << ") " << answers[idx].definition << std::endl;
                    score += 0;
                    show.result = "incorrect";
                }
                
        }

        else{
            (std::getline(std::cin, definition));

            if(definition == show.definition){
                score += 1;
                show.result = "correct";
                }
            else{
                score += 0;
                show.result = "incorrect";
                }
            }
            
        }
    }

    //pls give me answer :(
    else {
        int mode2;
        
        while (true){
        std::cout << "Multiple Choice or Identification\ntype 1 for Choices, type 2 for Identification" << std::endl;
        std::cin >> mode2;
        std::cin.ignore();
            if(mode2 >=1 && mode2 <=2){
                break;
            }
            else{
                std::cout << "enter a valid mode BITCH" << std::endl;
            }
        }

    for(Flashcards &show : cards){
        std::cout << "What is: "<< show.definition << std::endl;

        if(mode2 == 1 && m >= 4) {
        char ans;
        answer = show.answer;
        auto correct = std::find_if(cards.begin(), cards.end(), [&](const Flashcards &c){ //honestly dont know how this works dont ping this and the other one, if not needed, only ping if its unnecesarry or broken
            return c.answer == answer;
        });

        std::vector<Flashcards> answers;

        int index = std::distance(cards.begin(), correct);

        for(int i = 2; i >= 0; i--){
            if(i == index){
                    answers.push_back(cards[3]); //this is intentional so stop pinging this, only ping if this actually breaks the code
            }
            else{
                answers.push_back(cards[i]);
            }
        }
        answers.push_back(cards[index]);

        std::shuffle(answers.begin(), answers.end(), rng);
        auto key = std::find_if(answers.begin(), answers.end(), [&](const Flashcards &k){
            return k.answer == answer;
        });
        int idx = std::distance(answers.begin(), key);

        for(int u = 0; u < 4; u++){
            std::cout << char('a' + u) << ") " << answers[u].answer << std::endl;
            }
            std::cout << " " << std::endl;
            std::cin >> ans;
            std::cin.ignore();

                if(ans - 'a' == idx){
                    std::cout << "correct" << std::endl;
                    score += 1;
                    show.result = "correct";
                }
                else{
                    std::cout << "incorrect, correct answer was " << char('a' + idx) << ") " << answers[idx].answer << std::endl;
                    score += 0;
                    show.result = "incorrect";
                }

        }

        else{
        (std::getline(std::cin, answer));

        if(answer == show.answer){
            score += 1;
            show.result = "correct";
            }
        else{
            score += 0;
            show.result = "incorrect";
            }
        }
            
        }
    
    }
        
    std::cout << "your score is: " << score << std::endl;
}