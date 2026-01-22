#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
    
};

class MyStack{
    
    Node* head;
    public:
    
    MyStack(){
        head = NULL;
    }
    
    
    void push(int val){
        
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        
    }
    
    void pop(){
        if(!head){
            cout<<"Empty stack\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    void peek(){
        if(!head){
            cout<<"Stack Empty\n";
            return;
        }
        cout<<head->data<<" ";
    }
    
    bool isEmpty(){
        if(!head) return true;
        return false;
    }
    
    void traverse(){
        if(!head) return;
        
        Node * temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    
};

int main() {
	MyStack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	s.traverse();

	return 0;
}