#ifndef SUBSETS_H
#define SUBSETS_H

#include"backtrack.h"
using namespace combinatorics;

namespace combinatorics
{
	class Subsets : public Backtrack
	{
		public:
			Subsets();
			Subsets(std::vector<int> &init_v);
		private:
			bool is_solution(int k) override;
			void process_solution(int k) override;
			void construct_candidates(int k, std::vector<int> &c) override;
			void make_move(int k) override;
			void unmake_move(int k) override;
	};
}

#endif //SUBSETS_H
