#ifdef HASPTR
#define HASPTR

#include <string>
using namespace std;

class HasPtr
{
public:
  HasPtr(const string& s = string()): ps(new string()), i(0) {}
  HasPtr(const HasPtr& hp) :ps(new string(*hp.ps)), i(hp.i) {} 
  HasPtr& operator=(const HasPtr& hp)
  {
    string *new_ps = new string(*hp.ps);
    delete ps;
    ps = new_ps;
    i = hp.i;
    return *this;
  }

private:
  string *ps;
  int i;
};

class HasPtr
{
public:
    HasPtr(const string& s = string()): ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use) {++*use};
    HasPtr& operater=(const HasPtr&);
    HasPtr& operator=(HasPtr&);
    friend void swap(HasPtr&, HasPtr&);
    ~HasPtr();
private:
    string *ps;
    int i;
    size_t *use;
};  

HasPtr::~HasPtr()
{
  if (--*use == 0) {
    delete ps;
    delete use;
  }
}

void swap(HasPtr &lhs, HasPtr &rhs)
{
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}

HasPtr& HasPtr::operator=(HasPtr rhs)
{
  swap(*this, rhs);
  return *this;
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
  ++*rhs.use;
  if (--*use == 0)
  {
    delete ps;
    delete use;
  }
  ps = rhs.ps;
  i = rhs.i;
  use = rhs.use;
  return *this;
}

#endif

