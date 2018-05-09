#include <iostream>

long SubtractInWrongWay(long long n) {
    return (n >= 10 && n % 10 == 0) ? n / 10 : n - 1;
}

int main(int argc, char* argv[]) {
    long long n;
    long long k;
    std::cin >> n >> k;

    long long result = n;
    for (long long i = 0; i < k; i++) {
        result = SubtractInWrongWay(result);
    }
    std::cout << result << std::endl;
    return 0;
}