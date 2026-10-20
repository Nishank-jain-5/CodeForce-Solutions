#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
 
        char arr[10][10];
        
        int score = 0;
        
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                cin >> arr[i][j];
                
                if(arr[i][j] == 'X'){
                    score += min({i,j,9-i,9-j}) + 1;
                }
                
            }
        }
        
        cout << score << endl;
        
 
    }
    
}
