#include <vector>
#include <initializer_list>

template <class T>
class MyVector {
  std::vector<T> data_;
public:
  // リスト初期化用のコンストラクタ
  explicit MyVector(std::initializer_list<T> init) : data_(init.begin(), init.end())
  {

  }
};

struct X {
  X(std::initializer_list<int>) {}
};

X f()
{
  return { 1, 2, 3 };
}

void g(X)
{

}

int main()
{
  // MyVector<int> v = { 1, 2, 3 }; 明示的なコンパイルエラー
  MyVector<int> v{ 1, 2, 3 };

  X x1{ 1, 2, 3 };    // 直接初期化
  X{ 1, 2, 3 };       // 直接初期化(一時オブジェクト)
  X x2 = { 1, 2, 3 }; // コピー初期化

  X* x = new X{ 1, 2, 3 };
  delete x;

  g({ 1, 2, 3 });

  return 0;
}