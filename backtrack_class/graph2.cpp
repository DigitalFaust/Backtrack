#include<iostream>
#include<memory>
#include<vector>

constexpr int MAXV = 100;

struct edgenode
{
	int y;
	int weight;
	std::unique_ptr<edgenode> next;
	edgenode() : y(0), weight(0) {};
};

struct graph
{
	std::vector<std::unique_ptr<edgenode>> edges;
	std::vector<int> degree;
	int nedges;
	int nvertices;
	bool directed;
	graph() : edges(MAXV), degree(MAXV), nedges(0), nvertices(0), directed(false) {};
};

class Graph
{
	public:
		Graph();
		Graph(bool init_direct);
		void read();
		void cwrite();
	private:
		void init_graph(bool directed);
		void insert_edge(int x, int y, bool directed);

		std::unique_ptr<graph> g;
};

int main()
{
	Graph g;

	g.read();
	g.cwrite();

	return 0;
}

Graph::Graph()
{
	init_graph(false);
}

Graph::Graph(bool init_direct)
{
	init_graph(init_direct);
}

void Graph::read()
{
	int x {0}, y {0}, m {0};

	std::cout << "Enter a number of edges: ";
	std::cin >> m;
	std::cout << "Enter a number of vertices: ";
	std::cin >> g->nvertices;

	for(int i {1}; i <= m; i++)
	{
		std::cout << "Enter vertices x and y: ";
		std::cin >> x >> y;
		insert_edge(x, y, g->directed);
	}
}

void Graph::cwrite()
{
	std::unique_ptr<edgenode> p;

	for(int i {0}; i < g->nvertices; i++)
	{
		p = std::move(g->edges[i]);
		std::cout << i << ": ";
		while(p != nullptr)
		{
			std::cout << p->y << " ";
			p = std::move(p->next);
		}
		std::cout << '\n';
	}
}

void Graph::init_graph(bool directed)
{
	g = std::make_unique<graph>();
	g->directed = directed;
}

void Graph::insert_edge(int x, int y, bool directed)
{
	std::unique_ptr<edgenode> p {new edgenode};

	p->y = y;
	p->weight = 0;
	p->next = std::move(g->edges[x]);
	g->edges[x] = std::move(p);
	g->degree[x]++;

	if(!directed)
		insert_edge(y, x, true);
	else
		g->nedges++;
}
