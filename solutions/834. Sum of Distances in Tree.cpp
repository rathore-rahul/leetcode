class Solution {
public:
    vector<int> nodeCount;
    vector<int> sum;
    vector<vector<int> > graph;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        nodeCount.assign(N,1);
        sum.assign(N,0);
        graph.assign(N, vector<int> ());
        for(int i =0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        return sum;
    }
    
    void dfs1(int node, int par){
        for(int v : graph[node]){
            if(v != par){
                dfs1(v, node);
                nodeCount[node] += nodeCount[v];
                sum[node] += sum[v] + nodeCount[v];
            }
        }
    }
    
    void dfs2(int node, int par){
        for(int v: graph[node]){
            if(v != par){
                sum[v] = sum[node] - nodeCount[v] + nodeCount.size() - nodeCount[v];
                dfs2(v,node);
            }
        }
    }
};
