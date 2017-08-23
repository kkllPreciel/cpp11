#include <iostream>
#include <memory>
#include <initializer_list>

// 名前空間スコープでの変数宣言
auto v = { 1, 7, 3, 2, 0, 5, 0, 8, }; // vはstd::initializer_list<int>型

std::unique_ptr<int> create_unique_ptr(int i)
{
  // new 式の型名指定部
  return std::unique_ptr<int>(i != 0 ? new auto(i) : nullptr); // new auto(i)はint*型
}

int main()
{
  // for分の初期化文での変数宣言
  for (auto it = v.begin(), e = v.end(); it != e; ++it) { // itとeはconst int*型
    // if文の条件部での変数宣言
    if (auto ptr = create_unique_ptr(*it)) { // ptrはstd::unique_ptr<int>型
      std::cout << *ptr << ",";
    }
    else {
      std::cout << "null,";
    }
  }
  std::cout << '\n';

  // ブロックスコープでの変数宣言
  static auto s = "C++"; //　sはconst char*型

  // for文の初期化文、および、条件部での変数宣言
  for (auto p = s; auto elem = *p; ++p) { // pはconst char*型 elemはchar型
    std::cout << elem << ',';
  }
  std::cout << '\n';
  return 0;
}