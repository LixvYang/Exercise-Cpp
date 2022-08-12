#ifndef __COMPLEX__
#define __COMPLEX__

#include <cmath>
#include <iostream>

class ostream;
class complex;

complex &__doapl(complex *ths, const complex &);

class complex
{
  friend complex &__doapl(complex *ths, const complex &);

public:
  complex(double r = 0, double i = 0) : re(r), im(i) {}
  complex() : re(0), im(0) {}
  complex &operator+=(const complex &);
  double real() const { return re; }
  double imag() const { return im; }

private:
  double re, im;
};

inline complex &
__doapl(complex *ths, const complex &r)
{
  ths->re += r.re;
  ths->im += r.im;
  return *ths;
}

inline complex &
complex::operator+=(const complex &r)
{
  return __doapl(this, r);
}

inline complex operator+(const complex &x, const complex &y)
{
  return complex(
      x.real() + y.real(),
      x.imag() + y.imag());
}

inline complex
operator+(const complex &x, double y)
{
  return complex(real(x), imag(x));
}

ostream &operator<<(ostream &os, const complex &x)
{
  return os << x.imag() << " " << x.real() << ")";
}

class Fraction
{
public:
  Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
  operator double() const { return (double)(m_numerator / m_denominator); }

private:
  int m_numerator;
  int m_denominator;
};

#endif