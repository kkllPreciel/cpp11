class X {
public:
  // コピーを禁止し、ムーブを許可する
  X(const X&) = delete;
  X& operator = (const X&) = delete;

  // 特殊メンバ関数を明示的に定義もしくはdeleteした場合、
  // それ以外の特殊メンバ関数は明示的に定義もしくはdefault宣言しなければ
  // 暗黙定義されない
  X(X&&) = default;
  X() = default;
  X& operator=(X&&) = default;
};

void f() = delete;  // OK

int main()
{
  X x1;
  //X x2 = x1;  // コンパイルエラー! Xのコピーコンストラクタはdelete宣言されている
  X x3 = X(); // OK:ムーブコンストラクタはできる

  X x4;
  //x4 = x1;    // コンパイルエラー! Xのコピー代入演算子はdelete宣言されている

  X x5;
  x5 = X();   // OK:ムーブ代入はできる

  //f();        // コンパイルエラー! 関数f()はdelete宣言されている
}