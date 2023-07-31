#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class graph
{
public:
    unordered_map<int, vector<pair<int, int>>> adj;

    void addEdge(int u, int v, int w, bool directed)
    {
        adj[u].push_back(make_pair(v, w));
        if (!directed)
        {
            adj[v].push_back(make_pair(u, w));
        }
    }

    void djikstra(int s, int n, int m, unordered_map<int, int> &parent, vector<int> &distance)
    {
        parent[s] = s;
        distance[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push(make_pair(distance[s], s));

        while (!pq.empty())
        {
            int home = pq.top().second;
            pq.pop();

            for (pair<int, int> p : adj[home])
            {
                int nbr = p.first;
                int weight = p.second;
                if (distance[nbr] > distance[home] + weight)
                {
                    distance[nbr] = distance[home] + weight;
                    pq.push(make_pair(distance[s], s));
                    parent[nbr] = home;
                }
            }
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter number of nodes";
    cin >> n;
    cout << "Enter number of edges";
    cin >> m;

    int s;
    cout << "Enter source node";
    cin >> s;

    graph g;

    cout << "Enter connecting nodes and weight between them" << m << "times" << endl;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w, 0);
    }

    vector<int> distance(n + 1, INT_MAX);
    unordered_map<int, int> parent;
    g.djikstra(s, n, m, parent, distance);
    for (int i = 0; i < distance.size(); i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;

    int t;
    cout << "Enter Target Node : " << endl;
    cin >> t;
    int temp = t;
    vector<int> path;
    while (temp != parent[temp])
    {
        temp = parent[temp];
        path.push_back(temp);
    }
    path.push_back(temp);
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }

    cout << endl;
    return 0;
}