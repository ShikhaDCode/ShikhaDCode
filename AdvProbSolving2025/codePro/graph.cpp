#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Graph class
class Graph {
    int numVertices;                   // Number of vertices
    vector<vector<int>> adjList;       // Adjacency list representation

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);  // Add edge from src to dest
        adjList[dest].push_back(src); // Add edge for undirected graph
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // BFS implementation
    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true; // Mark the starting vertex as visited
        q.push(startVertex);         // Push the starting vertex to the queue

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            // Traverse all neighbors
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Mark neighbor as visited
                    q.push(neighbor);         // Push neighbor to the queue
                }
            }
        }
        cout << endl;
    }

    // DFS implementation (iterative)
    void DFSIterative(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> s;

        s.push(startVertex);

        cout << "DFS Traversal (Iterative): ";
        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = true; // Mark as visited
                cout << current << " ";

                // Push all unvisited neighbors onto the stack
                for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
                }
            }
        }
        cout << endl;
    }

    // DFS implementation (recursive)
    void DFSRecursive(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "DFS Traversal (Recursive): ";
        DFSHelper(startVertex, visited);
        cout << endl;
    }

private:
    void DFSHelper(int vertex, vector<bool>& visited) {
        visited[vertex] = true; // Mark the current vertex as visited
        cout << vertex << " ";

        // Visit all unvisited neighbors
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSHelper(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Graph (Adjacency List):" << endl;
    g.printGraph();

    cout << endl;
    g.BFS(0);              // Perform BFS starting from vertex 0
    g.DFSIterative(0);     // Perform DFS (iterative) starting from vertex 0
    g.DFSRecursive(0);     // Perform DFS (recursive) starting from vertex 0

    return 0;
}
