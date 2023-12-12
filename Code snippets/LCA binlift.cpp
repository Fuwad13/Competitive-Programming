int ancs[N][20];
int level[N];
int lca(int x, int y){
    // let x be the deeper node
    if(level[x] < level[y]){
        swap(x, y);
    }
    // lifting x to the same level of y
    for(int i = l; i>=0; i--){
        if(level[y] + (1<<i) <= level[x]){
            x = ancs[x][i];
        }
    }
    if(x==y)
        return x;
    // finding the node whose direct ancs./ parent is the lca of x and y
    for(int i = l; i >=0; i--){
        if(ancs[x][i]!=ancs[y][i]){
            x = ancs[x][i];
            y = ancs[y][i];
        }
    }
    return ancs[x][0];

}