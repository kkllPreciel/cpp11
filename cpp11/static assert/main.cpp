#include <type_traits>

template <class T>
struct X {
	static_assert(std::is_integral<T>::value, "template parameter T must be integral type");
};

int main()
{
	X<int>(); // OK
	//X<double>();	// コンパイルエラー：template parameter T must be integral type
}