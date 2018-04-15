#include <iostream>

int main(int argc, char* argv[]) {
    unsigned long long n;

    std::cin >> n;
    std::cout << (((n > 2) && (n % 2 == 0)) ? "YES" : "NO") << std::endl;

    return 0;
}