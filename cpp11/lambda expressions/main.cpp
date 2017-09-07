#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void f()
{
  int x = 3;

  // この時点で見える自動変数を参照でキャプチャし、
  // 参照した変数xを書き換える
  auto f = [&] { x = 1; };

  // 個別にキャプチャ方法を指定する場合は、
  // 以下のように、&の次に変数名を指定する
  // auto f = [&x] { x = 1; };

  f(); // x == 1
}

void g()
{
  int x = 3;

  // この時点で見える自動変数をコピーでキャプチャし、
  // コピーした変数xをラムダ式内で使用する
  auto f = [=] { return x + 1; };

  // 個別にきゃぷた方法を指定する場合は、
  // 以下のように、変数名を指定する
  // auto f = [x] { return x + 1; };

  int result = f(); // result == 4;
}

class X
{
  int member_value_ = 3;

  void bar()
  {
    std::cout << "bar" << std::endl;
  }

public:
  void foo()
  {
    int copy_value = 4;

    auto f = [this, copy_value] {
      member_value_ = 5;  // メンバ変数を参照する
      bar();  // メンバ関数を呼び出す

      return copy_value * 2; // コピーキャプチャしたローカル変数を使用する
    };

    int result = f();
    std::cout << "menber_value_:" << member_value_ << std::endl;
    std::cout << "result:" << result << std::endl;
  }
};

// 関数ポインタへの変換
void foo(int(*fp)(int, int))
{
  int result = fp(2, 3);
  std::cout << result << std::endl;
}

void proc(std::function<void()> on_complete)
{
  // …時間のかかる処理…
  for (int i = 0; i < 10; ++i) {
    std::cout << i << std::endl;
  }

  // 完了ハンドラを呼び出す
  on_complete();
}

int main()
{
  X().foo();

  foo([](int a, int b) { return a + b; });

  ///// アルゴリズムの引数として関数を渡す
  std::vector<int> v = { 1, 2, 3, 4, 5 };
  // 条件一致する最初の要素を検索する
  decltype(v)::iterator it = std::find_if(
    v.begin(), v.end(), [](int x) { return x % 2 == 0; }
  );
  // 見つかった
  if (it != v.end())
  {
    int found_value = *it;
    std::cout << found_value << std::endl;
  }

  ///// 処理が完了したことが通知されるハンドラを引数として渡す
  proc([] {
    std::cout << "complete" << std::endl;
  });

  return 0;
}