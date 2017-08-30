#include <iostream>
#include <vector>

// 自作コンテナクラス
class container
{
public:
  int* begin()
  {
    return &buf[0];
  }

  int* end()
  {
    return &buf[5]; ///< 注意(サイズ + 1の添え字)
  }

private:
  int buf[5] = { 21, 22, 23, 24, 25 };
};

int main()
{
  // C++03
  std::vector<int> v;
  for (std::vector<int>::const_iterator it = v.begin(), e = v.end(); it != e; ++it)
  {
    std::cout << *it << std::endl;
  }

  // C++11
  for (const auto& e : v)
  {
    std::cout << e << std::endl;
  }

  // 配列に対して範囲for文を使う
  int array[5] = { 1, 2, 3, 4, 5 };
  std::cout << "For int[5]:" << std::endl;
  for (auto& e : array)
  {
    std::cout << " " << e << std::endl;
  }

  // 標準コンテナに対して範囲for文を使う
  std::vector<int> vec = { 10, 11, 12, 13 };
  std::cout << "For std::vector<int>:" << std::endl;
  for (auto& e : vec)
  {
    std::cout << " " << e << std::endl;
  }

  // ユーザー定義のクラスに対して範囲for文を使う
  container con;
  std::cout << "For my_container:" << std::endl;
  for (auto& e : con)
  {
    std::cout << " " << e << std::endl;
  }

  return 0;
}