#include <iostream>

// add‚Ì–ß‚è’lŒ^‚Í lhs + rhs ‚Ì®‚ÌŒ^
// typename‚Í‚ ‚ç‚ä‚éŒ^
// class‚ÍƒNƒ‰ƒXŒ^‚Ì‚İ
template<typename T, typename U>
auto add(const T& lhs, const U& rhs) -> decltype(lhs + rhs)
{
  return lhs + rhs;
}

int main()
{
  // ŠÖ”‚ÌŒ^
  auto r = add(1, 2.0f);
  std::cout << std::fixed << r << '\n';

  // •Ï”‚ÌŒ^
  int i = 10;
  decltype(i) j = i;    // j‚ÍintŒ^
  decltype((i)) k = i;  // k‚Íint&Œ^
  i = 42;
  std::cout << j << ',' << k << '\n';
}