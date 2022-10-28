# include <vector>
# include <string>

namespace graph {
    struct Edge
    {
        int vertex;
        double weight;
    };
    
    struct Node
    {
        std::string name;
        std::vector<Edge> adjacency_list;
    };
    

    // adjecency list is the best representation for this graph as most of the nodes (intersections)
    // are actually between 2-8 edges. Sparse graph, no need for n^2 mem
    class Graph
    {
    private:
        std::vector<Node> node_list;
        int edges;
    public:
        using ShortestPath = Graph;
        ShortestPath* shortest_path(Node* source, Node* sink);
        int num_nodes(void);
        int num_edges(void);
        
    };

    inline int Graph::num_nodes() {
        return node_list.size();
    }

    inline int Graph::num_edges() {
        return edges;
    }

}