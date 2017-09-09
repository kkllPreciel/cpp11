//
// https://cpprefjp.github.io/lang/cpp11/constexpr.html
//

#include <cassert>

constexpr int square(int x)
{
  return x * x;
}

int main()
{
  // �R���p�C����assert
  constexpr int compile_time_result = square(3);
  static_assert(compile_time_result == 9, "result must be 9");

  // ���s��assert
  int runtime_result = square(3);
  assert(runtime_result == 9);

  // constexpr�R���X�g���N�^
}