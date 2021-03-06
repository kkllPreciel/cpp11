#include <utility>
#include <type_traits>
#include <iostream>
#include <string>

#define META_FUNCTION

#ifndef META_FUNCTION

// bool型の戻り値を持つテンプレート(詳細はカンマ演算子で検索)
template <class T1, class T2>
auto is_addable(T1 a, T2 b) -> decltype(a + b, bool())
{
	std::cout << "型T1とT2の間で、+演算子による加算が可能" << std::endl;
	return true;
}

auto is_addable(...) -> bool
{
	std::cout << "型T1とT2の間では、+演算子による加算はできない" << std::endl;
	return false;
}
#else
struct is_addable_impl {
	// 要件を満たしていればtrue_type型を返す
	template <class T, class U>
	static auto check(T*, U*) -> decltype(
		std::declval<T>() + std::declval<U>(),
		std::true_type());

	// 要件を満たしていなければfalse_type型を返す
	template <class T, class U>
	static auto check(...)->std::false_type;
};

template <class T, class U>
struct is_addable : decltype(is_addable_impl::check<T, U>(nullptr, nullptr)) {};

struct is_complete_type_impl {
	// sizeof(T)が有効かどうかで完全型かを判定する
	template <class T>
	static auto check(T*) -> decltype(
		sizeof(T),
		std::true_type());

	template<class T>
	static auto check(...)->std::false_type;
};

template<class T>
struct is_complete_type
	: decltype(is_complete_type_impl::check<T>(nullptr)) {};

struct A {};
struct B;

template <class... Args>
struct is_callable_impl {
	template <class F>
	static std::true_type
		check(decltype(std::declval<F>()(std::declval<Args>()...), (void)0)*);

	template <class F>
	static std::false_type check(...);
};

template <class F, class... Args>
struct is_callable
	: decltype(is_callable_impl<Args...>::template check<F>(nullptr)) {};
#endif

struct X {};
int main()
{
#ifndef META_FUNCTION
	// int型とint型で+演算子による加算が可能か
	is_addable(3, 2);

	// int型とX型で+演算子による加算が可能か
	is_addable(3, X());
#else
	// int型とint型で+演算子による加算が可能か
	static_assert(is_addable<int, int>::value, "int + int is valid");

	// int型とX型で+演算子による加算が可能か
	static_assert(!is_addable<int, X>::value, "int + X is invalid");

	static_assert(is_complete_type<A>::value, "A is complete type");
	static_assert(!is_complete_type<B>::value, "B is incomplete type");

	auto f = [](int a, char b, const std::string& c) {
		std::cout << a << ", " << b << ", " << c << std::endl;
	};

	static_assert(is_callable<decltype(f), int, char, const std::string&>::value,
		"f is callable with follow arguments: [int, char, const std::string&]");
	static_assert(!is_callable<decltype(f), int>::value,
		"f is callable with int type one argument");
#endif
	return 0;
}