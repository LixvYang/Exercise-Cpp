#ifndef StrVec
#define StrVec

#include <memory>
#include <string>
#include <utility>
using namespace std;
class StrVec;

class StrVec
{
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &);
  StrVec &operater = (const StrVec &);
  ~StrVec();
  void push_back(const std::string &);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }

private:
  static std::allocator<std::string> alloc;
  void cnk_n_alloc()
  {
    if (size() == capacity())
      reallocate();
  }
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
  void free();
  void reallocate();
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};

void StrVec::push_back(const std::string &s)
{
  chk_n_alloc();
  allc.construct(first_free++, s);
}

std::pair<string *, string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
  auto data = alloc.allocate(e - b);
  return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
  if (elements)
  {
    for (auto p = first_free; p != elements;)
    {
      alloc.destroy(--p);
    }
    alloc.deallocate(elements, cap - elements);
  }
}

StrVec::StrVec(const StrVec &s)
{
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
  free();
}

StrVec &StrVec::operater = (const StrVec &rhs)
{
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

#endif
