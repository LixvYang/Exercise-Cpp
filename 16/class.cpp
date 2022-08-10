#ifndef QUOTE
#define QUOTE

#include <cstddef>
#include <string>
using namespace std;

class Quote
{
  public:
    Quote()=default;
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {};
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; };
    virtual ~Quote()=default;
  private:
    string bookNo;
  protected:
    double price = 0.0;
};

class Bulk_quote : public Quote 
{
  public:
    Bulk_quote()=default;
    Bulk_quote(const string& book, double p, size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {}
    double net_price(size_t) const override;
  private:
    size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const 
{
  if (cnt >= min_qty)
    return cnt * (1-discount) * price;
  else
    return cnt * price;
}

class Limit_quote : public Quote 
{
  public:
    Limit_quote()=default;
    Limit_quote(const string &b, double p, size_t max, double disc) : Quote(b, p), max_qty(max), discount(disc) {}
    double net_price(size_t n) const override;

  private:
    size_t max_qty = 0;
    double discount = 0.0;
};

double Limit_quote::net_price(size_t n) const 
{
  if (n > this->max_qty)
    return max_qty * price * discount + (n - max_qty) * price;
  else
    return n * discount * price;
}

#endif // QUANT
