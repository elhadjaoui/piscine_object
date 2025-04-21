
#include "graph.hpp"

using namespace std;
int main()
{
    Vector2 graph_size(8, 5);
    Graph graph(graph_size);

    // Add some points to the graph
    graph.add_point(new Vector2(1, 1));
    graph.add_point(new Vector2(1, 2));
    graph.add_point(new Vector2(1, 3));
    graph.add_point(new Vector2(1, 4));
    graph.add_point(new Vector2(1, 5));
    graph.add_point(new Vector2(1, 6));
    graph.add_point(new Vector2(1, 7));
    graph.add_point(new Vector2(1, 8));
    graph.add_point(new Vector2(1, 9));
    graph.add_point(new Vector2(2, 1));
    graph.add_point(new Vector2(2, 2));
    graph.add_point(new Vector2(2, 4));
    graph.add_point(new Vector2(2, 5));
    graph.add_point(new Vector2(2, 6));

    cout << "Graph size: " << graph_size << endl;



    // Display the graph
    cout << graph << endl;
   
    
    return (0);
}
