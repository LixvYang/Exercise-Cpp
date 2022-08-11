#ifndef __STRING__
#define __STRING__
#include <complex.h>
#include <cstring>
using namespace std;
class String;

class String
{
  public:
    String(const char* ctrs=0);
    String(const String& str);
    String& operator=(const String& str);
    ~String();
    char* get_c_str() const { return m_data; };
  private:
    char* m_data;
};  

inline 
String::String(const char* cstr)
{
  if (cstr) {
    m_data = new char[strlen(cstr) + 1];
    strcpy(m_data, cstr); 
  } else {
    m_data = new char[1];
    *m_data = '\0';
  }
}

inline
String::~String()
{
  delete [] m_data;
}

inline
String::String(const String& str)
{
  m_data = new char[ strlen(str.m_data)+1 ];
  strcpy(m_data, str.m_data);
}

inline
String& String::operator=(const String &str)
{
  if (this == &str)
  {
    return *this;
  }
  delete [] m_data;
  m_data = new char[ strlen(str.m_data)+1 ];
  strcpy(m_data, str.m_data);
  return *this;
}

template<typename T>
class complex
{
  private:
    T re, im;
};

class store
{
  public:
    store(int w, int h, int we): _w(w), _h(h), _weight(we) {}
    bool operator<(const store& rhs) const { return _weight < rhs._weight; }
  
  private:
    int _w, _h, _weight;
};

template <class T>
inline
const T& min(const T& a, const T& b)
{
  return b < a ? b : a;
}

#endif
