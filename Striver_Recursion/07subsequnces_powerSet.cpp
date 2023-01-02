#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void powerSet(string s) {
    int n = s.length();
    for(int i=0;i<=pow(2,n)-1;i++) {
        string sub = "";
        for(int j=0;j<n;j++) { 
            if((1<<j) & i) {
                sub+=s[j];
            }
        }
        cout<<sub;
        cout<<endl;
    }
}

    int main(){
        string inp;
        cin>>inp;
        powerSet(inp);
    return 0;
}