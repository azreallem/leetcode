#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void print_u (unordered_map<string, string> u)
{
    for (const auto &n : u)
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
}

// 示例 1: 输入: s = "anagram", t = "nagaram" 输出: true
// 示例 2: 输入: s = "rat", t = "car" 输出: false
bool is_ectopic (string s, string t)
{
    int records[26] = {0};
    for (char c : s) {
        records[c - 'a'] += 1;
    }
    for (char c : t) {
        records[c - 'a'] -= 1;
    }
    for (int t : records) {
        if (t != 0)
            return false;
    }

    return true;
}


int main ()
{
    string s = "anagram", t = "nagaram";
    cout << is_ectopic(s, t) << endl;

    return 0;
}
