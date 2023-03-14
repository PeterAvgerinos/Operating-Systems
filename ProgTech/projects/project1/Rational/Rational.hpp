//
//  rationalclass.hpp
//  rational1
//
//  Created by Peter Augerinos on 22/7/22.
//
//

#include <iostream>

class rational {
    
public:

    rational(int a, int b);
    
    void setrational(int a, int b);
    
    rational add(rational r);

    rational sub(rational r);

    rational mul(rational r);

    rational div(rational r);

    void print();
    
    friend rational operator / (rational const &a, rational const &b);

    friend rational operator * (rational const &a, rational const &b);

    friend rational operator + (rational const &a, rational const &b);

    friend rational operator - (rational const &a, rational const &b);

    friend std::ostream & operator << (std::ostream &out, rational const &a);
    
private:
    int nom;
    int den;
    
    static int gcd(int a, int b);

    rational simplify(rational r){ 
        int gcd = r.gcd(r.nom, r.den);
        r.nom = r.nom/gcd;
        r.den = r.den/gcd;
        return r;
    }
};

//#endif /* babyratio_hpp */
