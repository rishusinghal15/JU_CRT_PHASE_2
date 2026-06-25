#include<iostream>
#include<vector>
#include<stack>
using namespace std; 


class twoStacks {
	public:
	int* arr;
	int size;
	int top1;
	int top2;
	
	twoStacks()
	{
		size = 100; 
		arr = new int[size];
		top1 = -1;
		top2 = size;
	}
	
	// Function to push an integer into the stack1.
	void push1(int x)
	{
		if (top2 - top1 == 1) {
			return;
		} else {
			top1++;
			arr[top1] = x;
		}
		
	}
	
	// Function to push an integer into the stack2.
	void push2(int x)
	{
		if (top2 - top1 == 1) {
			return;
		} else {
			top2--;
			arr[top2] = x;
		}
	}
	
	// Function to remove an element from top of the stack1.
	
	int pop1() {
		// if element available, then pop
		// if stack empty, then don't pop
		if (top1 == -1) {
			return - 1;
		} else {
			int ans = arr[top1];
			top1--;
			return ans; 
		}
	}
	
	// Function to remove an element from top of the stack2.
	int pop2() {
		if (top2 == size) {
			// Stack2 is empty, no element to pop
			return - 1;
		} else {
			int ans = arr[top2];
			top2++;
			return ans; 
		}
	}
};

int main() {
    twoStacks st;

    // Push elements
    st.push1(10);
    st.push1(20);
    st.push1(30);

    st.push2(100);
    st.push2(200);
    st.push2(300);

    // Pop from Stack 1
    cout << "Pop from Stack1: " << st.pop1() << endl;
    cout << "Pop from Stack1: " << st.pop1() << endl;

    // Pop from Stack 2
    cout << "Pop from Stack2: " << st.pop2() << endl;
    cout << "Pop from Stack2: " << st.pop2() << endl;

    return 0;
}