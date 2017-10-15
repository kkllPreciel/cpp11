#include <iostream>
#include <string>

int main()
{
	std::string s = u8"あいうえお";
	
	// バイト数を取得
	// UTF-8のため、ひとつのコードポイント(≒文字)のバイト数は固定ではない
	std::size_t byte_size = s.size();

	std::cout << byte_size << std::endl;

	return 0;
}