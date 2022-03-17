#include <iostream>
#include <algorithm>
using namespace std;

/* stoi(): string to int 
 * to_string(): int to string
 * */
void func1_string_to_int()
{
	string str = "123";
	int t = stoi(str);
	cout << "\"123\" to " << t << endl;
	t++;
	string t1 = to_string(t);
	cout << "t1=" << t1 << endl;
	
}

int main()
{
	func1_string_to_int();
	return 0;
}
