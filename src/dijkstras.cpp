#include "dijkstras.h"
#include <queue>
#include <vector>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int n = G.numVertices;
    if(n == 0) return{};
    
    vector<int> distance(n,INF);      //makes a vector of distance to every vertex from source node
    previous.assign(n,-1);       // keeps track of the path
    vector<bool> visited(n,false);     //makes sure we dont revisit

    //pair is (dist, vertex)
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<> > pq; // greater  turns it into a min heap instead of max heap
    pq.push({0,source}); //insert the first pair into the queue
    distance[source] = 0;            //initizalize the distance with 0 because its the one were starting with

    while(!pq.empty())
    {
        int current = pq.top().second; // second refering to the vertex
        pq.pop();                   

        if(visited[current]) continue; //if visited skip it

        visited[current] = true;

        for(const Edge & e: G[current])
        {
            int currNeighbor = e.dst;
            int neighborWeight = e.weight;

            if(!visited[currNeighbor] && distance[current] + neighborWeight < distance[currNeighbor])   // checks if the current distance for the vertex is larger
            {
                distance[currNeighbor] = distance[current] + neighborWeight;
                previous[currNeighbor] = current;
                pq.push({distance[currNeighbor],currNeighbor});
            }
        }
    }
    return distance;
}


vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){return{};};
void print_path(const vector<int>& v, int total){};