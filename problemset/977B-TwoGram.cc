#include <map>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    long long n;
    std::string s;
    std::cin >> n >> s;

    std::map<std::string, int> stat_map;
    for (std::string::size_type i = 0; i < s.size() - 1; i++) {
        std::string two_gram = s.substr(i, 2);
        stat_map[two_gram]++;
    }

    long long max_count_so_far = 0;
    std::string max_two_gram_so_far;
    for (std::map<std::string, int>::iterator it = stat_map.begin(); it != stat_map.end(); it++) {
        if (it->second > max_count_so_far) {
            max_count_so_far = it->second;
            max_two_gram_so_far = it->first;
        }
    }
    std::cout << max_two_gram_so_far << std::endl;
    return 0;
}