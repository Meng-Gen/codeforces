#include <iostream>

int main(int argc, char* argv[]) {
    unsigned long long n;
    unsigned long long m;
    unsigned long long a;

    std::cin >> n >> m >> a;
    std::cout << ((n + a - 1) / a) * ((m + a - 1) / a) << std::endl;

    return 0;
}