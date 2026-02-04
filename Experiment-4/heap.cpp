#include<iostream>
#include<vector>

#define MAX 100

using namespace std;

int heap[MAX];
int heapSize = 0;

void heapifyUP(int i){

    while(i > 0 && heap[(i-1)/2] > heap[i]){
        swap(heap[(i-1)/2],heap[i]);

        i = (i-1)/2;
    }

}


void heapifyDown(int i){

    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < heapSize && heap[left] < heap[smallest]){
        smallest = left;
    }
    if(right < heapSize && heap[right] < heap[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(heap[smallest],heap[i]);
        heapifyDown(smallest);
    }


}

void deleteMin(){
    if(heapSize==0) return;

    heap[0] = heap[heapSize-1];
    heapSize--;

    heapifyDown(0);
}

void insert(int val){

    if(heapSize == MAX) return;

    heap[heapSize] = val;
    heapSize++;

    heapifyUP(heapSize-1);

}

void deleteAtIndex(int idx) {
    if (idx < 0 || idx >= heapSize) return;

    heap[idx] = heap[heapSize - 1];
    heapSize--;

    int parent = (idx - 1) / 2;

    if (idx == 0 || heap[idx] >= heap[parent]) {
        heapifyDown(idx);
    } 
    else {

        heapifyUP(idx);
    }
}

int main(){

    insert(4);
    insert(2);
    insert(5);
    insert(8);
    insert(10);
    insert(18);
    insert(20);
    for(int i = 0 ; i < heapSize ; i ++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    deleteMin();
    for(int i = 0 ; i < heapSize ; i ++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;

    deleteAtIndex(3);

    cout<<endl;

    for(int i = 0 ; i < heapSize ; i ++){
        cout<<heap[i]<<" ";
    }
}