#include <iostream>
#include <vector>
using namespace std;

int remove_array_of_val(vector<int> &a, int val) {
	int i = 0;
	int j = 0;
	int n = a.size();
	for (; i < n; i++) {
		if (a[i] == val)
			continue;
		else if (a[j] == val && a[i] != val)
			swap(a[i], a[j]);
		j++;
	}
	return j;
}

int main()
{
	vector<int> a = {0,1,2,2,3,0,4,2};
	int res = remove_array_of_val(a, 2);
	cout << res << endl;
	return 0;
}
