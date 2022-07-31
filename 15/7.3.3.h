#ifndef 7.3.3
#define 7.3.3

class Y;

class X 
{
  Y* y = nullptr;
};

class Y
{
  X x;
};

#endif
