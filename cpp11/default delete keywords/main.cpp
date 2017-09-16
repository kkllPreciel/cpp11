class X {
public:
  // �R�s�[���֎~���A���[�u��������
  X(const X&) = delete;
  X& operator = (const X&) = delete;

  // ���ꃁ���o�֐��𖾎��I�ɒ�`��������delete�����ꍇ�A
  // ����ȊO�̓��ꃁ���o�֐��͖����I�ɒ�`��������default�錾���Ȃ����
  // �Öْ�`����Ȃ�
  X(X&&) = default;
  X() = default;
  X& operator=(X&&) = default;
};

void f() = delete;  // OK

int main()
{
  X x1;
  //X x2 = x1;  // �R���p�C���G���[! X�̃R�s�[�R���X�g���N�^��delete�錾����Ă���
  X x3 = X(); // OK:���[�u�R���X�g���N�^�͂ł���

  X x4;
  //x4 = x1;    // �R���p�C���G���[! X�̃R�s�[������Z�q��delete�錾����Ă���

  X x5;
  x5 = X();   // OK:���[�u����͂ł���

  //f();        // �R���p�C���G���[! �֐�f()��delete�錾����Ă���
}