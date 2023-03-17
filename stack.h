#pragma once
#include <iostream>

using namespace std;

class stackOverflow : std::exception {

public:

	stackOverflow() : reason("stack overflow err msg") {}

	const char* what() const {

		return reason;

	}

private:

	const char* reason;

};

class stackUnderflow : std::exception {

public:

	stackUnderflow() : reason("stack underflow err msg") {}

	const char* what() const {

		return reason;

	}

private:

	const char* reason;

};

class sWrongSize : std::exception {

public:

	sWrongSize() : reason("stack wrong size err msg") {}

	const char* what() const {

		return reason;

	}

private:

	const char* reason;

};


template <class T>
class Stack
{
public:
	virtual ~Stack() {}
	virtual void push(const T& e) = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
};

template<class T>
class limitedStack : Stack<T> {

private:

	T* array;
	size_t cap;
	size_t max_cap;

public:
	
	limitedStack();
	limitedStack(size_t sz);
	~limitedStack() {}
	void push(const T& e);
	T pop();
	bool isEmpty();

};

template<typename T>
limitedStack<T>::limitedStack() {

	max_cap = 256;
	array = new T[max_cap];
	cap = 0;

}

template<typename T>
limitedStack<T>::limitedStack(size_t sz) {

	if (sz == 0) {

		sWrongSize err;
		throw(err.what());

	}
	else {

		try {

			max_cap = sz;
			array = new T[sz];
			cap = 0;

		}
		catch (exception) {

			sWrongSize err;
			throw(err.what());

		}

	}
	

}

template <typename T>
void limitedStack<T>::push(const T& e) {
	
	if (cap >= max_cap) {

		stackOverflow err;
		throw(err);

	}
	else {

		array[cap] = e;
		cap++;

	}
	
}

template <typename T>
T limitedStack<T>::pop() {
	
	if (cap <= 0) {

		stackUnderflow err;
		throw(err);

	}
	else {

		cap--;
		return array[cap];

	}


}

template<typename T>
bool limitedStack<T>::isEmpty() {
	
	return(cap == 0);

}