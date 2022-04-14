#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
namespace std {
	template<typename T>
	ostream& operator<<(ostream& os, vector<T> vec)
	{
		int n = vec.size();
		os << "{";
		for (int i = 0; i < n; i++) {
			if (i != n - 1)
				os << vec[i] << ", ";
			else
				os << vec[i];
		}
		os << "}";
		return os;
	}
}


int monotoneIncreasingDigits(int n)
{
	int a[10] = {0};
	int count = 0;
	while(n) {
		a[count++] = n % 10;
		n /= 10;
	}

	int flag = 0;
	for (int i = 0; i < count; i++) {
		if (flag == 1) {
			if (a[i] != 0) {
			   a[i]--;
			   flag = 0;
			}
		}
		if (i + 1 < count && a[i] < a[i+1]) {
			flag = 1;
			for (int j = 0; j <= i; j++)
				a[j] = 9;
		}
	}

	int res = 0;
	int tmp = 1;
	for (int i = 0; i < count; i++) {
		res += a[i] * tmp;
		if (i != count - 1)
			tmp *= 10; 
	}
	return res;
}





int main()
{
	cout << monotoneIncreasingDigits(332) << endl;
	return 0;
}
