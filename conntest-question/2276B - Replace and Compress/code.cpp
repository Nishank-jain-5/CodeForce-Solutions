#include <iostream>
#include <vector>
#include <set>
using namespace std;
 
 
 
string perm(string s){
    string ans = "";
    ans += s[0];
    
    for(int i=1; i<s.size(); i++){
 
        char ch = ans[ans.size()-1];
        if(s[i] == ch){
            continue;
        }
        else{
            ans += s[i];
        }
    }
    
    return ans;
}
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        string s;
        cin >> s;
        
        set<int> st;
        
        int m = perm(s).size();
        st.insert(m);
        
        for(int i = 1; i < (int)s.size() - 1; i++){
            
            int len = m;
            if(s[i-1] == s[i] && s[i] == s[i+1]){
                len = m + 2;        
            }
            
            else if(s[i-1] != s[i] && s[i] != s[i+1]){
                len = m - 2;    
            }
            
            st.insert(len);
        }
        
        cout << st.size() << endl;
        
        
    }
    
    
}
