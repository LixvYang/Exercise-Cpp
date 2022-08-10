#ifndef __COMPLEX__
#define __COMPLEX__

#include <cmath>

class ostream;
class complex;

complex& __doapl (complex& ths, const complex&);

class complex
{
public:
  complex(double r = 0, double i = 0) : re(r), im(i) {};
  complex() : re(0), im(0) {};
  complex& operator+=(const complex&);
  double real() const { return re; }
  double imag() const { return im; }

private:
  double re, im;

  friend complex& __doapl (complex& ths, const complex&);
};

#endif 

