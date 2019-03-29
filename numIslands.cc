class UF {
    private:
    vector<int> parent;
    vector<int> rank;
    int count;
    
    void makeSet(vector<vector<char>>& grid,int n, int m){
        count =0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    parent.push_back(i*n+j);
                    count++;
                }else parent.push_back(-1);
                rank.push_back(0);
            }
        }
    }
    
    int find(int i){
        if(parent[i]!=i){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    
    void Union(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            if(rank[rootx]>rank[rooty]){
                parent[rooty] = rootx;
            } else if(rank[rootx]<rank[rooty]){
                parent[rootx] = rooty;
            } else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
            --count;
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        
        makeSet(grid,n,m);
        for(int i =0;i<m;i++){
            for(int j =0; j<n;j++){
                if(grid[i][j] == '1'){
                    grid[i][j]=0;
                    if(i-1>=0 && grid[i-1][j]== '1') Union(i*n+j, (i-1)*n+j);
                    if(i+1<m && grid[i+1][j]== '1') Union(i*n+j, (i+1)*n+j);
                    if(j-1>=0 && grid[i][j-1]== '1') Union(i*n+j, i*n+j-1);
                    if(j+1<n && grid[i][j+1]== '1') Union(i*n+j,i*n+j+1);
                }
            }
        }
        
        return count;
    }
};
