#include "score.h"
#include "raylib.h"

#include <iostream>

void Score::draw()
{
    std::string str1 = "Score: ";
    std::string str2 = std::to_string(score);
    const char* finalstr = (str1 + str2).c_str();

    DrawText(finalstr, 20, 20, 20, WHITE);

}

void Score::update(bool collision)
{
    if (collision) {
        score += 1;

        // std::cout << score << std::endl;

    }

}
