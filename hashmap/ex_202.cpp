#include <iostream>
#include <unordered_map>

using namespace std;

template <typename T>
void print_u (unordered_map<T, T> u)
{
    for (const auto &n : u)
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
}

bool is_happy (int val)
{
    unordered_map<int, bool> records;
 
    while (1) {
        int t = 0;
        while (val != 0) {
            t += (val % 10) * (val % 10);
            val = val / 10;
        }
        val = t;
        cout << val << endl;
        if (val == 1)
            return true;
        if (records[val] == false)
            records[val] = true;
        else
            return false;
    }
}


int main ()
{
    cout << is_happy(2) << endl;
    return 0;
}
