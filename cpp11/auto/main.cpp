#include <iostream>
#include <memory>
#include <initializer_list>

// ���O��ԃX�R�[�v�ł̕ϐ��錾
auto v = { 1, 7, 3, 2, 0, 5, 0, 8, }; // v��std::initializer_list<int>�^

std::unique_ptr<int> create_unique_ptr(int i)
{
  // new ���̌^���w�蕔
  return std::unique_ptr<int>(i != 0 ? new auto(i) : nullptr); // new auto(i)��int*�^
}

int main()
{
  // for���̏��������ł̕ϐ��錾
  for (auto it = v.begin(), e = v.end(); it != e; ++it) { // it��e��const int*�^
    // if���̏������ł̕ϐ��錾
    if (auto ptr = create_unique_ptr(*it)) { // ptr��std::unique_ptr<int>�^
      std::cout << *ptr << ",";
    }
    else {
      std::cout << "null,";
    }
  }
  std::cout << '\n';

  // �u���b�N�X�R�[�v�ł̕ϐ��錾
  static auto s = "C++"; //�@s��const char*�^

  // for���̏��������A����сA�������ł̕ϐ��錾
  for (auto p = s; auto elem = *p; ++p) { // p��const char*�^ elem��char�^
    std::cout << elem << ',';
  }
  std::cout << '\n';
  return 0;
}