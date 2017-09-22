template <class T>
class SmartPointer {
  T* p_ = nullptr;
public:
  // bool�ւ̖����I�Ȍ^�ϊ����Z�q
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

  // OK : if���ɂ���������bool�ւ̌^�ϊ�
  if (p) {}
  else {}

  //p + 1;  // �R���p�C���G���[�F�Öق̌^�ϊ����Z�q�ł̓R���p�C�����ʂ��Ă���

  constexpr X x{};

  // bool b1 = x; // �R���p�C���G���[�Fbool�ւ̈Öٕϊ�
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