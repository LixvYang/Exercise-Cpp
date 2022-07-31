#ifndef Screen
#define Screen

#include <ostream>
#include <string>
using namespace std;

class Screen
{
public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wt, char c) : height(ht), width(wt), contents(ht * wt, c) {}
  Screen(pos ht, pos wt) : height(ht), width(wt), contents(ht * wt, ' ') {}
  Screen(post ht, pos wt, char c) : height(ht), width(wt), contents(ht * wt, c) {}
  char get() const { return contents[cursor]; }
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  void some_member() const;
  Screen &set(char);
  Screen &set(pos, pos, char);

  Screen &display(ostream &os) {do_display(os); return *this;}
  const Screen &display(ostream &os) const { do_display(os); return *this; }
private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  mutable size_t access_ctd;
  void do_display(ostream &os) const {os << contents;}
};

inline
Screen &Screen::move(pos ht, pos c)
{
  pos row = r * width;
  cursor = row + c;
  return *this;
}
char Screen::get(pos r, pos c) const 
{ 
  pos row = r * width; 
  return contents[row + c];
}

void Screen::some_member() const {
  ++access_ctd;
}

inline Screen &Screen::set(char c)
{
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
  contents[r*width + col] = ch;
  return *this;
}
#endif 
