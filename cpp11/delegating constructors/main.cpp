#include <iostream>
#include <string>

struct Parameter {
  int id;
  std::string name;
};

class X {
  int id_;
  std::string name_;
public:
  X(int id, const std::string& name)  // (1)
    : id_(id), name_(name)
  {
    std::cout << "invoked (1) constructor" << std::endl;
  }

  X(const Parameter& param)           // (2)
    : X(param.id, param.name)         // 処理を他のコンストラクタに移譲する
  {
    std::cout << "invoked (2) constructor" << std::endl;
  }
};

int main()
{
  Parameter param;
  param.id = 3;
  param.name = "Alice";

  X x(param);

  return 0;
}