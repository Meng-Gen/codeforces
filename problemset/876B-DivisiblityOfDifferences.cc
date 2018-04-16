#include <map>
#include <iostream>
#include <iterator>
#include <vector>

typedef std::map< long long, std::vector<long long> > Map;
typedef std::map< long long, std::vector<long long> >::iterator MapIterator;

int main(int argc, char* argv[]) {
    long long n;
    long long k;
    long long m;
    long long a;
    Map modular_map;

    std::cin >> n >> k >> m;
    for (long long i = 0; i < n; i++) {
        std::cin >> a;
        long long modular_a = a % m;
        if (modular_map.find(modular_a) == modular_map.end()) {
            modular_map[modular_a] = std::vector<long long>();
        }
        modular_map[modular_a].push_back(a);
    }

    for (MapIterator it = modular_map.begin(); it != modular_map.end(); ++it) {
        std::vector<long long> list = it->second;
        if (list.size() >= k) {
            std::cout << "Yes" << std::endl;
            for (int i = 0; i < k; i++) {
                std::cout << list[i];
                if (i != k - 1) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
    return 0;
}