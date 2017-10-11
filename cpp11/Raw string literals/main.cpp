#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

// 文字列のフォーマット関数
// not thread-safe, スレッドセーフな実装ではないので注意
// Boost.Formatやcppformatを使用することを推奨
template <class... Args>
std::string format(const char* fmt, Args&&... args)
{
	std::streambuf* backup = std::cout.rdbuf();
	std::stringstream sout;
	std::streambuf* soutbuf = sout.rdbuf();
	std::cout.rdbuf(soutbuf);

	std::fprintf(stdout, fmt, args...);

	std::string result = sout.str();

	std::cout.rdbuf(backup);
	return result;
}

int main()
{
	int user_id = 123;
	std::string name = "Alice";
	std::string json = format(R"({"user_id": %d, "name": "%s"})", user_id, name.c_str());

	std::cout << json << std::endl;

	// バックスラッシュ区切りになっているWindowsのファイルパスを入力
	std::string path = R"(C:\language\cpp\main.cpp)";
	std::cout << path << std::endl;

	return 0;
}