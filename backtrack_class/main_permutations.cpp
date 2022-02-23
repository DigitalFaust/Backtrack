#include<iostream>
#include<algorithm>
#include"permutations.h"
#include<string>
using namespace combinatorics;

int main()
{
	Permutations my_set;
	std::vector<int> v;
	std::string prompt {"Enter any char to finish\nEnter a set size: "};

	for(int i {0}; std::cout << prompt && std::cin >> i;)
	{
		v.resize(i);
		int cnt {1};
		std::for_each(v.begin(), v.end(), [&](int &x){ x = cnt++;});
		my_set.set_v(v);
		my_set.backtrack(0);
	}

	return 0;
}
