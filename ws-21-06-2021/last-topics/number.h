struct Number {
    virtual double toDouble() = 0;
};

struct Integer: public Number {
    int x;
    Integer(int x);
    virtual double toDouble();
};

struct Real: public Number {
    double x;
    Real(double x);
    virtual double toDouble();
};

struct Rational: Integer {
    int den;
    Rational(int num, int den);
    virtual double toDouble();
};

Integer::Integer(int xx) {
    x = xx;
}

double Integer::toDouble() {
    return x;
}

Real::Real(double xx) {
    x = xx;
}

double Real::toDouble() {
    return x;
}

Rational::Rational(int n, int d): Integer(n) {
    den = d;
}

double Rational::toDouble() {
    return (double)x/den;
}
