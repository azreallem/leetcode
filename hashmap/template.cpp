#include <iostream>
#include <unordered_map>

using namespace std;

template <typename T>
void print_u (unordered_map<T, T> u)
{
    for (const auto &n : u)
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
}

int func ()
{
    return 0;
}


int main ()
{
    // unordered_map initial
    unordered_map<string, string> u = {
        {"RED","#FF0000"},
        {"GREEN","#00FF00"},
        {"BLUE","#0000FF"}
    };

    func();
    print_u(u);    
    return 0;
}
