#include <vector>

// 型std::vectorに別名vecを付ける。
// 要素型Tはパラメータ化する
template <class T>
using Vec = std::vector<T>;

int f(int, int) { return 0; }

// int型にIntegerという別名を付ける
using Integer = int;

// int型を2つパラメータとしてとり、int型を返す関数ポインタに、
// FunctionPointerという名前を付ける
using FunctionPointer = int(*)(int, int);

// decltypeと組み合わせることで、
// 特定関数への関数ポインタの型をより簡単に取得できる
using FunctionPointerByDecltype = decltype(&f);

int main()
{
	// 要素型を渡してstd::vector型の別名を使用する
	Vec<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
}