#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int a, b;
        cin >> a >> b;
        
        int xk, yk;
        cin >> xk >> yk;
        
        int xq, yq;
        cin >> xq >> yq;
        
        
        vector<pair<int,int>> k;
        vector<pair<int,int>> q;
        
        // k,a,b
        k.push_back({xk+a, yk+b});
        k.push_back({xk-a, yk-b});
        k.push_back({xk+a, yk-b});
        k.push_back({xk-a, yk+b});
        // k,b,a
        k.push_back({xk+b, yk+a});
        k.push_back({xk-b, yk-a});
        k.push_back({xk+b, yk-a});
        k.push_back({xk-b, yk+a});
        
        // q,a,b
        q.push_back({xq+a, yq+b});
        q.push_back({xq-a, yq-b});
        q.push_back({xq+a, yq-b});
        q.push_back({xq-a, yq+b});
        // q,b,a
        q.push_back({xq+b, yq+a});
        q.push_back({xq-b, yq-a});
        q.push_back({xq+b, yq-a});
        q.push_back({xq-b, yq+a});
        
        int cnt = 0;
        
        for(auto i : k){
            if(find(q.begin(), q.end(), i) != q.end()){
                cnt++;
            }
        }
        
        if(a == b){
            cnt /= 2;
        }
        
        cout << cnt << endl;
        
    }
    
}
