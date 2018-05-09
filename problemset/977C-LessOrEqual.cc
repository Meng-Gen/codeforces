#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    long long n;
    long long k;
    std::vector<long long> sequence; 
    std::cin >> n >> k;

    for (long long i = 0; i < n; i++) {
        long long a;
        std::cin >> a;
        sequence.push_back(a);
    }

    std::sort(sequence.begin(), sequence.end());

    if (k == n) {
        std::cout << sequence[n - 1] << std::endl;
    } else if (k == 0) {
        if (sequence[0] == 1) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << sequence[0] - 1 << std::endl;
        }
    } else {
        if (sequence[k - 1] == sequence[k]) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << sequence[k - 1] << std::endl;
        }
    }

    return 0;
}