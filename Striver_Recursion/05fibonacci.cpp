#include<iostream>
using namespace std;
/*
Time Complexity = 2^n

lower bound = 2^(n/2)
upper bound = 2^n
*/
int fibonacci(int n) {
    if(n<=1) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}
    int main(){
        int n;
        cin>>n;
        cout<<fibonacci(n)<<endl;
    return 0;
}