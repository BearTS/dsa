#include <climits>
#include <iostream>
#include <cstdbool>
using namespace std;
// Number of vertices in the graph
#define V 9
int minDistance(int dist[], bool sptSet[])
{
 // Initialize min value
 int min = INT_MAX, min_index;
 for (int v = 0; v < V; v++)
 if (sptSet[v] == false && dist[v] <= min)
 min = dist[v], min_index = v;
 return min_index;
}
// A utility function to print the constructed distance array
void printSolution(int dist[])
{
 cout<<"Vertex Distance from Source\n";
 for (int i = 0; i < V; i++)
 if(i<=6){
 cout<<char(i+65)<<"\t\t"<<dist[i]<<"\n";
 }

 else{
 cout<<char(i+78)<<"\t\t"<<dist[i]<<"\n";
 }
}
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
 int dist[V]; // The output array. dist[i] will hold the shortest
 // distance from src to i
 bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
 // path tree or shortest distance from src to i is finalized
 // Initialize all distances as INFINITE and stpSet[] as false
 for (int i = 0; i < V; i++)
 dist[i] = INT_MAX, sptSet[i] = false;
 // Distance of source vertex from itself is always 0
 dist[src] = 0;
 // Find shortest path for all vertices
 for (int count = 0; count < V - 1; count++) {
 // Pick the minimum distance vertex from the set of vertices not
 // yet processed. u is always equal to src in the first iteration.
 int u = minDistance(dist, sptSet);
 // Mark the picked vertex as processed
 sptSet[u] = true;
 // Update dist value of the adjacent vertices of the picked vertex.
 for (int v = 0; v < V; v++)
 // Update dist[v] only if is not in sptSet, there is an edge from
 // u to v, and total weight of path from src to v through u is
 // smaller than current value of dist[v]
 if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
 && dist[u] + graph[u][v] < dist[v])
 dist[v] = dist[u] + graph[u][v];
 }
 printSolution(dist);
}
int main()
{
 cout<<"Name - Raghav Trivedi, Registration number - 21BCE0417"<<endl;
 /*int graph[V][V];
 cout<<"Give 9*9 input or uncomment 2d-matrix";
 for(int i=0; i<V; i++){
 for(int j=0; j<V; j++){
 cin>>graph[i][j];
 }
 }
 //this 2D matrix is for output purpose only input will be taken by for loop given above
 //if you want output, comment out this matrix or give input directly.
 */

 int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 1, 2, 0 },
 { 4, 0, 2, 0, 0, 0, 5, 0, 0 },
 { 0, 2, 0, 0, 6, 4, 0, 0, 2 },
 { 0, 0, 0, 0, 2, 0, 0, 3, 0 },
 { 0, 0, 6, 2, 0, 3, 1, 0, 0 },
 { 0, 0, 4, 0, 3, 0, 3, 0, 5 },
 { 1, 5, 0, 0, 1, 3, 0, 1, 0 },
 { 2, 0, 0, 3, 0, 0, 1, 0, 0 },
 { 0, 0, 2, 0, 0, 5, 0, 0, 0 } };


 dijkstra(graph, 7);
 return 0;
}
