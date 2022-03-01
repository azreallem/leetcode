#include <iostream>
#include <string>
using namespace std;

string swapstr(string &a) {
	int n = a.size();
	int j = n - 1;

	for (int i = 0; i < n; i++) {
		if (i < j) {
			swap(a[i], a[j]);
			j--;
		} else
			break;
	}
	return a;
}

int main()
{
	string s1 = "hello";
	swapstr(s1);
	cout << s1 << endl;
	return 0;
}
