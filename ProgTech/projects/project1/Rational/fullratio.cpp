//  
//  rationalclass.cpp  
//  rational1  
//  
//  Created by Peter Augerinos AM03115074 on 22/7/22.   
//  Έχω παραδώσει και στον κωδικό pt21a125
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
  
// rational rational::add(rational r){  
//     rational w(1,1);  
//     w.nom = r.den*this->nom + this->den*r.nom;  
//     w.den = this->den*r.den;  
//     // w = simplify(w);  
//     return w;  
// }  
//  
// rational rational::sub(rational r){  
//     rational w(1,1);  
//     w.nom = r.den*this->nom - r.nom*this->den;  
//     w.den = this->den*r.den;  
//     // w = simplify(w);  
//     return w;  
// }  
//  
// rational rational::mul(rational r){  
//     rational w(1,1);  
//     w.den = this->den*r.den;  
//     w.nom = this->nom*r.nom;  
//     // w = simplify(w);  
//     return w;  
// }  
//  
// rational rational::div(rational r){  
//     rational w(1,1);  
//     w.nom = this->nom*r.den;  
//     w.den = this->den*r.nom;  
//     // w = simplify(w);  
//     return w; }  
//  
// void rational::print(){  
//     int gcd = rational::gcd(this->nom, this->den);  
//     this->nom = this->nom/gcd;  
//     this->den = this->den/gcd;  
//     if((this->nom>0 && this->den<0) || (this->nom<0 && this->den>0))  
//         cout<<"-"<<abs(this->nom)<<"/"<<abs(this->den);  
//     else  
//         cout<<abs(this->nom)<<"/"<<abs(this->den);  
// };  
  
int rational::gcd(int a, int b){  
    if(b == 0){return a;}  
    else  
    {return gcd(b,a%b);}  
}  
  
rational operator +(rational const &a, rational const &b){  
    rational w(1,1);  
    w.den = a.den*b.den;  
    w.nom = a.nom*b.den + b.nom*a.den;  
    // w = w.simplify(w);  
    return w;  
}  
  
rational operator -(rational const &a, rational const &b){  
    rational w(1,1);  
    w.nom = a.nom*b.den - b.nom*a.den;  
    w.den = a.den*b.den;  
    // w = w.simplify(w);  
    return w;  
}  
  
rational operator *(rational const &a, rational const &b){  
    rational w(1,1);  
    w.den = a.den*b.den;  
    w.nom = a.nom*b.nom;  
    // w = w.simplify(w);  
    return w;  
}  
  
rational operator /(rational const &a, rational const &b){  
    rational w(1,1);  
    w.nom = a.nom*b.den;  
    w.den = a.den*b.nom;  
    // w = w.simplify(w);  
    return w;  
}  
  
std::ostream & operator << (std::ostream &out, rational const &a){  
    rational w(1,1);  
    w.nom = a.nom;  
    w.den = a.den;  
    int gcd = w.gcd(w.nom, w.den);  
    w.nom =w.nom/gcd;  
    w.den =w.den/gcd;  
    if((w.nom>0 && w.den<0) || (w.nom<0 && w.den>0))  
        cout<<"-"<<abs(w.nom)<<"/"<<abs(w.den);  
    else  
        cout<<abs(w.nom)<<"/"<<abs(w.den);  
    return out;  
}  
  
// int main() {  
//     rational a(1, 2);  
//     rational b(3, 4);  
//     rational c(5, 6);  
//     cout << a + b - c << endl;  
//     cout << a << " should still be 1/2" << endl;  
//  }  
