#include<iostream>
using namespace std;
 
int main(){
        int t;
        cin >> t;
        
        while(t--){
            int n;
            cin >> n;
            
            string s;
            cin >> s;
            
            int cnt = 0;
            bool flag = false;
            
            for(int i=0; i<s.size(); i++){
                if (s[i] == '#') continue;
                
                if(i+2 < s.size() && s[i] == '.' 
                   && s[i+1] == '.' && s[i+2] == '.'){
                        
                        cnt = 0;
                        cnt += 2;
                        
                        break;
                }
                else{
                    cnt += 1;
                }
                
            }
            
            cout << cnt << endl;
            
        }
    }
