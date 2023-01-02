#include<iostream>
using namespace std;

int sumOfN(int n) {
    if(n < 1) return 0;
    return n+sumOfN(n-1);
}
int mutliplyOfN(int n) {
    if(n < 1) return 1;
    return n*sumOfN(n-1);
}
    int main(){
        int n;
        cin>>n;
      cout<<sumOfN(n)<<endl;
    return 0;
}