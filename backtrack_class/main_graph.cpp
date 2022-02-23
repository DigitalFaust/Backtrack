#include"graph.h"
#include<iostream>

int main()
{
	combinatorics::Graph g;

	g.read();
	std::cout << "Original graph\n";
	g.write();

	combinatorics::Graph cpg(g);

	std::cout << "\nCopy of the graph\n";
	cpg.write();
	cpg.read();
	cpg.write();

	std::cout << '\n';

	g.write();

	combinatorics::Graph ng;

	ng = cpg;

	std::cout << "\nNew graph\n";
	ng.write();

	ng.read();
	ng.write();

	std::cout << '\n';

	cpg.write();

	return 0;
}
