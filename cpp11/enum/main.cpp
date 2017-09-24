#include <cassert>
#include <type_traits>

enum class Color { Red, Green, Blue };
enum class CharColor : char { Red, Green, Blue }; // ���^��char�ɂ���

int main()
{
  // �P��Red�Ǝw�肷��̂ł͂Ȃ��A�ǂ̗񋓌^�ɑ�����̂����w�肷��
  Color c = Color::Red;

  // �����I�Ȍ^�ϊ��͋�����
  int colorValue = static_cast<int>(Color::Red);
  // int colorValue = Color::Red;  // �R���p�C���G���[�F�Öق̌^�ϊ��͂ł��Ȃ�
  assert(colorValue == 0);

  // �񋓌^�̊��^���擾���āA���̌^�ɃL���X�g
  auto colorValue2 = static_cast<std::underlying_type<Color>::type>(Color::Red);
  assert(colorValue2 == 0);

  return 0;
}