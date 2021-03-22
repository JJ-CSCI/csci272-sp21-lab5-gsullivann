//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here

class Real {
protected:
  double a;
public: 
  Real(double x):  a{x} {}
  double GetReal() { return a;}

  Real operator*(double s) {
    Real res{a*s};
    return res;
  }
};

class Complex: public Real {
protected:
  double b;
public:
  Complex( double x, double y) : Real(x), b{y} {}
  //Real(x) -> x=a , b{y} -> y=b
  double GetImaginary() {return b; }
  Complex operator*(double s) {
    Complex res{a*s, b*s};
    return res;
  }
};

class Surreal: public Complex {
protected:
  double c;
public:
  Surreal( double x, double y, double z) : Complex(x,y), c{z} {}
  double GetSurreal() { return c; }
  Surreal operator *(double s) {
    Surreal res{a*s, b*s, c*s};
    return res;
  }
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
        REQUIRE( r.GetSurreal() == 32.0 );
    }
}
//------------------------------
