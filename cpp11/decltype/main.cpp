#include <iostream>

// addの戻り値型は lhs + rhs の式の型
// typenameはあらゆる型
// classはクラス型のみ
template<typename T, typename U>
auto add(const T& lhs, const U& rhs) -> decltype(lhs + rhs)
{
  return lhs + rhs;
}

int main()
{
  // 関数の型
  auto r = add(1, 2.0f);
  std::cout << std::fixed << r << '\n';

  // 変数の型
  int i = 10;
  decltype(i) j = i;    // jはint型
  decltype((i)) k = i;  // kはint&型
  i = 42;
  std::cout << j << ',' << k << '\n';
}