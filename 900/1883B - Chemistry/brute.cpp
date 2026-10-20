#include <iostream>
#include <unordered_map>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;
        
        unordered_map<int,int> mpp;
        
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            
            if(mpp.find(ch) != mpp.end()){
                mpp[ch]++;
            }
            else{
                mpp[ch] = 1;
            }
        }
        
        int odd_cnt = 0;
        
        for(auto i : mpp){
            if(i.second % 2 == 1){
                odd_cnt++;
            }
        }
        
        if(odd_cnt > k+1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        
    }
    
}
