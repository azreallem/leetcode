#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool is_contains(string s1, string s2)
{
    unordered_map<char, int> u1;
    for (char c : s2)
        u1[c]++;
    for (char c : s1) {
        if (u1.count(c) == 1 && u1[c] != 0)
            u1[c]--;
        else
            return false;
    }

    return true;
}

int main()
{
    string s1 = "bac";
    string s2 = "aab";
    cout << is_contains(s1, s2) << endl;
    return 0;
}
