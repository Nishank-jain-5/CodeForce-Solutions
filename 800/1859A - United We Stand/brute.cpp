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
        
        vector<long long> a(n);
        
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        vector<long long> b;
        vector<long long> c;
        
        for(int i=0; i<n; i++){
            if(i == 0){
                b.push_back(a[i]);
                continue;
            }
            else{
                if(b[0] % a[i] == 0){
                    b.push_back(a[i]);
                }
                else{
                    c.push_back(a[i]);
                }
            }
        }
        
        if(b.size() == 0 || c.size() == 0){
            cout << -1 << endl;
        }
        else{
            cout << b.size() << " " << c.size() << endl;
            
            for(auto i : b){
                cout << i << " ";
            }
            cout << endl;
            
            for(auto i : c){
                cout << i << " ";
            }
            cout << endl;
        }
        
    }
    
}
