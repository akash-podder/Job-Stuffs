#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void mergeList(vector<int> &v, int low, int high, int mid){
    vector<int> v1;
    vector<int> v2;

    for(int i=low; i<=mid; i++){
        v1.push_back(v[i]);
    }

    for(int i=mid+1; i<=high; i++){
        v2.push_back(v[i]);
    }

    int len1=v1.size();
    int len2=v2.size();
    
    int i=0, j=0, current=low;

    while(i<len1 && j<len2){
        if(v1[i]<=v2[j]){
            v[current] = v1[i];
            i++;
        }
        else{
            v[current] = v2[j];
            j++;
        }

        current++;
    }

    while(i<len1){
        v[current] = v1[i];
        i++;
        
        current++;
    }

    while(j<len2){
        v[current] = v2[j];
        j++;

        current++;
    }
}

void mergeSort(vector<int> &v, int low, int high){
    // Base case
    if(low == high){
        return;
    }

    // getting the Mid of the Vector
    int mid = low + ((high-low)/2);

    // dividing elements from Center in Each Step
    mergeSort(v, low, mid);
    mergeSort(v, mid+1, high);

    mergeList(v, low, high, mid);
}

int main(){
    vector<int> v = {5, 2, 1, 4, 3, 9};

    mergeSort(v, 0, v.size()-1);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    cout<<endl;

    return 0;
}