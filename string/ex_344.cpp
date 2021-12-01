#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s)
{
	for (int i = 0, j = s.size()-1; i < j; i++, j--) {
		swap(s[i], s[j]);
	}
}

int main()
{
	vector<char> s{'h','e','l','l','o'};
	reverseString(s);

	for (auto x : s)
		cout << x <<" ";
	cout <<endl;
	return 0;
}
