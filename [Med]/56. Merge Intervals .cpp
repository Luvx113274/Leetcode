#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> output;
    for(auto interval : intervals){
        if(output.empty() || output.back()[1] < interval[0]){
            output.push_back(interval);
        }
        else{
            output.back()[1] = max(output.back()[1], interval[1]);
        }
    }
    return output;
}

int main(){
    vector<vector<int>> vt = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = merge(vt);
    for(auto v : res){
        cout << v[0] << " " << v[1] << "\n";
    }
}