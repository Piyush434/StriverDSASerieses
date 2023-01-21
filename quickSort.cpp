#include<bits/stdc++.h>
using namespace std;

// int partition
int partition(int l,int r,vector<int>& arr) {
    int val = arr[r];
    int i = l-1;
    int j = l;
    while(j<r) {
        if(arr[j]<val) {
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i],arr[j]);
    return i;
}

void quickSort(int l,int r,vector<int>& arr) {
    if(l>r) return;
    int pi = partition(l,r,arr);
    quickSort(l,pi-1,arr);
    quickSort(pi+1,r,arr);
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) 
        arr[i] = rand()%10000;
    quickSort(0,n-1,arr);  
    for(auto i: arr) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}