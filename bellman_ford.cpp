#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


vector<int> bellmanFord(int s, int n, int m, vector<pair<int, pair<int, int>>> edges){
    vector<int> distance(n+1,INT_MAX);
    distance[s] = 0;

    for(int i = 1; i <= n-1; i++){
        for(int j = 0; j < m; j++){
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int w = edges[i].first;

            if(distance[u] != INT_MAX && distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
            }
        }
    }

    for(int i = 1; i <= n-1; i++){
        for(int j = 0; j < m; j++){
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int w = edges[i].first;

            if(distance[u] != INT_MAX && distance[u] + w < distance[v]){
                cout<<"Graph contains negative weight cycle"<<endl;
                vector<int> emptyVector;
                return emptyVector;
            }
        }
    }

    return distance;
}

int main()
{
    int n, m;
    cout << "Enter number of nodes";
    cin >> n;
    cout << "Enter number of edges";
    cin >> m;

    cout << "Enter connecting nodes and weight between them" << m << "times" << endl;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_pair(w, make_pair(u, v)));
    }
    
    vector<int> distance = bellmanFord(0,n,m,edges);
    for(int i = 0; i < distance.size(); i++){
        cout<<distance[i]<<" ";
    }
    cout<<endl;
    return 0;
}