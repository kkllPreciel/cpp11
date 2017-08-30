#include <iostream>
#include <vector>

// ����R���e�i�N���X
class container
{
public:
  int* begin()
  {
    return &buf[0];
  }

  int* end()
  {
    return &buf[5]; ///< ����(�T�C�Y + 1�̓Y����)
  }

private:
  int buf[5] = { 21, 22, 23, 24, 25 };
};

int main()
{
  // C++03
  std::vector<int> v;
  for (std::vector<int>::const_iterator it = v.begin(), e = v.end(); it != e; ++it)
  {
    std::cout << *it << std::endl;
  }

  // C++11
  for (const auto& e : v)
  {
    std::cout << e << std::endl;
  }

  // �z��ɑ΂��Ĕ͈�for�����g��
  int array[5] = { 1, 2, 3, 4, 5 };
  std::cout << "For int[5]:" << std::endl;
  for (auto& e : array)
  {
    std::cout << " " << e << std::endl;
  }

  // �W���R���e�i�ɑ΂��Ĕ͈�for�����g��
  std::vector<int> vec = { 10, 11, 12, 13 };
  std::cout << "For std::vector<int>:" << std::endl;
  for (auto& e : vec)
  {
    std::cout << " " << e << std::endl;
  }

  // ���[�U�[��`�̃N���X�ɑ΂��Ĕ͈�for�����g��
  container con;
  std::cout << "For my_container:" << std::endl;
  for (auto& e : con)
  {
    std::cout << " " << e << std::endl;
  }

  return 0;
}