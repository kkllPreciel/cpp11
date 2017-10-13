#include <cassert>
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

int main()
{
	std::u16string s16 = u"�g���";
	std::u32string s32 = U"�g���";

	// WARNING:visual studio2015���Ɖ��̂�size��3�ɂȂ�
	//assert(s16.size() == 4); // �T���Q�[�g�y�A���܂ނ̂�1����������
	assert(s32.size() == 3); // UTF-32�ɃT���Q�[�g�y�A�͂Ȃ�

	// WARNING:�����艺 visual studio�̃o�O�ɂ�萳�퓮�삵�Ȃ�
	// UTF-8��UTF-32�̑��ݕϊ����s���R���o�[�^�[
	// std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;

	// UTF-8����UTF-32�ɕϊ�
	// std::string u8str = u8"����������";
	// std::u32string u32str = converter.from_bytes(u8str);

	// �R�[�h�|�C���g�����擾
	// std::size_t codepoint_count = u32str.size();
	// std::cout << codepoint_count << std::endl;

	return 0;
}