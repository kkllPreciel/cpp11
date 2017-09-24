#include <cassert>
#include <type_traits>

enum class Color { Red, Green, Blue };
enum class CharColor : char { Red, Green, Blue }; // 基底型をcharにする

int main()
{
  // 単にRedと指定するのではなく、どの列挙型に属するのかを指定する
  Color c = Color::Red;

  // 明示的な型変換は許可する
  int colorValue = static_cast<int>(Color::Red);
  // int colorValue = Color::Red;  // コンパイルエラー：暗黙の型変換はできない
  assert(colorValue == 0);

  // 列挙型の基底型を取得して、その型にキャスト
  auto colorValue2 = static_cast<std::underlying_type<Color>::type>(Color::Red);
  assert(colorValue2 == 0);

  return 0;
}