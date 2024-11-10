#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    int *Data;
    int noOfVertices;
    bool *visited;
    int **adjMatrix;

public:
    Graph(int numOfVertices);
    void CreateGraph();
    void printadjacent();
    void performDFS();
    void performBFS();
    void DFS(int);
    void BFS(int);
    int *getData();
    void display();
    ~Graph();   
};



Graph::Graph(int numOfVertices) : noOfVertices(numOfVertices) {
    Data = new int[noOfVertices];
    visited = new bool[noOfVertices];
    adjMatrix = new int*[noOfVertices];

    for (int i = 0; i < noOfVertices; i++) {
        adjMatrix[i] = new int[noOfVertices];
        for (int j = 0; j < noOfVertices; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = false;
    }
}

void Graph::CreateGraph() {
    int edges, src, dest;
    cout << "Enter the number of edges: ";
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        cout << "Enter edge (source and destination): ";
        cin >> src >> dest;
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;  // For an undirected graph
    }
}

void Graph::printadjacent() {
    for (int i = 0; i < noOfVertices; i++) {
        cout << "Adjacency list of vertex " << i << ":\n";
        for (int j = 0; j < noOfVertices; j++) {
            if (adjMatrix[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

void Graph::performDFS() {
    cout << "DFS Traversal: ";
    for (int i = 0; i < noOfVertices; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    cout << endl;
}

void Graph::DFS(int v) {
    stack<int> s;
    s.push(v);
    while (!s.empty()) {
        v = s.top();
        s.pop();
        if (!visited[v]) {
            visited[v] = true;
            cout << v << " ";
        }
        for (int i = 0; i < noOfVertices; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                s.push(i);
            }
        }
    }
}

void Graph::performBFS() {
    cout << "BFS Traversal: ";
    for (int i = 0; i < noOfVertices; i++) {
        visited[i] = false; // Reset visited for BFS
    }
    for (int i = 0; i < noOfVertices; i++) {
        if (!visited[i]) {
            BFS(i);
        }
    }
    cout << endl;
}

void Graph::BFS(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        cout << v << " ";
        for (int i = 0; i < noOfVertices; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int* Graph::getData() {
    return Data;
}

void Graph::display() {
    cout << "Graph data: ";
    for (int i = 0; i < noOfVertices; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;
}

Graph::~Graph() {
    delete[] Data;
    delete[] visited;
    for (int i = 0; i < noOfVertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

int main() {
    int numOfVertices;
    cout << "Enter the number of vertices: ";
    cin >> numOfVertices;

    Graph graph(numOfVertices);

    graph.CreateGraph();

    int choice;
    do {
        cout << "\n1. Print Adjacency List";
        cout << "\n2. Perform DFS";
        cout << "\n3. Perform BFS";
        cout << "\n4. Display Graph Data";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                graph.printadjacent();
                break;
            case 2:
                graph.performDFS();
                break;
            case 3:
                graph.performBFS();
                break;
            case 4:
                graph.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

