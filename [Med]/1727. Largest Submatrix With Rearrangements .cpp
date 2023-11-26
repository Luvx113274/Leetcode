#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/largest-submatrix-with-rearrangements/solutions/4330299/beats-100-explained-with-video-simple-sorting-visualized-too/?envType=daily-question&envId=2023-11-26
int largestSubmatrix(vector<vector<int>>& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int ans = 0;
    for(int j = 0; j < n; j++)
        for(int i = 1; i < m; i++)
            if(matrix[i][j] == 1)
                matrix[i][j] += matrix[i-1][j];
    for(int i = 0; i < m; i++)
    {
        sort(matrix[i].begin(), matrix[i].end());
        reverse(matrix[i].begin(), matrix[i].end());
        for(int j = 0; j < n; j++)
            ans = max(ans, matrix[i][j]*(j+1));
    }
    return ans;
}


int main(){
    vector<vector<int>> vt = {{0,0,1},{1,1,1},{1,0,1}};
    cout << largestSubmatrix(vt);
}