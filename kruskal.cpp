#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findParent(int u, vector<int> parent)
{
    while (u != parent[u])
    {
        u = parent[u];
    }

    return u;
}

void doUnion(int u, int v, vector<int> &parent, vector<int> &size)
{
    if (size[u] > size[v])
        swap(u, v);

    parent[u] = v;
    size[v] += size[u];
}

int kruskal(int n, vector<pair<int, pair<int, int>>> &edges)
{
    vector<int> parent(n);
    vector<int> size(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 0;
    }

    int minWt = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        u = findParent(u, parent);
        v = findParent(v, parent);

        if (u != v)
        {
            minWt += w;
            doUnion(u, v, parent, size);
        }
    }

    return minWt;
}

int main()
{
    int n, m;
    cout << "Enter the number of Nodes : " << endl;
    cin >> n;
    cout << "Enter the number of Edges : " << endl;
    cin >> m;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_pair(w, make_pair(u, v)));
    }

    sort(edges.begin(), edges.end());

    return 0;
}