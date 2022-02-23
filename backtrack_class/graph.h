#ifndef GRAPH_H
#define GRAPH_H

namespace combinatorics
{
	constexpr int MAXV = 100;

	struct edgenode
	{
		int y;
		int weight;
		edgenode *next;
	};

	struct graph
	{
		edgenode *edges[MAXV];
		int degree[MAXV];
		int nedges;
		int nvertices;
		bool directed;
	};

	class Graph
	{
		public:
			Graph();
			Graph(bool init_direct);
			Graph(Graph &init_graph);
			Graph& operator=(Graph &rght_side);
			void read();
			void write();
			graph& get_g();
			int get_nvertices();
			~Graph();
		private:
			void insert_edge(int x, int y, bool directed);
			void init_graph(bool init_direct);
			void delete_edges();
			graph *g;
	};
}

#endif //GRAPH_H
