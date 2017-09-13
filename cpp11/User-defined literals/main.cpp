#include <iostream>
#include <string>

namespace my_namespace {
  inline namespace literals {
    std::string operator"" _s(const char* str, std::size_t length)
    {
      return std::string(str, length);
    }
  };
};

int main()
{
  using namespace my_namespace::literals;

  auto x = "hello"_s; // x‚ÌŒ^‚Ístd::string
  std::cout << x << std::endl;

  return 0;
}