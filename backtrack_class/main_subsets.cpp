#include"subsets.h"
#include<algorithm>
#include<iostream>
#include<string>
using std::string;
using std::for_each;
using namespace combinatorics;

int main()
{
	Subsets my_set;
	std::vector<int> v {0};
	my_set.set_v(v);
	string prompt = "To finish enter any char\nEnter a set size: ";
//	int cnt = 1;

//	for_each(v.begin(), v.end(), [&](int &i){ i = cnt++;});
//	for_each(v.begin(), v.end(), [](int &i){ std::cout << i << " "; });

	for(int i {0}; std::cout << prompt && std::cin >> i;)
	{
		my_set.resize(i);
		my_set.backtrack(0);
	}

	return 0;
}
