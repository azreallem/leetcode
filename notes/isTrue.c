/* 0   --> false
 * 非0 --> true
 * */


#include <iostream>
using namespace std;

int main()
{
	int res = 0;
	if (res)
		cout << "if(res) res=" << res << endl;
	if (!res)
		cout << "if(!res) res=" << res << endl;
	res = 1;
	if (res)
		cout << "if(res) res=" << res << endl;
	res = -1;
	if (res)
		cout << "if(res) res=" << res << endl;

	return 0;
}

