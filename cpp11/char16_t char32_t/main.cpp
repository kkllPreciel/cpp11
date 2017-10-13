#include <cassert>
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

int main()
{
	std::u16string s16 = u"吉野家";
	std::u32string s32 = U"吉野家";

	// WARNING:visual studio2015だと何故かsizeが3になる
	//assert(s16.size() == 4); // サロゲートペアを含むので1文字分多い
	assert(s32.size() == 3); // UTF-32にサロゲートペアはない

	// WARNING:これより下 visual studioのバグにより正常動作しない
	// UTF-8とUTF-32の相互変換を行うコンバーター
	// std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;

	// UTF-8からUTF-32に変換
	// std::string u8str = u8"あいうえお";
	// std::u32string u32str = converter.from_bytes(u8str);

	// コードポイント数を取得
	// std::size_t codepoint_count = u32str.size();
	// std::cout << codepoint_count << std::endl;

	return 0;
}