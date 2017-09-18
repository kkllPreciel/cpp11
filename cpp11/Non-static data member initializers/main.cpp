#include <string>
#include <cassert>

struct Person {
  int id = 3;
  std::string name = "Alice";
  std::string description{ "Hello everyone" };
};

class X {
  int id_ = 3;
  std::string data_ = "hello";
public:
  // id_は4で初期化され、data_は"hello"で初期化される。
  // 「id_ = 3」の初期化式は実行されない
  X() : id_(4) {}

  // id_はパラメータidで初期化され、data_は"world"で初期化される。
  // 「id_ = 3」の初期化式は実行されない。
  // 「data_ = "hello"」の初期化式は実行されない。
  X(int id) : id_(id), data_("world") {}
};

int main()
{
  Person p;

  assert(p.id == 3);
  assert(p.name == "Alice");
  assert(p.description == "Hello everyone");

  return 0;


}