// UEProgrammerTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>

void FindFor—oincidences(const std::string& input, std::unordered_map<char, bool>& output) {
    auto size = input.size();

    char c_symbol = 0;
    for (auto index = 0; index < size; index++) {
            
        c_symbol = std::tolower(input[index]);

        auto it_val = output.find(c_symbol);

        if (it_val == output.end()) {
            output.insert(std::pair<char, bool>(c_symbol, false));
        } else {
            it_val->second = true;
        }
    }
}

void ConvertString(const std::string& input, std::string& output) {
    std::unordered_map<char, bool> coincidences;

    output.reserve(input.size());

    FindFor—oincidences(input, coincidences);

    for (auto it = input.begin(); it != input.end(); it++) {
        if (coincidences[std::tolower(*it)]) {
            output.push_back(')');
        } else {
            output.push_back('(');
        }
    }
}

int main(int argc, char** argv)
{
    int result = 0;

    std::string s_input = "1234144961649126491664162419qwertyu2649261421894689146901Q@^$!#$%^&*()";
    std::string s_output;

    std::cout << "Input:  " << s_input << std::endl;

    ConvertString(s_input, s_output);

    std::cout << "Result: " << s_output << std::endl;

    return result;
}

