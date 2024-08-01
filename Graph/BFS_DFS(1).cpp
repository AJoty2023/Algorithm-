#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        this->head = NULL;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);

        if (this->head == NULL) {
            this->head = newNode;
        }
        else {
            Node* currNode = this->head;
            while (currNode->next != NULL) {
                currNode = currNode->next;
            }
            currNode->next = newNode;
        }
    }

    void displayList() {
        if (this->head == NULL) {
            cout << "List is empty!" << endl;
        }
        else {
            Node* currNode = this->head;
            while (currNode != NULL) {
                cout << currNode->data << " ";
                currNode = currNode->next;
            }
            cout << endl;
        }
    }
    Node* getHead() {
        return head;
    }
};

class Graph {
private:
    int V; // number of vertices
    LinkedList *adjList; // adjacency list

public:
    Graph(int V) {
        this->V = V;
        adjList = new LinkedList[V];
    }

    // function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].addNode(v);
        adjList[v].addNode(u); // for an undirected graph
    }

    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " : ";
            adjList[i].displayList();
        }
    }
    void BFS(int start) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int currVertex = q.front();
            cout << currVertex << " ";
            q.pop();

            Node* adj = adjList[currVertex].getHead();
            while (adj != nullptr) {
                int adjVertex = adj->data;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
                adj = adj->next;
            }
        }
    }
    
void dfs(int start, bool visited[]) {
    visited[start] = true;
    cout << start << " ";

    Node* adj = adjList[start].getHead();
    while (adj != nullptr) {
        int adjVertex = adj->data;
        if (!visited[adjVertex]) {
            dfs(adjVertex, visited);
        }
        adj = adj->next;
    }
}

void DFS(int start) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    dfs(start, visited);

    delete[] visited;
}

    
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printAdjList();
cout << "BFS starting from vertex 2: ";
    g.BFS(2);
    cout << endl;
    cout << "DFS starting from vertex 2: ";
    g.DFS(2);
    cout << endl;
    return 0;
}
