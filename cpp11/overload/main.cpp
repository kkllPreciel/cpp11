template <class T>
class SmartPointer {
  T* p_ = nullptr;
public:
  // boolへの明示的な型変換演算子
  explicit operator bool() const
  {
    return p_;
  }
};

struct X {
  constexpr explicit operator bool() const
  {
    return true;
  }
};

int main()
{
  SmartPointer<int> p;

  // OK : if文による条件式のboolへの型変換
  if (p) {}
  else {}

  //p + 1;  // コンパイルエラー：暗黙の型変換演算子ではコンパイルが通っていた

  constexpr X x{};

  // bool b1 = x; // コンパイルエラー：boolへの暗黙変換
  bool b2 = (bool)x;
  bool b3 = static_cast<bool>(x);
  bool b4 = bool(x);
  //bool b5 = x == true;
  bool b6 = !x;
  bool b7 = !!x;
  bool b8 = x && true;

  if (x) {}

  bool b9 = x ? true : false;

  static_assert(x, "x must be bool");


  return 0;
}