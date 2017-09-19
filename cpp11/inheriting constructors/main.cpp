#include <string>

struct Base1 {
  Base1() {}
  Base1(int) {}
};

struct Base2 {
  Base2() {}
  Base2(const std::string&) {}
};

struct Derived : Base1, Base2 {
  // Base1とBase2のコンストラクタを、Derivedで暗黙的に宣言する
  using Base1::Base1;
  using Base2::Base2;

  // Derived(), Derived(int), Derived(const std::string&)が暗黙宣言される

  // Base2::Base2(const std::string&)のコンストラクタだけは、
  // 暗黙宣言されたものを使用せずに、明示的に宣言する。
  Derived(const std::string& s) : Base2::Base2(s) {}
};

int main()
{
  Derived d1(3);        // OK
  Derived d2("hello");  // OK

  return 0;
}