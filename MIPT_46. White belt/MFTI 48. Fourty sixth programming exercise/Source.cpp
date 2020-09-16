#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <exception>
using namespace std;
class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }
    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw 1;
        }
        else if (denominator < 0) {
            if (numerator < 0) {
                denominator = abs(denominator);
                numerator = abs(numerator);
            }
            else {
                denominator = abs(denominator);
                numerator = numerator - 2 * numerator;
            }
        }
        if (numerator == 0) {
            denominator = 1;
        }

        int nod = Nod(abs(numerator), abs(denominator));
        num = numerator / nod;
        den = denominator / nod;
    }
    int Numerator() const {
        return num;
    }
    int Denominator() const {
        return den;
    }
private:
    int num;
    int den;

    int Nod(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            }
            else {
                b %= a;
            }
        }
        return a + b;
    }
};
bool operator == (Rational a, Rational b) {
    if ((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator())) {
        return true;
    }
    else {
        return false;
    }
}
Rational operator + (Rational a, Rational b) {
    int p = (a.Numerator() * b.Denominator()) + (b.Numerator() * a.Denominator());
    int q = a.Denominator() * b.Denominator();
    return Rational(p, q);
}
Rational operator - (Rational a, Rational b) {
    int p = (a.Numerator() * b.Denominator()) - (b.Numerator() * a.Denominator());
    int q = a.Denominator() * b.Denominator();
    return Rational(p, q);
}
Rational operator * (Rational a, Rational b) {
    return Rational((a.Numerator() * b.Numerator()), (a.Denominator() * b.Denominator()));
}
Rational operator / (Rational a, Rational b) {
    if (b.Numerator() == 0) {
        throw 2;
    }
    return Rational((a.Numerator() * b.Denominator()), (a.Denominator() * b.Numerator()));
}
istream& operator >> (istream& stream, Rational& r) {
    int p, q;
    if (stream >> p && stream.ignore(256, '/') && stream >> q) {
        r = { p, q };
    }
    return stream;
}
ostream& operator << (ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}
bool operator > (Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}
bool operator < (Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}

int main() {
    try {
        Rational a, b;
        char operation;
        cin >> a >> operation >> b;
        if (operation == '+') {
            cout << a + b;
        }
        else if (operation == '-') {
            cout << a - b;
        }
        else if (operation == '/') {
            cout << a / b;
        }
        else if (operation == '*') {
            cout << a * b;
        }
    }
    catch (int n) {
        if (n == 1) {
            cout << "Invalid argument";
        }
        else {
            cout << "Division by zero";
        }
    }
    return 0;
}