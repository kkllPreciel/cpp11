#include <iostream>

// add�̖߂�l�^�� lhs + rhs �̎��̌^
// typename�͂�����^
// class�̓N���X�^�̂�
template<typename T, typename U>
auto add(const T& lhs, const U& rhs) -> decltype(lhs + rhs)
{
  return lhs + rhs;
}

int main()
{
  // �֐��̌^
  auto r = add(1, 2.0f);
  std::cout << std::fixed << r << '\n';

  // �ϐ��̌^
  int i = 10;
  decltype(i) j = i;    // j��int�^
  decltype((i)) k = i;  // k��int&�^
  i = 42;
  std::cout << j << ',' << k << '\n';
}