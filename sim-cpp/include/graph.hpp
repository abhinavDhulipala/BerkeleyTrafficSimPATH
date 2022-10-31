# include <vector>
# include <string>

namespace graph {
    using vertex_t = int;
    using weight_t = double;

    using Sink = std::pair<vertex_t, weight_t>;
    using Sinks = std::vector<Sink>;
    using ShortestPath = std::vector<vertex_t>;

    struct Node {
        std::string_view intersection;
        std::pair<double, double> coords;
    };

    // adjecency list is the best representation for this graph as most of the nodes (intersections)
    // are actually between 2-8 edges. Sparse graph, no need for n^2 mem
    class Graph
    { 
    private:
        std::vector<Sinks> edge_list;
        std::vector<Node> node_list;
        size_t num_edges;
    public:
        ShortestPath ShortestPath(vertex_t source, vertex_t sink);
        size_t NumNodes(void);
        size_t NumEdges(void);
        void AddEdge(vertex_t source, vertex_t sink, weight_t weight);
        void UpdateEdge(vertex_t source, vertex_t sink, weight_t weight);
        void RemoveEdge(vertex_t source, vertex_t sink, weight_t weight);
        void AddNode(Node node);
        // from matrix file generate a graph
        Graph FromMtx(std::string_view mtx);
    };

    size_t Graph::NumNodes() {
        return node_list.size();
    }
 
    size_t Graph::NumEdges() {
        return num_edges;
    }

    void Graph::AddNode(Node node) {
        node_list.push_back(node);
    }

    void Graph::AddEdge(vertex_t source, vertex_t sink, weight_t weight) {
        edge_list[source].push_back(std::make_pair(sink, weight));
        num_edges++;
    }

    void Graph::AddNode(Node node) {
        node_list.push_back(node);
        edge_list.push_back(std::vector<Sink>{});
    }
}