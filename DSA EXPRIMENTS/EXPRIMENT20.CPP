// Program to traverse graphs using DFS.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);  // Uncomment this line for an undirected graph
    }

    void dfsTraversal(int startVertex) {
        vector<bool> visited(vertices, false);
        stack<int> s;

        s.push(startVertex);

        cout << "DFS Traversal starting from vertex " << startVertex << ": ";

        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();

            if (!visited[currentVertex]) {
                cout << currentVertex << " ";
                visited[currentVertex] = true;
            }

            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph graph(6); // Create a graph with 6 vertices

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);

    // Perform DFS traversal starting from vertex 0
    graph.dfsTraversal(0);

    return 0;
}