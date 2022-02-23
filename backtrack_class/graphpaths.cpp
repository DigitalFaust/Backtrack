#include"graphpaths.h"
#include<deque>
#include<iostream>
#include<algorithm>
#include<memory>

namespace combinatorics
{
	Graphpaths::Graphpaths() : Backtrack(), g(false) {}

	Graphpaths::Graphpaths(Graph &init_g) : Backtrack(init_g.get_nvertices()), g(init_g)
	{
		int cnt {0};
		std::for_each(v.begin(), v.end(), [&] (int &x) { x = cnt++; });
	}

	Graph& Graphpaths::get_graph()
	{
		return g;
	}

	void Graphpaths::set_graph(Graph &new_graph)
	{
		int cnt {0};
		g = new_graph;
		v.resize(g.get_nvertices());
		std::for_each(v.begin(), v.end(), [&] (int &x) { x = cnt++; });
	}

	void Graphpaths::set_dest(int new_dest)
	{
		dest = new_dest;
	}

	int Graphpaths::get_dest()
	{
		return dest;
	}

	bool Graphpaths::is_solution(int k)
	{
		return dest == v[k - 1];
	}

	void Graphpaths::process_solution(int k)
	{
		for(int i = 0; i < k; i++)
			std::cout << v[i] << " ";
		std::cout << '\n';
	}

	void Graphpaths::construct_candidates(int k, std::vector<int> &c)
	{
		std::deque<bool> in_sol(v.size());

		std::for_each(in_sol.begin(), in_sol.end(), [] (bool &x) { x = false; });
		std::for_each_n(v.begin(), k, [&in_sol] (int &x) { in_sol[x] = true; });

		if(k == 0)
		{
			c.push_back(0);
		}
		else
		{
			edgenode *p = g.get_g().edges[v[k - 1]];
			while(p != nullptr)
			{
				if(!in_sol[p->y])
					c.push_back(p->y);
				p = p->next;
			}
		}
	}

	void Graphpaths::make_move(int k) {}

	void Graphpaths::unmake_move(int k) {}
}
