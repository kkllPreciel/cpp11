#include <iostream>

namespace my_namespace {
  inline namespace features {
    void f() {}
  };

  void g() {}
};

namespace version {
  namespace v1 {
    void f()
    {
      std::cout << "v1" << std::endl;
    }
  }

  inline namespace v2 {
    void f()
    {
      std::cout << "v2" << std::endl;
    }
  }
};

int main()
{
  {
    // my_namespace::features名前空間も含む
    // my_namespace名前空間以下の機能を、名前空間修飾なしで
    // アクセスできるようにする
    using namespace my_namespace;
    f();
    g();
  }
  {
    // my_namespace::features名前空間以下の機能だけを
    // 名前空間修飾なしでアクセスできるようにする
    using namespace my_namespace::features;
    f();
    my_namespace::g();
  }
  {
    version::v1::f(); // 古いバージョンのAPIを呼び出す
    version::v2::f(); // バージョンを明示的に指定してAPIを呼び出す
    version::f();     // デフォルトバージョンのAPIを呼び出す
  }
}