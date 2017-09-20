// ���N���X
class base {
  virtual void func_final() final;
  virtual void func_virt();
  virtual void func_virt_int(int a);
  void func_non_virt();
};

// �h���N���X
class derived : public base {
  // NG, final�����o�֐��̓I�[�o�[���C�h�ł��Ȃ�
  // void func_final();

  // OK, �I�[�o�[���C�h�ł��Ă���
  void func_virt() override;

  // NG, �����̌��A�^������Ă���A�I�[�o�[���C�h�ł��Ȃ�
  // void func_virt_int(short a) override;

  // NG, ���N���X��func_non_virt()�͉��z�֐��ł͖����̂ŁA�I�[�o�[���C�h�ł��Ȃ�
  // void func_non_virt() override;
};

// �I�[�o�[���C�h�s�̊��N���X
class base_f final {
  virtual void func_virt();
};

// �h���N���X
//class derived : public base_f {
  //NG, final���N���X�̃����o�֐��̓I�[�o�[���C�h�ł��Ȃ�
//  void func_virt();
//};

int main()
{
  return 0;
}