#include<iostream>
#include <list>
#include <stack>
#include <vector>
#include <set>
#define NIL -1
using namespace std;
int cnt = 0;
set< int > bc[ 301000 ];

class Edge
{
    public:
    int u;
    int v;
    Edge(int u, int v);
};
Edge::Edge(int u, int v)
{
    this->u = u;
    this->v = v;
}

// A class that represents an directed graph
class Graph
{
    int V;    // No. of vertices
    int E;    // No. of edges
    list<int> *adj;    // A dynamic array of adjacency lists

    // A Recursive DFS based function used by BCC()
    void BCCUtil(int u, int disc[], int low[],
                 list<Edge> *st, int parent[]);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void BCC();    // prints strongly connected components
};

Graph::Graph(int V)
{
    this->V = V;
    this->E = 0;
    adj = new list<int>[V + 100];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    E++;
}

// A recursive function that finds and prints strongly connected
// components using DFS traversal
// u --> The vertex to be visited next
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
//             discovery time) that can be reached from subtree
//             rooted with current vertex
// *st -- >> To store visited edges
void Graph::BCCUtil(int u, int disc[], int low[], list<Edge> *st,
                    int parent[])
{
    // A static variable is used for simplicity, we can avoid use
    // of static variable by passing a pointer.
    static int time = 0;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
    int children = 0;

    // Go through all vertices adjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of 'u'

        // If v is not visited yet, then recur for it
        if (disc[v] == -1)
        {
            children++;
            parent[v] = u;
            //store the edge in stack
            st->push_back(Edge(u,v));
            BCCUtil(v, disc, low, st, parent);

            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            // Case 1 -- per Strongly Connected Components Article
            low[u]  = min(low[u], low[v]);

            //If u is an articulation point,
            //pop all edges from stack till u -- v
            if( (disc[u] == 1 && children > 1) ||
                (disc[u] > 1 && low[v] >= disc[u]) )
            {
                while(st->back().u != u || st->back().v != v)
                {
                    bc[ cnt ].insert( st->back().u );
                    bc[ cnt ].insert( st->back().v );
                    st->pop_back();
                }
                if( st->size() > 0 ) {
                bc[ cnt ].insert( st->back().u );
                bc[ cnt ].insert( st->back().v );
                st->pop_back();
                }
                cnt++;
            }
        }

        // Update low value of 'u' only of 'v' is still in stack
        // (i.e. it's a back edge, not cross edge).
        // Case 2 -- per Strongly Connected Components Article
        else if(v != parent[u] && disc[v] < low[u])
        {
            low[u]  = min(low[u], disc[v]);
            st->push_back(Edge(u,v));
        }
    }
}

// The function to do DFS traversal. It uses BCCUtil()
void Graph::BCC()
{
    int *disc = new int[V+100];
    int *low = new int[V+100];
    int *parent = new int[V+100];
    list<Edge> *st = new list<Edge>[E+100];

    // Initialize disc and low, and parent arrays
    for (int i = 0; i < V; i++)
    {
        disc[i] = NIL;
        low[i] = NIL;
        parent[i] = NIL;
    }

    for (int i = 0; i < V; i++)
    {
        if (disc[i] == NIL)
            BCCUtil(i, disc, low, st, parent);

        int j = 0;
        //If stack is not empty, pop all edges from stack
        while(st->size() > 0)
        {
            j = 1;
                bc[ cnt ].insert( st->back().u );
                bc[ cnt ].insert( st->back().v );
            st->pop_back();
        }
        if(j == 1)
        {
            cnt++;
        }
    }
}
// Driver program to test above function
int main()
{
    int N, M;
    scanf("%d%d", &N, &M );
    Graph g(N);
    for( int i = 0; i < M; i++ ) {
        int u, v;
        scanf("%d%d", &u, &v );
        u--;
        v--;
        g.addEdge( u, v );
        g.addEdge( v, u );
    }
    g.BCC();
    int visited[ 100100 ] = { 0 };
    for( int i = 0; i < cnt; i++ ) {
        if( bc[ i ].size() > 2 ) {
        for( set< int >::iterator it = bc[ i ].begin(); it != bc[ i ].end(); it++ ) {
                visited[ *it ] = true;
        }
        }
    }
    for( int i = 0; i < N; i++ ) {
        if( !visited[ i ] ) printf("%d\n", i + 1 );
    }
        return 0;
}
