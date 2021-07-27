#include <iostream>
#include <unordered_map>
#include <stack>

int main() {
    std::unordered_map<int, std::stack<int>> stacks;
    int cnt = 0;
    for (auto m: stacks) ++cnt;
    std::cout << cnt << std::endl;
    return 0;
}
