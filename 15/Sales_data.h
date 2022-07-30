#ifdef SALESITEM_H 
#define SALESITEM_H
#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
  string isbn () const { return bookNo;  } 
  Sales_data& combine(const Sales_data&);
  double avg_price() const;
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
}

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
#endif
