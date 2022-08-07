#ifndef MESSAGE
#define MESSAGE
#include <iostream>
#include <string>
#include <set>
#include <type_traits>
#include "Floder.h"
using std::string;
class Folder;

class Message
{
  friend class Folder;
  friend void swap(Message&, Message&);
public:
  explicit Message(const std::string &str = "") : contents(str) {}
  Message(const Message&);
  Message& operator=(const Message&);
  Message& operator=(Message);
  ~Message();
  void save(Folder&);
  void remove(Folder&);
private:
  std::string contents;
  std::set<Folder*> folders;
  void add_to_Folder(const Message&);
  void remove_from_Folders();
};

void Message::save(Folder& f)
{
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Floder &f)
{
  floders.erase(&f);
  f.remMsg(this);
}

void Message::add_to_Folder(const Message &m)
{
  for (auto f : m.folders)
  {
    f->addMsg(this);
  }
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
  add_to_Folder(m);
}

void Message::remove_from_Folders()
{
  for (auto f : folders)
  {
    f->remMsg(this);
  }
}

Message::~Message()
{
  remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folder(rhs);
  return *this;
}

inline
void swap(Message &lhs, Message &rhs)
{
  using std::swap;
  for (auto f : lhs.floders)
    f->remMsg(&rhs); 
  for (auto f : rhs.floders)
    f->remMsg(&rhs);
  swap(lhs.folders, rhs.folders);
  swap(lhs.contents, rhs.contents);
  for (auto f : lhs.folders)
  {
    f->addMsg(&lhs);
  }
  for (auto f : rhs.folders)
  {
    f->addMsg(&rhs);
  }
}

Message& Message::operator=(Message rhs)
{
  swap(*this, rhs);
  return *this;
}

class Folder
{
  friend void swap(Message &lhs, Message &rhs);
  friend void swap(Folder &lhs, Folder &rhs);
  friend class Message;
public:
  Folder()=default;
  Folder(const Folder&);
  Folder& operator=(const Folder&);
  ~Folder();
  void print_debug();

private:
  std::set<Message*> msgs;
  void add_to_Message(const Folder&);
  void remove_to_Message();
  void addMsg(Message* m) {msgs.insert(m);};
  void remMsg(Message* m) {msgs.erase(m);};
};

void swap(Folder& lhs, Folder& rhs);

void Folder::add_to_Message(const Folder& f)
{
	for (auto m : f.msgs)
		m->add_to_Folder(*m);
}

Folder::Folder(const Folder& f) :msgs(f.msgs)
{
	add_to_Message(f);
}

void Folder::remove_to_Message()
{
	for (auto m : msgs)
		m->remove_from_Folders();
	msgs.clear();
}

Folder::~Folder()
{
	remove_to_Message();
}

Folder& Folder::operator=(const Folder& rhs)
{
	remove_to_Message();
	msgs = rhs.msgs;
	add_to_Message(rhs);
	return *this;
}

void Folder::print_debug()
{
	for (auto m : msgs)
		std::cout << m->contents << " ";
	std::cout << std::endl;
}

#endif
