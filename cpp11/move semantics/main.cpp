#include <vector>

struct Foo
{

};

int f()
{
  return 0;
}

int main()
{
  int i = 0;
  i;		// 名前付きオブジェクトは左辺値
  0;		// リテラル値は右辺値

  Foo x;
  x;		// 名前付きオブジェクトは左辺値
  Foo();	// コンストラクタの戻り値は右辺値

  f();		// 関数の戻り値は右辺値

  std::vector<int> v, vv;
  v = vv;						// 左辺値参照
  v = std::vector<int>(100, 0);	// 右辺値参照

  return 0;
}