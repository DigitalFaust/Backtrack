#ifndef GRAPHPATHS_H
#define GRAPHPATHS_H

#include<vector>
#include"backtrack.h"
#include"graph.h"

namespace combinatorics
{
	class Graphpaths : public Backtrack
	{
		public:
			Graphpaths();
			Graphpaths(Graph &init_g);
			Graph& get_graph();
			void set_graph(Graph &new_graph);
			void set_dest(int new_dest);
			int get_dest();
		private:
			bool is_solution(int k) override;
			void process_solution(int k) override;
			void construct_candidates(int k, std::vector<int> &c);
			void make_move(int k) override;
			void unmake_move(int k) override;

			Graph g;
			int dest;
	};
}

#endif //GRAPHPATHS_H
