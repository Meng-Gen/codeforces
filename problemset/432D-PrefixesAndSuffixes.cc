#include <ios>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> ZAlgorithm(const std::string& s) {
    int n = s.length();
    std::vector<int> z(n);
    int x = 0;
    int y = 0;
    for (int k = 1; k < n; k++) {
        if (y < k) {
            x = k;
            y = k;
            int j = x;
            while (j < n && s[j] == s[j - x]) {
                j++;
            }
            y = j - 1;
            z[k] = y - x + 1;
        } else if (k + z[k - x] <= y) {
            z[k] = z[k - x];
        } else {
            x = k;
            int j = y + 1;
            while (j < n && s[j] == s[j - x]) {
                j++;
            }
            y = j - 1;
            z[k] = y - x + 1;
        }
    }
    z[0] = n;
    return z;
}

std::vector<int> GetTable(const std::vector<int>& z) {
    int n = z.size();
    std::vector<int> counts(n + 1);
    for (int i = 0; i < n; i++) {
        counts[z[i]]++;
    }
    // Accumulate
    for (int i = n - 1; i >= 0; i--) {
        counts[i] += counts[i + 1];
    }
    return counts;
}

int main(int argc, char* argv[]) {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // Input
    std::string s;
    std::cin >> s;

    // Z-Algorithm
    std::vector<int> z = ZAlgorithm(s);
    std::vector<int> table = GetTable(z);

    // Output
    int n = s.length();
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (z[i] == n - i) {
            count++;
        }
    }
    std::cout << count << '\n';
    for (int i = n - 1; i >= 0; i--) {
        if (z[i] == n - i) {
            std::cout << n - i << " " << table[n - i] << '\n';
        }
    }

    return 0;
}