#include "sales_data2.h"
#include <istream>
#ifndef Sales_data
#define Sales_data

#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
friend Sales_data add(const Sales_data&, const Sales_data&);
friend istream &read(istream&, Sales_data&);
friend ostream &print(ostream&, Sales_data&);

public:
  Sales_data() = default;
  Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revence(p*n) {}
  Sales_data(const string &s) : bookNo(s) {}
  Sales_data(istream &);
  string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data&);

private:
  inline double avg_price() const;

private:
  string bookNo;
  unsigned units_sold = 0;
  double revence = 0.0;
};

inline double Sales_data::avg_price() const
{
  return units_sold ? revence / units_sold : 0;
}

Sales_data &combine(const Sales_data& rhs)
{
  units_sold += rhs.units_sold;
  revence += rhs.revence;
  return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}
istream &read(istream& is, Sales_data& item) 
{
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revence = price * item.units_sold;
  return is;
}
ostream &print(ostream& os, Sales_data& item)
{
  os << item.isbn() << " " << item.units_sold << " " << item.revence;
  return os;
}

#endif
