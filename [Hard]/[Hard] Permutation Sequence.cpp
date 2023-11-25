#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {
    int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}, i = 1;
    vector<char> s{'1','2','3','4','5','6','7','8','9'};
    string res = "";
    while(k > 0){
        int ind = ceil(k * 1.0 / fact[n-i]);
        k%=fact[n-i];
        res += (s[ind - 1]);
        s.erase(s.begin() + ind - 1);
        i++;
    }
    for(int j = n - i; j >= 0; j--){
        res += s[j];
    }
    return res;
}

int main(){
    cout <<  getPermutation(9,300000);
}
