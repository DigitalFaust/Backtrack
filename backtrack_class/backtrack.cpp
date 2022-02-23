#include"backtrack.h"

namespace combinatorics
{
	Backtrack::Backtrack() : v(0), finished(false) {}

	Backtrack::Backtrack(std::vector<int> &init_v) : v(init_v), finished(false) {}

	Backtrack::Backtrack(int size_v) : v(size_v), finished(false) {}

	void Backtrack::backtrack(int k)
	{
		std::vector<int> c;

		if(is_solution(k))
			process_solution(k);
		else
		{
			k++;
			construct_candidates(k - 1, c);
			for(auto &i : c)
			{
				v[k - 1] = i;
				make_move(k);
				backtrack(k);
				unmake_move(k);
				if(finished) return;
			}
		}
	}

	void Backtrack::set_v(std::vector<int> &new_v)
	{
		v = new_v;
	}

	std::vector<int> Backtrack::get_v()
	{
		return v;
	}

	void Backtrack::resize(int new_size)
	{
		v.resize(new_size);
	}
}
