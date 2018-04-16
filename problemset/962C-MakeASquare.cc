#include <map>
#include <iostream>
#include <string>
#include <vector>

std::map< int, std::vector<std::string> > square_map;

void InitSquareMap() {
    for (int i = 1; i <= 10; i++) {
        square_map[i] = std::vector<std::string>();
    }

    // Floor[Sqrt[2 * 10^9]] = 44721
    for (unsigned long long i = 1; i <= 44721; i++) {
        std::string literal = std::to_string(i * i);
        int len = literal.length();
        square_map[len].push_back(literal);
    }
}

bool IsSubsequence(std::string s, std::string t) {
    unsigned long long i = 0;
    unsigned long long j = 0;

    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == s.length();
}

int Get(unsigned long long n) {
    std::string literal = std::to_string(n);
    int len = literal.length();
    for (int i = len; i > 0; i--) {
        std::vector<std::string> list = square_map[i];
        int list_size = list.size();
        for (int j = 0; j < list_size; j++) {
            if (IsSubsequence(list[j], literal)) {
                return len - i;
            }
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    InitSquareMap();

    unsigned long long n;
    std::cin >> n;
    std::cout << Get(n) << std::endl;

    return 0;
}