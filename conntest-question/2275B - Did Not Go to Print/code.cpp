#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    
    while(t--){
        
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        vector<int> print;
        stack<int> st;
        
        for(int i=0; i<n; i++){
            char ch = s[i];
            
            if(ch == '1'){
                st.push(i+1);
            }
            else if(ch == '2'){
                if(st.empty()){
                    print.push_back(i+1);
                }
                else{
                    int a = st.top();
                    st.pop();
                    print.push_back(a);
                }
            }
            else if( ch == '3'){
                print.push_back(i+1);
            }
        }
        
        vector<bool> isPrinted(n + 1, false);
 
        for (int x : print) {
            isPrinted[x] = true;
        }
        
        vector<int> ans;
        
        for(int i=1; i<n+1; i++){
            if(isPrinted[i]){
                continue;
            }
            else{
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0){
            cout << 0 << endl;
        }
        else{
            cout << ans.size() << endl;
            for(auto n : ans){
                cout << n << " ";
            }
            cout << endl;
        }
    }
}
