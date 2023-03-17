#pragma once
#include <iostream>

using namespace std;

class queueOverflow : std::exception {

public:

	queueOverflow() : reason("queue overflow err msg") {}

	const char* what() const {

		return reason;

	}

private:

	const char* reason;

};

class queueUnderflow : std::exception {

public:

	queueUnderflow() : reason("queue underflow err msg") {}

	const char* what() const {

		return reason;

	}

private:

	const char* reason;

};

class qWrongSize : std::exception {

public:

	qWrongSize() : reason("queue wrong size err msg") {}

	const char* what() const {

		return reason;

	}

private:

	const char* reason;

};

template <class T>
class Queue
{
public:
	virtual ~Queue() {}
	virtual void enQueue(const T& e) = 0;
	virtual T deQueue() = 0;
	virtual bool isEmpty() = 0;
};

template<class T>
class limitedQueue : Queue<T> {

private:

	T* array;
	size_t cap;
	size_t max_cap;

public:

	limitedQueue();
	limitedQueue(size_t sz);
	~limitedQueue() {}
	void enQueue(const T& e);
	T deQueue();
	bool isEmpty();

};

template<typename T>
limitedQueue<T>::limitedQueue() {

	max_cap = 256;
	array = new T[max_cap];
	cap = 0;

}
template<typename T>
limitedQueue<T>::limitedQueue(size_t sz) {

	if (sz == 0) {

		qWrongSize err;
		throw err;

	}
	else {

		try {

			max_cap = sz;
			array = new T[sz];
			cap = 0;

		}
		catch (exception) {

			qWrongSize err;
			throw err;

		}

	}
	

}

template <typename T>
void limitedQueue<T>::enQueue(const T& e) {

	if (cap >= max_cap) {

		queueOverflow err;
		throw err;

	}
	else {

		array[cap] = e;
		cap++;

	}
	
}

template <typename T>
T limitedQueue<T>::deQueue() {

	if (cap <= 0) {

		queueUnderflow err;
		throw err;

	}
	else {

		cap--;
		T temp = array[0];

		for (int i = 0; i < cap; i++) {

			array[i] = array[i + 1];

		}
		return temp;

	}

}

template<typename T>
bool limitedQueue<T>::isEmpty() {

	return(cap == 0);

}