template <class Derived>
class base {
  // �h���N���X����Abase�N���X��private�@�\�ɃA�N�Z�X�ł���悤�ɂ���
  friend Derived;

  // private�ȃf�t�H���g�R���X�g���N�^
  base() {}
};

class derived : public base<derived> {
};

int main()
{
  derived d;

  return 0;
}