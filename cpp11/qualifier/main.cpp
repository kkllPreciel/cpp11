#include <vector>
#include <utility>

class X {
  std::vector<int> data_;
public:
  X() : data_(100) {}

  // *this�����Ӓl�̏ꍇ�́A�ێ����Ă���vector�I�u�W�F�N�g�̎Q�Ƃ�Ԃ�
  const std::vector<int>& data() const&
  {
    return data_;
  }

  // *this���E�Ӓl�̏ꍇ�͎Q�Ƃ�Ԃ��ƈꎞ�I�u�W�F�N�g�̎������s���Ă��܂����߁A
  // ���[�u�ŕԂ�
  std::vector<int> data() &&
  {
    return std::move(data_);
  }
};

int main()
{
  X x;

  const std::vector<int>& v1 = x.data();
  std::vector<int> v2 = X().data();

  return 0;
}