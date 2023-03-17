#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

bool checkBalanceBrackets(const string& text, const int maxDeep);

int main() {

	cout << "BASIC STACK FUNCS:" << endl << endl;
	limitedStack<int> teststack(2);
	teststack.push(6);
	teststack.push(7);
	cout << "Added 2 elems (6,7), isEmpty()? " << teststack.isEmpty() << endl;
	cout << "Popped last elem: " << teststack.pop() << endl;
	cout << "isEmpty? " << teststack.isEmpty() << endl;
	cout << "Popped last elem: " << teststack.pop() << endl;
	cout << "isEmpty? " << teststack.isEmpty() << endl;

	//teststack.pop();

	/*teststack.push(1);
	teststack.push(1);
	teststack.push(1);*/

	//limitedStack<int> errStack(-1);
	

	cout << endl << endl << "BASIC QUEUE FUNCS:" << endl << endl;
	limitedQueue<int> testqueue(2);
	testqueue.enQueue(6);
	testqueue.enQueue(7);
	cout << "Added 2 elems (6,7), isEmpty()? " << testqueue.isEmpty() << endl;
	cout << "Popped first elem: " << testqueue.deQueue() << endl;
	cout << "isEmpty? " << testqueue.isEmpty() << endl;
	cout << "Popped first elem: " << testqueue.deQueue() << endl;
	cout << "isEmpty? " << testqueue.isEmpty() << endl;

	//testqueue.deQueue();

	/*testqueue.enQueue(1);
	testqueue.enQueue(1);
	testqueue.enQueue(1);*/

	//limitedQueue<int> errQueue(-1);

	cout << endl << endl;

	string strue = "((()))";
	string strue1 = "{he (me)}";
	string sfalse = "((())))";
	string sfalse1 = "((((()))))";

	cout << "strue brackets result: " << checkBalanceBrackets(strue, 3)<<endl;
	cout << "strue1 brackets result: " << checkBalanceBrackets(strue1, 3) << endl;
	cout << "sfalse brackets result: " << checkBalanceBrackets(sfalse, 3) << endl;
	cout << "sfalse1 brackets result: " << checkBalanceBrackets(sfalse1, 3) << endl;

	system("pause");
	return 0;

}

bool checkBalanceBrackets(const string& text, const int maxDeep) {

	int length = text.length();
	int brac(0);

	for (int i = 0; i < length; i++) {

		if (text[i] == '(' || text[i] == ')' || text[i] == '<' || text[i] == '>' || text[i] == '[' || text[i] == ']' || text[i] == '{' || text[i] == '}') {

			brac++;

		}
		
	}

	if (brac % 2 != 0) {
		return false;
	}
	else {

		limitedStack<char> bracketsStack(256);

		int deep_ch(0);

		for (int i = 0; i < length; i++) {

			if (deep_ch > maxDeep)return false;

			switch (text[i]) {

			case '(': bracketsStack.push(')'); deep_ch++; break;
			case '<': bracketsStack.push('>'); deep_ch++; break;
			case '[': bracketsStack.push(']'); deep_ch++; break;
			case '{': bracketsStack.push('}'); deep_ch++; break;
			
			case ')':
			case '>':
			case '}':
			case ']':

				if (bracketsStack.isEmpty() || bracketsStack.pop() != text[i]) {

					return false;

				}

				break;

			}

		}

		return(bracketsStack.isEmpty());

	}
	

}