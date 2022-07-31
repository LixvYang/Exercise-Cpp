#ifndef Person
#define Person

#include <iostream>
#include <string>
using namespace std;

struct Person;
istream& read(std::istream&, Person&);

struct Person
{
friend istream& read(istream& is, Person& person);
friend ostream& print(ostream& os, const Person& person);

public:
  Person() = default;
  Person(const string& sname, const string& saddr) : name(sname), address(saddr) {}
  Person(istream& is) { read(is, *this); }

  auto get_name() const -> string const& { return name; }
  auto get_address() const -> string const& { return address; }

private:
  string name;
  string address;
};

istream& read(istream& is, Person& person)
{
  return is >> person.name >> person.address;
}

ostream& print(ostream& os, const Person& person)
{
  return os << person.name << " " << person.address;
}

#endif // !Person
