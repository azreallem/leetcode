#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void print_u (unordered_map<int, int> u)
{
    for (const auto &n : u)
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
}



vector<int> is_intersect (vector<int> a, vector<int> b)
{
    vector<int> res;
    unordered_map<int, int> records;
    for (const auto &n : a) {
        if (!records.count(n))
            records.insert({n, false});
    }
    for (const auto &n : b) {
        if (records.count(n))
            records[n] = true;
    }
    for (const auto & n : records)
        if (n.second)
            res.push_back(n.first);
    return res;
}


int main ()
{
    vector<int> a = {4, 2, 2, 6, 1, 3}, b = {2, 2, 6, 1, 3};
    vector<int> c = is_intersect(a, b);

    for(const auto &t : c) {
        cout << t << "\t";
    }
    cout << endl;

    return 0;
}
