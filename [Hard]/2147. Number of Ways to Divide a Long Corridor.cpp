#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/solutions/4337730/beat-100-c/

int numberOfWays(string cor) {
    int count = 1, sum = 0;
    long res = 1;
    for(auto c : cor){
        if(c == 'P' && sum == 2){
            count++;
        } else if(c == 'S' && sum == 2){
            sum = 1;
            res = (res*count)%1000000007;
            count = 1;
        } else if(c == 'S' && sum < 2){
            sum++;
        }
    }
    if(sum == 2){
        return res;
    }
    return 0;

}

int main(){
    string vt = "PPPPPSPPSPPSPPPSPPPPSPPPPSPPPPSPPSPPPSPSPPPSPSPPPSPSPPPSPSPPPPSPPPPSPPPSPPSPPPPSPSPPPPSPSPPPPSPSPPPSPPSPPPPSPSPSS";
    cout << numberOfWays(vt);
}