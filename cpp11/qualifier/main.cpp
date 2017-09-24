#include <vector>
#include <utility>

class X {
  std::vector<int> data_;
public:
  X() : data_(100) {}

  // *thisが左辺値の場合は、保持しているvectorオブジェクトの参照を返す
  const std::vector<int>& data() const&
  {
    return data_;
  }

  // *thisが右辺値の場合は参照を返すと一時オブジェクトの寿命が尽きてしまうため、
  // ムーブで返す
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