#include <ios>
#include <iostream>
#include <stack>
#include <string>

bool IsUntangled(const std::string& s) {
    std::stack<char> config_stack;
    for (int i = 0; i < s.length(); i++) {
        if (!config_stack.empty() && config_stack.top() == s[i]) {
            config_stack.pop();
        } else {
            config_stack.push(s[i]);
        }
    }
    return config_stack.empty();
}

int main(int argc, char* argv[]) {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // Input
    std::string s;
    std::cin >> s;

    // Output
    std::cout << (IsUntangled(s) ? "Yes" : "No") << '\n';
    return 0;
}