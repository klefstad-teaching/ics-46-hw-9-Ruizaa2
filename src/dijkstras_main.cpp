#include "dijkstras.h"
/*
int main() {
    // Create a small test graph
    Graph G;
    G.numVertices = 6; // Example graph with 6 vertices
    G.resize(G.numVertices);

    // Add edges (source, destination, weight)
    G[0].push_back({0, 1, 7});
    G[0].push_back({0, 2, 9});
    G[0].push_back({0, 5, 14});
    G[1].push_back({1, 2, 10});
    G[1].push_back({1, 3, 15});
    G[2].push_back({2, 3, 11});
    G[2].push_back({2, 5, 2});
    G[3].push_back({3, 4, 6});
    G[4].push_back({4, 5, 9});

    int source = 0; // Start from vertex 0

    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    // Print shortest distances from the source node
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < G.numVertices; i++) {
        cout << "To " << i << ": " << distances[i] << endl;
    }

    return 0;
}
*/
int main() {
    string filename = "src/small.txt";  // Hardcoded file name
    Graph G;
    int source;  // Hardcoded source vertex (or read from file if needed)
    cin >> source;
    try {
        file_to_graph(filename, G);
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }


    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    // Print shortest distances from the source vertex
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < G.numVertices; i++) {
        cout << distances[i] << " ";
    }
    cout << "\nTotal cost is " << distances[source] << "\n";  // Autograder format

    return 0;
}