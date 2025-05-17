#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int parentIndex(int child_idx){
    return ceil((float)child_idx/(float)2)-1;
}

void maxHeapify(vector<int> &v, int index, int len){
    int leftChildIndex = (2*index)+1;
    int rightChildIndex= (2*index)+2;

    int highest_idx = index;

    if(leftChildIndex<len && v[leftChildIndex]>v[highest_idx]){
        highest_idx = leftChildIndex;
    }

    if(rightChildIndex<len && v[rightChildIndex]>v[highest_idx]){
        highest_idx = rightChildIndex;
    }

    // this Condition happens meaning that the "Parent" is Not the Largest... So we Swap it with highset index & call Max-Heapify for the Lower indexes
    if(highest_idx != index){
        swap(v[index], v[highest_idx]);
        maxHeapify(v, highest_idx, len);
    }
}

void buildMaxHeap(vector<int> &v, int len){
    // we are Skipping all the LEAF Node
    for (int i = (len / 2) - 1; i >= 0; i--) {
        maxHeapify(v, i, len);
    }
}

void heapSort(vector<int> &v){
    // at First we call "buildMaxHeap" once, as such the larget element comes at the Root/Top. Then, we Swap it to the Last Element & call Max Heapify again Except the Last Element
    int n = v.size();
    buildMaxHeap(v, n); // full length

    int currentLastIdx = n-1;

    for (int i = n - 1; i > 0; i--) {
        swap(v[0], v[currentLastIdx]);           // move max to end
        maxHeapify(v, 0, currentLastIdx);        // heapify remaining part

        currentLastIdx--;
    }
}

int main(){

    // int ara[] = {5,3,2,4,1};
    vector<int> v = {5,3,2,4,1};
    
    heapSort(v);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    
    cout<<endl;
    
    return 0;
}