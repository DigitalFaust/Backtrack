#include<iostream>
#include"graphpaths.h"
#include<string>

int main()
{
	std::string prompt = "Enter any char to finish\nEnter a destination vertex: ";

	for(int i {0}; std::cout << prompt && std::cin >> i;)
	{
		combinatorics::Graph g;
		g.read();
		g.write();
		combinatorics::Graphpaths gp(g);
		gp.set_dest(i);
		std::cout << "All posible ways to a vertex: " << i << '\n';
		gp.backtrack(0);
	}

	return 0;
}
