#include <iostream>
#include <stack>
#include <deque>
#include <type_traits>

template <class T, class Container = std::deque<T>>
class movable_stack : public std::stack<T, Container> {
  using base = std::stack<T, Container>;

  static_assert(std::is_nothrow_default_constructible<T>{},
    "T must be nothrow default constructible");
  static_assert(std::is_nothrow_move_constructible<T>{},
    "T must be nothrow move constructible");

public:
  // クラスのテンプレートパラメータTに対して、
  // ムーブコンストラクタが例外を送出しないことを要求しているので、
  // pop操作は例外を送出することなくreturnで要素を返せる。
  std::pair<T, bool> move_pop() noexcept
  {
    if (base::empty()) {
      return std::make_pair(T(), false);
    }

    T x = std::move(base::top());
    base::pop();
    return std::make_pair(std::move(x), true);
  }
};

int main()
{
  movable_stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);

  while (!s.empty()) {
    int next_value = s.move_pop().first;
    std::cout << next_value << std::endl;
  }
}