#include <string>
#include <iostream>
#include <vector>
#include <iterator>

struct X {
  X(int) {}
};

struct Y {
  Y(int, double, std::string) {}
};

struct Z {
};

Y createY()
{
  return { 1, 3.14, "hello" }; // OK
}

int main()
{
  // 従来のコンストラクタ呼び出し
  X x1(0);
  X x2 = 0;

  // 一様初期化構文によるコンストラクタ呼び出し
  X x3{ 0 };
  X x4 = { 0 };

  Z x();  // xは引数を持たず Z を返す関数の宣言！(恐らく意図と異なる)
  Z y{ }; // yはデフォルトコンストラクタで初期化した Z 型の変数

    return 0;
}

