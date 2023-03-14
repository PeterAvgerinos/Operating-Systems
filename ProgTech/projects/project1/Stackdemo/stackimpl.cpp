//  stackimpl.hpp
//  stackdemo
//
//  Created by Peter Augerinos on 22/7/22.
//

#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
class stack {
public:
    
    stack(int size);
    
    stack(const stack &s);
    
    ~stack();
    
    const stack<T> & operator =(const stack &s){
        this->~stack();
        top=s.top;
        stacksize=s.stacksize;
        arr = new T[stacksize];
        for(int i=0; i<s.top; i++) arr[i]=s.arr[i];
        return *this;
    };
    
    bool empty ();
    
    void push(const T &x);
    
    T pop();
    
    int size();
    
    friend ostream & operator << (ostream &out, const stack &s){
        if (s.top==0) {
			out<<"[]";
			return out;
		}
        else { 
            out<<"[";
            for (int i=0; i<s.top-1; i++){ 
                out<<s.arr[i]<<", ";
            }
            out<<s.arr[s.top-1];
            out<<"]";
            return out;
        }
    };
    
private:
    int top;
    int stacksize;
    T *arr;
};

template <typename T>
stack<T>::stack(int size){
    top = 0;
    stacksize = size;
    arr = new T[stacksize];
}

template <typename T>
stack<T>::stack(const stack &s){
    top = s.top;
    stacksize = s.stacksize;
    arr = new T[stacksize];
    for (int i=0; i<s.top; i++){ 
        arr[i] = s.arr[i];
    }
}

template <typename T>
stack<T>::~stack(){
    delete [] arr;
}

template <typename T>
bool stack<T>::empty() { 
    return top == 0;
}

template <typename T>
void stack<T>::push(const T &x){
    arr[top++]=x;
}

template <typename T>
T stack<T>::pop(){
    return arr[--top];
}

template <typename T>
int stack<T>::size(){
    return top;
}

// int main () {
//     // let’s play with integers...
//     stack<int> s(10);
//     cout << "s is empty: " << s << endl;
//     s.push(42);
//     cout << "s has one element: " << s << endl;
//     s.push(17);
//     s.push(34);
//     cout << "s has more elements: " << s << endl;
//     cout << "How many? " << s.size() << endl;
//     stack<int> t(5);
//     t.push(7);
//     cout << "t:" << t << endl;
//     t = s;
//     cout << "popping t from s: " << s.pop() << endl;
//     s.push(8);
//     stack<int> a(s);
//     t.push(99);
//     a.push(77);
//     cout << "s: " << s << endl;
//     cout << "t: " << t << endl;
//     cout << "a: " << a << endl;
//     // now with doubles...
//     stack<double> c(4);
//     c.push(3.14);
//     c.push(1.414);
//     cout << "c contains doubles " << c << endl;
//     // and with characters...
//     stack<char> k(4);
//
//     cout << "k contains a character " << k << endl;
// }
