#include <bits/stdc++.h>
using namespace std;

class MyStack {
	int *arr;
	int top;
	int capacity;

public:
	MyStack(int size) {
		capacity = size;
		arr = new int[size];
		top = -1;
	}

	void push(int x) {
		if (top == capacity - 1) {
			cout << "Stack Overflow\n";
			return;
		}
		arr[++top] = x;
	}

	void pop() {
		if (top == -1) {
			cout << "Stack Underflow\n";
			return;
		}
		top--;
	}

	int peek() {
		if (top == -1) {
			cout << "Stack is empty\n";
			return -1;
		}
		return arr[top];
	}

	bool isEmpty() {
		return top == -1;
	}

	void display() {
		if (top == -1) {
			cout << "Stack Empty\n";
			return;
		}
		for (int i = top; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}

	~MyStack() {
		delete[] arr;
	}
};

int main() {
	MyStack s(5);

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	s.display();

	s.pop();
	cout << "Top: " << s.peek() << "\n";
	return 0;
}