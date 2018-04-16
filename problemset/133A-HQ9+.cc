#include <iostream>
#include <string>

bool IsLanguage(std::string program) {
    for (std::string::iterator it = program.begin(); it != program.end(); it++) {
        if (*it == 'H' || *it == 'Q' || *it == '9') {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    std::string program;
    std::cin >> program;
    std::cout << (IsLanguage(program) ? "YES" : "NO") << std::endl;
    return 0;
}