#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-path-sum/solutions/4330078/beat-90-c/

int mem[200][200];
int dfs(int r, int c, vector<vector<int>>& grid){
    if(r == 0|| c == 0) return mem[r][c];
    if(mem[r][c])   return mem[r][c];
    mem[r][c] = grid[r][c] + min(dfs(r-1, c, grid),dfs(r, c-1, grid));
    return mem[r][c];
}
int minPathSum(vector<vector<int>>& grid) {
    memset(mem, 0, sizeof(mem));
    mem[0][0] = grid[0][0];
    for(int i = 1; i < grid[0].size(); i++){
        mem[0][i] = grid[0][i] + mem[0][i-1];
    }
    for(int i = 1; i < grid.size(); i++){
        mem[i][0] = grid[i][0] + mem[i-1][0];
    }
    return dfs(grid.size() - 1, grid[0].size() - 1, grid);
}


int main(){
    vector<vector<int>> vt = {{1,3,1},{1,5,1},{4,2,1}};
    cout << minPathSum(vt);
}