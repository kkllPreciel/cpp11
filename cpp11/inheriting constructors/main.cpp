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
  // Base1��Base2�̃R���X�g���N�^���ADerived�ňÖٓI�ɐ錾����
  using Base1::Base1;
  using Base2::Base2;

  // Derived(), Derived(int), Derived(const std::string&)���Öِ錾�����

  // Base2::Base2(const std::string&)�̃R���X�g���N�^�����́A
  // �Öِ錾���ꂽ���̂��g�p�����ɁA�����I�ɐ錾����B
  Derived(const std::string& s) : Base2::Base2(s) {}
};

int main()
{
  Derived d1(3);        // OK
  Derived d2("hello");  // OK

  return 0;
}