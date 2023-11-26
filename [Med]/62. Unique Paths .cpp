#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/unique-paths/solutions/4330034/beat-100-c/

int arr[101][101];
int uniquePaths(int m, int n);
int path(int m, int n){
    if(m == 1 || n == 1)  return 1;
    if(arr[m][n])  return arr[m][n];
    arr[m][n] = path(m-1, n) + path(m, n-1);
    return arr[m][n];
}
int uniquePaths(int m, int n) {
    memset(arr, 0, sizeof(arr));
    return path(m,n);
}


int main(){
    cout << uniquePaths(3, 7);
}