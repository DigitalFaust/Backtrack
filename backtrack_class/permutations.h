#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

#include"backtrack.h"

namespace combinatorics
{
	class Permutations : public Backtrack
	{
		public:
			Permutations();
			Permutations(std::vector<int> &init_v);
		private:
			bool is_solution(int k) override;
			void process_solution(int k) override;
			void construct_candidates(int k, std::vector<int> &c);
			void make_move(int k) override;
			void unmake_move(int k) override;
	};
}

#endif //PERMUTATIONS_H
