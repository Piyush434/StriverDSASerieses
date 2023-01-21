#include<iostream>
#include<bits/stdc++.h>
#include<chrono>
using namespace std;

int linearSearchRecursive(int* arr,int i,int n,int key) {
    if(i>=n) return -1;
    if(arr[i] == key) return i;
    return linearSearchRecursive(arr,i+1,n,key);
}

int linearSearch(int* arr,int n,int key) {
    for(int i=0;i<n;i++) {
        if(arr[i] == key) return i;
    }
    return -1;
}
int binarySearchRecursive(int* arr,int l,int r,int key) {
    if(l>r) return -1;
    int mid = (l+r)/2;
    if(arr[mid] == key) {
        return mid;
    }
    int ans;
    if(key<arr[mid]) ans = binarySearchRecursive(arr,l,mid-1,key);
    else ans = binarySearchRecursive(arr,mid+1,r,key);
    
    return ans;

}
int binarySearch(int* arr,int n,int key) {
    int l = 0;
    int r = n-1;
    while(l<=r) {
        int mid = (l+r)/2;
        if(arr[mid] == key) return mid;
        else if(key<arr[mid]) r = mid-1;
        else l = mid+1;
    }
    return -1;
}
    int main(){
        int n;
        cin>>n;
        int key;
        cin>>key;
        int* arr = new int[n];
        for(int i=0;i<n;i++) 
            arr[i] = rand()%1000;
        sort(arr,arr+n);
        cout<<"Our Array-->"<<endl;
        for(int i=0;i<n;i++) cout<<i<<" - "<<arr[i]<<" || ";
        cout<<endl;

        // int ans2 = binarySearchRecursive(arr,0,n-1,key);

        // int ans3 = linearSearch(arr,n,key);
        // int ans4 = linearSearchRecursive(arr,0,n,key);
        

        auto start = chrono::high_resolution_clock::now(); 
        ios_base::sync_with_stdio(false); 

        int ans1 = linearSearch(arr,n,key);

        auto end = chrono::high_resolution_clock::now(); 
        double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
        time_taken *= 1e-9;

        cout<<"----------------------------------------"<<endl<<endl;
        cout<<"Linear Search Iterative: "<<endl;
        cout<<ans1<<" --> Time Taken: "<<time_taken<<endl;
        cout<<"----------------------------------------"<<endl<<endl;

        

        start = chrono::high_resolution_clock::now(); 
        ios_base::sync_with_stdio(false); 

        int ans2 = linearSearchRecursive(arr,0,n,key);

        end = chrono::high_resolution_clock::now(); 
        time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
        time_taken *= 1e-9;

        cout<<"----------------------------------------"<<endl<<endl;
        cout<<"Linear Search Rcursive: "<<endl;
        cout<<ans2<<" --> Time Taken: "<<time_taken<<endl;
        cout<<"----------------------------------------"<<endl<<endl;

        
        start = chrono::high_resolution_clock::now(); 
        ios_base::sync_with_stdio(false); 

        int ans3 = binarySearch(arr,n,key);

        end = chrono::high_resolution_clock::now(); 
        time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
        time_taken *= 1e-9;

        cout<<"----------------------------------------"<<endl<<endl;
        cout<<"Binary Search Iterative: "<<endl;
        cout<<ans3<<" --> Time Taken: "<<time_taken<<endl;
        cout<<"----------------------------------------"<<endl<<endl;


        start = chrono::high_resolution_clock::now(); 
        ios_base::sync_with_stdio(false); 

        int ans4 = binarySearchRecursive(arr,0,n-1,key);

        end = chrono::high_resolution_clock::now(); 
        time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
        time_taken *= 1e-9;

        cout<<"----------------------------------------"<<endl<<endl;
        cout<<"Bianry Search Rcursive: "<<endl;
        cout<<ans2<<" --> Time Taken: "<<time_taken<<endl;
        cout<<"----------------------------------------"<<endl<<endl;


    return 0;
}