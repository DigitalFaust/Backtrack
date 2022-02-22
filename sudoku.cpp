#include<iostream>
#include<cmath>
#include<iomanip>

constexpr int DIMENSION = 9;
constexpr int NCELLS = DIMENSION * DIMENSION;
bool finished = false;

struct point
{
	int x;
	int y;
};

struct boardtype
{
	int m[DIMENSION + 1][DIMENSION + 1];
	int freecells;
	point move[NCELLS + 1];
};

void init_board(boardtype *board);

void next_cell(int &x, int &y, boardtype *board);
void print_board(boardtype *board);
void possible_values(int x, int y, bool possible[], boardtype *board);
void find_square(int x, int y, boardtype *board, int &si, int &sj);

void backtrack(int array[], boardtype *board, int k);
bool is_solution(boardtype *board);
void process_solution(boardtype *board);
void construct_candidates(int k, int cands[], int &ncand, boardtype *board);
void make_move(boardtype *board, int array[], int k);
void unmake_move(boardtype *board, int k);

int main()
{
	boardtype *board {new boardtype};
	int array[NCELLS + 1] {0};

	init_board(board);

	board->m[0][2] = 4;
	board->m[0][4] = 5;
	board->m[0][5] = 3;
	board->m[0][8] = 8;

	board->m[1][0] = 6;
	board->m[1][2] = 8;
	board->m[1][6] = 3;
	board->m[1][7] = 5;

	board->m[2][4] = 2;
	board->m[2][5] = 8;
	board->m[2][6] = 6;
	board->m[2][7] = 7;

	board->m[3][3] = 4;
	board->m[3][5] = 9;
	board->m[3][6] = 5;
	board->m[3][7] = 2;

	board->m[4][0] = 4;
	board->m[4][2] = 6;
	board->m[4][5] = 5;
	board->m[4][7] = 9;

	board->m[5][1] = 8;
	board->m[5][4] = 1;
	board->m[5][6] = 4;
	board->m[5][7] = 3;
	board->m[5][8] = 7;

	board->m[6][0] = 3;
	board->m[6][3] = 8;
	board->m[6][6] = 2;
	board->m[6][7] = 4;

	board->m[7][0] = 8;
	board->m[7][1] = 5;
	board->m[7][2] = 2;
	board->m[7][3] = 1;
	board->m[7][5] = 4;
	board->m[7][6] = 7;
	board->m[7][7] = 6;
	board->m[7][8] = 9;

	board->m[8][2] = 7;
	board->m[8][4] = 6;
	board->m[8][8] = 3;

	board->freecells -= 40;

	print_board(board);

	std::cout << "Finding a solution...\n";

	backtrack(array, board, 0);

	return 0;
}

void init_board(boardtype *board)
{
	for(int i {0}; i < DIMENSION; i++)
	{
		for(int j = 0; j < DIMENSION; j++)
		{
			board->m[i][j] = 0;
		}
	}

	board->freecells = NCELLS;

	for(int i {0}; i < NCELLS; i++)
	{
		board->move[i].x = 0;
		board->move[i].y = 0;
	}
}

void next_cell(int &x, int &y, boardtype *board)
{
	while(board->m[x][y] != 0)
	{
		x = (rand() % 9);
		y = (rand() % 9);
	}
}

void print_board(boardtype *board)
{
	std::cout << '\n';
	for(int i {0}; i < DIMENSION; i++)
	{
		for(int j {0}; j < DIMENSION; j++)
		{
			std::cout << std::setw(3) << board->m[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void possible_values(int x, int y, bool possible[], boardtype *board)
{
	for(int i {0}; i < DIMENSION; i++)
	{
		int vval = board->m[x][i];
		int hval = board->m[i][y];
		if(vval != 0) possible[vval] = false;
		if(hval != 0) possible[hval] = false;
	}
	
	int sx {0}, sy {0}; // positions in a little sqaure
	find_square(x, y, board, sx, sy);

	for(int i {sx}; i <= (sx + 2); i++)
	{
		for(int j {sy}; j <= (sy + 2); j++)
		{
			int val = board->m[i][j];
			if(val != 0) possible[val] = false;
		}
	}
}

void find_square(int x, int y, boardtype *board, int &sx, int &sy)
{
	//sx and sy are the upper-left corner of a little square
	//x and y are position of the square that upper-left corner is (sx, sy)
	sx = 3*(x/3);
	sy = 3*(y/3);
}

void backtrack(int array[], boardtype *board, int k)
{
	int cand[DIMENSION] {0};
	int ncand {0};

	if(is_solution(board))
		process_solution(board);
	else
	{
		k++;
		construct_candidates(k, cand, ncand, board);
		for(int i = 0; i < ncand; i++)
		{
			array[k] = cand[i];
			make_move(board, array, k);
			backtrack(array, board, k);
			if(finished) return;
			unmake_move(board, k);
		}
	}
}

bool is_solution(boardtype *board)
{
	return board->freecells == 0;
}

void process_solution(boardtype *board)
{
	std::cout << "========= The solution is ==========\n";
	print_board(board);
	std::cout << "====================================\n";
	finished = true;
}

void construct_candidates(int k, int cands[], int &ncand, boardtype *board)
{
	int x {0}, y {0};
	bool possible[DIMENSION + 1] {true};

	for(int i {1}; i < DIMENSION + 1; i++)
		possible[i] = true;

	next_cell(x, y, board);
	board->move[k].x = x;
	board->move[k].y = y;
	possible_values(x, y, possible, board);

	ncand = 0;
	for(int i = 1; i <= DIMENSION; i++)
	{
		if(possible[i])
			cands[ncand++] = i;
	}
}

void make_move(boardtype *board, int array[], int k)
{
	int x = board->move[k].x;
	int y = board->move[k].y;

	board->m[x][y] = array[k];
	board->freecells -= 1;

	print_board(board);
}

void unmake_move(boardtype *board, int k)
{
	int x = board->move[k].x;
	int y = board->move[k].y;

	board->m[x][y] = 0;
	board->freecells += 1;

	print_board(board);
}
