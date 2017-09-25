#include <iostream>
#include <complex>
#include <string>

union X {
  int m1;
  std::complex<double> m2;  // �N���X�I�u�W�F�N�g��
  std::string m3;           // �ێ��ł���

  X() : m1(0) {}
  ~X() {}
};

int main()
{
  X x;

  // int�^�̒l��������
  x.m1 = 3;
  std::cout << x.m1 << std::endl;

  // std::complex<double>�^�̃I�u�W�F�N�g��������
  x.m2 = std::complex<double>(1.0, 2.0);
  std::cout << x.m2 << std::endl;

  // �f�X�g���N�^���Ăяo���K�v������^�ɑ΂��ẮA
  // �z�unew�\���ŃR���X�g���N�^���g�p���ăI�u�W�F�N�g������A
  // �����I�Ƀf�X�g���N�^���Ăяo������
  new(&x.m3) std::string("hello");
  std::cout << x.m3 << std::endl;
  x.m3.~basic_string<char>();

  return 0;
}