#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/first-missing-positive/solutions/4329459/beat-100-simple-c/

int firstMissingPositive(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] <= 0 || nums[i] >= nums.size() + 1) continue;
        if(nums[i] != nums[nums[i]-1]) {
            swap(nums[i], nums[nums[i]-1]);
            i--;
        }
    }
    for(int i = 0; i < nums.size(); i++){
        if(i+1 != nums[i])  return i+1;
    }
    return nums.size()+1;
}


int main(){
    vector<int> vt = {3,4,-1,1};
    cout << firstMissingPositive(vt);
}