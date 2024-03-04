struct LCA {
    int n, lg;
    vector<vector<int>> adj, ancs;
    vector<int> depth;
    LCA(int n): n(n){
        adj.resize(n+1);
        lg = ceil(log2(n));
        ancs.resize(n+1, vector<int>(lg+1));
        depth.resize(n+1, 0);
    }

    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void dfs(int v, int p){
        ancs[v][0] = p;
        for(int i = 1; i <= lg; i++){
            ancs[v][i] = ancs[ancs[v][i-1]][i-1];
        }
        for(auto c: adj[v]){
            if(c^p){
                depth[c] = 1 + depth[v];
                dfs(c, v);
            }
        }
    }

    int lca(int x, int y){
        if(depth[x] < depth[y]){
            swap(x, y);
        }
        for(int i = lg; i>=0; i--){
            if(depth[y] + (1<<i) <= depth[x]){
                x = ancs[x][i];
            }
        }
        if(x==y)
            return x;
        for(int i = lg; i >=0; i--){
            if(ancs[x][i]!=ancs[y][i]){
                x = ancs[x][i];
                y = ancs[y][i];
            }
        }
        return ancs[x][0];
    }

    int get_dist(int x, int y){
        return depth[x] + depth[y] - 2*depth[lca(x, y)];
    }

    int kth_ancestor(int x, int k){
        for(int i = lg; i>=0; i--){
            if(k & (1<<i)){
                x = ancs[x][i];
            }
        }
        return x;
    }
};