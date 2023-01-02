#include<bits/stdc++.h>
using namespace std;

void printName_ntimes(int n) {
    if(n == 0) return;
    cout<<"Piyush"<<endl;
    printName_ntimes(--n);
} 

void print_one_toN(int n) {
    static int m = 1;
    if(n == 0) return;
    cout<<m<<endl;
    m++;
    print_one_toN(--n);
}

void N_to_one(int n) {
    if(n<1) return;
    cout<<n<<endl;
    N_to_one(n-1);
}

void back_track_oneToN(int n) {
    if(n<1)
        return;
    back_track_oneToN(n-1);
    cout<<n<<endl;
}

int main(){

    // print name 'n' times
    // printName_ntimes(5);

    // print linearly from 1 to n
    // print_one_toN(5);

    // print from N to 1
    N_to_one(5);

    // print 1 to N by backtracking
    // back_track_oneToN(5);



    return 0;
}