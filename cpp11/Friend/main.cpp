template <class Derived>
class base {
  // 派生クラスから、baseクラスのprivate機能にアクセスできるようにする
  friend Derived;

  // privateなデフォルトコンストラクタ
  base() {}
};

class derived : public base<derived> {
};

int main()
{
  derived d;

  return 0;
}