#include"permutations.h"
#include<algorithm>
#include<iostream>
#include<deque>

namespace combinatorics
{
	Permutations::Permutations() : Backtrack() {}

	Permutations::Permutations(std::vector<int> &init_v) : Backtrack(init_v) {}

	bool Permutations::is_solution(int k)
	{
		return v.size() == k;
	}

	void Permutations::process_solution(int k)
	{
		std::for_each(v.begin(), k, [](int &i){ std::cout << i << " "; });
		std::cout << '\n';
	}

	void Permutations::construct_candidates(int k, std::vector<int> &c)
	{
		std::deque<bool> in_sol(v.size());

		std::for_each(in_sol.begin(), in_sol.end(), [](bool &x){ x = false; });
		std::for_each_n(v.begin(), k, [&in_sol](int &x){ in_sol[x - 1] = true; });

		for(int i {0}; i < in_sol.size(); i++)
		{
			if(!in_sol[i])
				c.push_back(i + 1);
		}
	}

	void Permutations::make_move(int k) {}

	void Permutations::unmake_move(int k) {}
}
