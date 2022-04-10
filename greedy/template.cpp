#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
namespace std {
	template<typename T>
	ostream& operator<<(ostream& os, vector<T> vec)
	{
		os << "{";
		for (int i = 0; i < vec.size(); i++) {
			if (i != vec.size() - 1)
				os << vec[i] << ", ";
			else
				os << vec[i];
		}
		os << "}";
		return os;
	}
}


int main()
{
	return 0;
}
