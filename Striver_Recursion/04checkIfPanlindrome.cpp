#include<iostream>
using namespace std;

bool checkPalindrome(int i,string s) {
    if(i>s.length()/2) return true;

    if(s[i] != s[s.length()-1-i]) return false;

    return checkPalindrome(i+1,s);

}
    int main(){
        string s;
        cin>>s;
        if(checkPalindrome(0,s)) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    return 0;
}