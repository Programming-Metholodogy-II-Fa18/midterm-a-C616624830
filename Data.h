#pragma once
class Data {
public:
	Data() {}
	~Data() {
		delete[]a;
	}
	void add(int x) {
		if (length == capacity - 1) {
			expansion();
		}
		a[tail] = x;
		if (tail == capacity - 1) {
			tail = 0;
		}
		else {
			tail = tail + 1;
		}
		++length;
	}
	int remove() {
		if (isEmpty()) {
			return -1;
		}
		int x = a[head];
		if (head == capacity - 1) {
			head = 0;
		}
		else {
			head = head + 1;
		}
		--length;
		return x;
	}
	int getValue(int i) {
		if (i == tail || i >= capacity) {
			return -1;
		}
		if (head < tail) {
			if (i < head || i >= tail)
				return -1;
		}
		if (tail > head) {
			if (i < head && i >= tail)
				return -1;
		}
		return a[i];
	}
	void expansion() {
		capacity *= 2;
		int* a2 = new int[capacity];
		for (int i = 0; i <= length; i++) {
			a2[i] = a[i];
		}
		delete[]a;
		a = a2;
	}
	bool isEmpty() {
		return length == 0;
	}
private:
	int head{ 0 };
	int tail{ 0 };
	int length{ 0 };
	int capacity{ 10 };
	int* a = new int[capacity];
};