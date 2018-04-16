#include <iostream>
#include <set>
#include <string>

int main(int argc, char* argv[]) {
    std::string letters;
    std::set<char> letter_set;

    std::getline(std::cin, letters);
    for (std::string::iterator it = letters.begin(); it != letters.end(); it++) {
        if (*it == '{' || *it == '}' || *it == ',' || *it == ' ') {
            continue;
        }
        letter_set.insert(*it);
    }

    std::cout << letter_set.size() << std::endl;
    return 0;
}