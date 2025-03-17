#include "dijkstras.h"
#include <queue>
#include <vector>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int n = G.numVertices;
    vector<int> distance(n,INF);
    previous.resize(n,-1);
    vector<bool> visited(n,false);

    //pair is (dist, vertex)
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; // greater  turns it into a min heap instead of max heap
    pq.push(pair(0,source));
    distance[source] = 0;

    while(!pq.empty())
    {
        int current = pq.top().second; // second refering to the vertex
        pq.pop();

        if(visited[current]) continue;

        visited[current] = true;

        for(const Edge & e: G[current])
        {
            int currNeighbor = e.dst;
            int neighborWeight = e.weight;

            if(!visited[currNeighbor] && distance[current] + neighborWeight < distance[currNeighbor])
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