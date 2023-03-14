#include <iostream>

using namespace std;

template <typename T>
class stack { 				//me pinaka
public:

	stack (int size) {
		sz=size;
		top=0;
		data = new T[sz];
	}

	stack (const stack &s) {
		sz=s.sz;
		top=s.top;
		data = new T[sz];
		for (int i=0; i<s.top; i++) data[i]=s.data[i];
	}

	~stack() {
		delete [] data;
	}

	const stack& operator = (const stack &s) {
		this->~stack();
		sz=s.sz;
		top=s.top;
		data = new T[sz];
		for(int i=0; i<s.top; i++) data[i]=s.data[i];
		return *this;
	}


	bool empty() {
		return top == 0;
	}

	void push (const T &x) { //xwris elegxo
		data[top++]=x;
	}

	T pop () { //xwris elegxo
		return data[--top];
	}

	int size() {
		return top;
	}


	friend ostream& operator << (ostream &out, const stack &s) {
		if (s.top==0) {
			out<<"[]";
			return out;
		}
		out<<'[';
		for (int i=0; i<s.top-1; i++) out<<s.data[i]<<", ";
		out<<s.data[s.top-1];
		out<<']';
		return out;
	}

private:
	T *data;
	int top;
	int sz;
};

#ifndef CONTEST
int main() {
	//let's play with integers..
	stack<int> s(10);
	cout << "s is empty: " << s << endl;
	s.push(42);
	cout << "s has one element: " << s << endl;
	s.push(17);
	s.push(34);
	cout << "s has more elements: " << s << endl;
	cout << "How many? " << s.size() << endl;
	stack<int> t(5);
	t.push(7);
	cout << "t: " << t << endl;
	t = s;
	cout << "popping from s: " << s.pop() << endl;
	s.push(8);
	stack<int> a(s);
	t.push(99);
	a.push(77);
	cout << "s: " << s << endl;
	cout << "t: " << t << endl;
	cout << "a: " << a << endl;
	//now with doubles...
	stack<double> c(4);
	c.push(3.14);
	c.push(1.414);
	cout << "c contains doubles " << c << endl;
	//and with characters...
	stack<char> k(4);
	k.push('$');
	cout << "k contains a character " << k << endl;
}
#endif
