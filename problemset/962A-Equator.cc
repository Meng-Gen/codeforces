#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    unsigned long long n;
    unsigned long long a;
    std::vector<unsigned long long> sequence;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        sequence.push_back(a);
    }

    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += sequence[i];
    }

    unsigned long long threshold = (sum + 1) / 2;
    unsigned long long curr = 0;
    for (int i = 0; i < n; i++) {
        curr += sequence[i];
        if (curr >= threshold) {
            std::cout << (i + 1) << std::endl;
            break;
        }
    }

    return 0;
}