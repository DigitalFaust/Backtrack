#ifndef BACKTRACK_H
#define BACKTRACK_H

#include<vector>

namespace combinatorics
{
	class Backtrack
	{
		public:
			Backtrack();
			Backtrack(std::vector<int> &init_v);
			Backtrack(int v_size);
			void backtrack(int k);
			void set_v(std::vector<int> &new_v);
			std::vector<int> get_v();
			void resize(int new_size);
		protected:
			virtual bool is_solution(int k) = 0;
			virtual void process_solution(int k) = 0;
			virtual void construct_candidates(int k, std::vector<int> &candidts) = 0;
			virtual void make_move(int k) = 0;
			virtual void unmake_move(int k) = 0;

			std::vector<int> v;
			bool finished;
	};
}

#endif //BACKTRACK_H
