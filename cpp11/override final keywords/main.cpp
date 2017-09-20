// 基底クラス
class base {
  virtual void func_final() final;
  virtual void func_virt();
  virtual void func_virt_int(int a);
  void func_non_virt();
};

// 派生クラス
class derived : public base {
  // NG, finalメンバ関数はオーバーライドできない
  // void func_final();

  // OK, オーバーライドできている
  void func_virt() override;

  // NG, 引数の個数、型が違っており、オーバーライドできない
  // void func_virt_int(short a) override;

  // NG, 基底クラスのfunc_non_virt()は仮想関数では無いので、オーバーライドできない
  // void func_non_virt() override;
};

// オーバーライド不可の基底クラス
class base_f final {
  virtual void func_virt();
};

// 派生クラス
//class derived : public base_f {
  //NG, final基底クラスのメンバ関数はオーバーライドできない
//  void func_virt();
//};

int main()
{
  return 0;
}