#include<iostream>
#include"subsets.h"

namespace combinatorics
{
	constexpr int init_maxcand = 2;

	Subsets::Subsets() : Backtrack() {}

	Subsets::Subsets(std::vector<int> &init_v) : Backtrack(init_v) {}

	bool Subsets::is_solution(int k)
	{
		return v.size() == k;
	}

	void Subsets::process_solution(int k)
	{
		std::cout << "{ ";
		for(int i = 0; i < k; i++)
			if(v[i])
				std::cout << i + 1 << " ";
		std::cout << "}\n";
	}

	void Subsets::construct_candidates(int k, std::vector<int> &c)
	{
		c.push_back(0);
		c.push_back(1);
	}

	void Subsets::make_move(int k) {}

	void Subsets::unmake_move(int k) {}
}
