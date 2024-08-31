
#include "graph.hpp"

using namespace std;
int main()
{
    Vector2 graph_size(10, 10);
    Graph graph(graph_size);

    // Add some points to the graph
    graph.add_point(new Vector2(1, 1));
    graph.add_point(new Vector2(2, 3));
    graph.add_point(new Vector2(5, 5));
    graph.add_point(new Vector2(9, 9));
    // graph.add_point(new Vector2(10, 10)); // Out of bounds


    // Display the graph
    cout << graph << endl;
   
    
    return (0);
}
