#include <iostream>
using namespace std;

#define MAX 10

void DFS(int v, int visited[], int graph[MAX][MAX], int n) {
    visited[v] = 1;
    for(int i = 0; i < n; i++) {
        if(graph[v][i] != 0 && visited[i] == 0)
            DFS(i, visited, graph, n);
    }
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    string city[n];
    cout << "Enter city names:\n";
    for(int i = 0; i < n; i++)
        cin >> city[i];

    int graph[MAX][MAX];
    cout << "\nEnter cost matrix (0 if no flight):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "\nAdjacency Matrix:\n";
    for(int i = 0; i < n; i++) {
        cout << city[i] << ": ";
        for(int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    int visited[MAX] = {0};
    DFS(0, visited, graph, n);

    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            cout << "\nGraph is NOT Connected.\n";
            return 0;
        }
    }

    cout << "\nGraph is Connected.\n";
    return 0;
}


// Enter number of cities: 4
// Enter city names:
// Pune Mumbai Delhi Goa

// Enter cost matrix:
// 0 1 1 0
// 1 0 1 1
// 1 1 0 1
// 0 1 1 0

// Graph is Connected.
