#include <iostream>
#include <complex>
#include <string>

union X {
  int m1;
  std::complex<double> m2;  // クラスオブジェクトを
  std::string m3;           // 保持できる

  X() : m1(0) {}
  ~X() {}
};

int main()
{
  X x;

  // int型の値を代入する
  x.m1 = 3;
  std::cout << x.m1 << std::endl;

  // std::complex<double>型のオブジェクトを代入する
  x.m2 = std::complex<double>(1.0, 2.0);
  std::cout << x.m2 << std::endl;

  // デストラクタを呼び出す必要がある型に対しては、
  // 配置new構文でコンストラクタを使用してオブジェクト代入し、
  // 明示的にデストラクタを呼び出すこと
  new(&x.m3) std::string("hello");
  std::cout << x.m3 << std::endl;
  x.m3.~basic_string<char>();

  return 0;
}