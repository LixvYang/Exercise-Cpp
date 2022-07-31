#ifdef SALESITEM_H 
#define SALESITEM_H
#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
  Sales_data() = default;
  Sales_data(const string &s) : bookNo(s) { }
  Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) {}
  Sales_data(): units_sold(0), revence(0) {}
  Sales_data(istream &is) {return read(is, *this)};

  string isbn () const { return bookNo;  } 
  Sales_data& combine(const Sales_data&);

  double avg_price() const;
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

double Sales_data::avg_price() const {
  if (units_sold)
    return revenue/units_sold;
  else
    return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revence += rhs.revenus;
  return*this;
}

istream &read(istream &is, Sales_data &item)
{
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revence = price * item.units_sold;
  return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
  os << item.isbn() << " " << item.units_sold << " "
     << item.revence << " " << item.avg_price();
  return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

#endif
