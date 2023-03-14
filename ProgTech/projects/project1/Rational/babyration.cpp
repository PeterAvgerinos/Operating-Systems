//  
//  rationalclass.cpp  
//  rational1  
//  
//  Created by Peter Augerinos on 22/7/22.  
#ifndef CONTEST  
#include "babyratio.hpp"  
#endif  
  
using namespace std;  
  
  
rational::rational(int a, int b) : nom(a), den(b) {  
  
}  
  
// void rational::setrational(int a, int b){  
//     nom = a;  
//     den = b;  
// };  
  
rational rational::add(rational r){  
    rational w(1,1);  
    w.nom = r.den*this->nom + this->den*r.nom;  
    w.den = this->den*r.den;  
    // w = simplify(w);  
    return w;  
}  
  
rational rational::sub(rational r){  
    rational w(1,1);  
    w.nom = r.den*this->nom - r.nom*this->den;  
    w.den = this->den*r.den;  
    // w = simplify(w);  
    return w;  
}  
  
rational rational::mul(rational r){  
    rational w(1,1);  
    w.den = this->den*r.den;  
    w.nom = this->nom*r.nom;  
    // w = simplify(w);  
    return w;  
}  
  
rational rational::div(rational r){  
    rational w(1,1);  
    w.nom = this->nom*r.den;  
    w.den = this->den*r.nom;  
    // w = simplify(w);  
    return w; }  
  
void rational::print(){  
    int gcd = rational::gcd(this->nom, this->den);  
    this->nom = this->nom/gcd;  
    this->den = this->den/gcd;  
    if((this->nom>0 && this->den<0) || (this->nom<0 && this->den>0))  
        cout<<"-"<<abs(this->nom)<<"/"<<abs(this->den);  
    else  
        cout<<abs(this->nom)<<"/"<<abs(this->den);  
};  
  
int rational::gcd(int a, int b){  
    if(b == 0){return a;}  
    else  
    {return gcd(b,a%b);}  
}  
// rational operator +(rational const &a, rational const &b){  
//     rational w;  
//     w.den = a.den*b.den;  
//     w.nom = a.nom*b.den + b.nom*a.den;  
//     w = w.simplify(w);  
//     return w;  
// }  
//  
// rational operator -(rational const &a, rational const &b){  
//     rational w;  
//     w.nom = a.nom*b.den - b.nom*a.den;  
//     w.den = a.den*b.den;  
//     w = w.simplify(w);  
//     return w;  
// }  
//  
// rational operator *(rational const &a, rational const &b){  
//     rational w;  
//     w.den = a.den*b.den;  
//     w.nom = a.nom*b.nom;  
//     w = w.simplify(w);  
//     return w;  
// }  
//  
// rational operator /(rational const &a, rational const &b){  
//     rational w;  
//     w.nom = a.nom*b.den;  
//     w.den = a.den*b.nom;  
//     w = w.simplify(w);  
//     return w;  
// }  
//  
// std::ostream & operator << (std::ostream &out, rational const &a){  
//     if((a.nom>0 && a.den<0) || (a.nom<0 && a.den>0))  
//         cout<<"-"<<abs(a.nom)<<"/"<<abs(a.den);  
//     else  
//         cout<<abs(a.nom)<<"/"<<abs(a.den);  
//     return out;  
// }  
  
// int main() {  
//     rational a(1, 2);  
//     rational b(3, 4);  
//     rational c(5, 6);  
//      a.add(b).sub(c).print();  
//      cout << endl;  
//      a.print();  
//      cout << "should still be 1/2" << endl;  
//  }  
