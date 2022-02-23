#include"graph.h"
#include<iostream>

namespace combinatorics
{
	Graph::Graph()
	{
		init_graph(false);
	}

	Graph::Graph(bool init_direct)
	{
		init_graph(init_direct);
	}

	Graph::Graph(Graph &init_graph)
	{
		g = new graph;
		g->nvertices = init_graph.g->nvertices;
		g->nedges = init_graph.g->nedges;
		g->directed = init_graph.g->directed;

		for(int i = 0; i < g->nvertices; i++)
		{
			g->degree[i] = init_graph.g->degree[i];
			edgenode *p = init_graph.g->edges[i];
			while(p != nullptr)
			{
				edgenode *cp = new edgenode;
				cp->y = p->y;
				cp->weight = p->weight;
				cp->next = g->edges[i];
				g->edges[i] = cp;
				p = p->next;
			}
		}
	}

	Graph& Graph::operator=(Graph &rght_side)
	{
		g->nvertices = rght_side.g->nvertices;
		g->nedges = rght_side.g->nedges;
		g->directed = rght_side.g->directed;

		delete_edges();
		for(int i {0}; i < rght_side.g->nvertices; i++)
		{
			g->degree[i] = rght_side.g->degree[i];
			edgenode *p = rght_side.g->edges[i];
			while(p != nullptr)
			{
				edgenode *cp = new edgenode;
				cp->y = p->y;
				cp->weight = p->weight;
				cp->next = g->edges[i];
				g->edges[i] = cp;
				p = p->next;
			}
		}

		return *this;
	}

	void Graph::read()
	{
		delete_edges();	
		init_graph(g->directed);

		int x {0}, y {0}, m {0};

		std::cout << "Enter a number of edges: ";
		std::cin >> m;
		std::cout << "Enter a number of vertices: ";
		std::cin >> g->nvertices;

		for(int i = 1; i <= m; i++)
		{
			std::cout << "Enter vertices x and y: ";
			std::cin >> x >> y;
			insert_edge(x, y, g->directed);
		}
	}

	void Graph::write()
	{
		edgenode *p = nullptr;

		for(int i = 0; i < g->nvertices; i++)
		{
			p = g->edges[i];
			std::cout << i << ": ";
			while(p != nullptr)
			{
				std::cout << p->y << " ";
				p = p->next;
			}
			std::cout << '\n';
		}
	}

	graph& Graph::get_g()
	{
		return *g;
	}

	int Graph::get_nvertices()
	{
		return g->nvertices;
	}

	void Graph::insert_edge(int x, int y, bool directed)
	{
		edgenode *p = new edgenode;

		p->y = y;
		p->weight = 0;
		p->next = g->edges[x];
		g->edges[x] = p;
		g->degree[x]++;

		if(!directed)
			insert_edge(y, x, true);
		else
			g->nedges++;
	}

	void Graph::init_graph(bool init_direct)
	{
		g = new graph;
		g->nedges = 0;
		g->nvertices = 0;
		g->directed = init_direct;

		for(int i = 0; i < MAXV; i++)
		{
			g->edges[i] = nullptr;
			g->degree[i] = 0;
		}

	}

	void Graph::delete_edges()
	{
		for(int i = 0; i < g->nvertices; i++)
		{
			edgenode *p = g->edges[i];
			while(p != nullptr)
			{
				edgenode *temp = p;
				p = p->next;
				delete temp;
			}
		}

	}

	Graph::~Graph()
	{
		delete_edges();
		delete g;
	}
}
