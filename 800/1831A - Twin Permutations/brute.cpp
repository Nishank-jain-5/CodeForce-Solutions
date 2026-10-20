#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int main(){
 
    int t;
    cin >> t;
 
    while(t--){
 
        int n;
        cin >> n;
 
        vector<int> v(n);
 
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
 
 
        vector<int> ans(n);
 
        for(int i=0; i<n; i++){
            int val = n - v[i] + 1;
            ans[i] = val;
        }
 
        for(auto i : ans){
            cout << i << " ";
        }
        cout << endl;
 
    }
 
 
 
}
