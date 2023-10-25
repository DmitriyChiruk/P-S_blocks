#include "Tests.h"

void TestSBlockEncr(std::vector<std::vector<uint8_t>>& STable)
{
	// Check s-block encryption for 8bit symbol
	uint8_t val = 0x4a;
	uint8_t exp_val_encr = 0xd6;
	uint8_t val_encr = SBlockEncrypt(val, STable);

	std::cout << "Check s-block encryption for 8bit symbol" << std::endl;

	std::cout << "Value: " << std::hex << (int)val << std::endl;
	std::cout << "Encrypted: " << std::hex << (int)val_encr;
	std::cout << "\tMust be: " << std::hex << (int)exp_val_encr << std::endl;
	std::cout << (val_encr == exp_val_encr ? "Passed!" : "Failed") << std::endl;
}

void TestSBlockDecr1(std::vector<std::vector<uint8_t>>& STable)
{
	// Check s-block decryption with searching by s-box for 8bit symbol
	uint8_t val = 0x4a;
	uint8_t val_encr = 0xd6;
	uint8_t val_decr = SBlockDecrypt(val_encr, STable);

	std::cout << "Check s-block decryption with searching by s-box for 8bit symbol" << std::endl;

	std::cout << "Encrypted: " << std::hex << (int)val_encr << std::endl;
	std::cout << "Decrypted: " << std::hex << (int)val_decr;
	std::cout << "\tMust be: " << std::hex << (int)val << std::endl;
	std::cout << (val_decr == val ? "Passed!" : "Failed") << std::endl;
}

void TestSBlockDecr2(std::vector<std::vector<uint8_t>>& InvSTable)
{
	// Check s-block decryption with inverted s-box for 8bit symbol
	uint8_t val = 0x4a;
	uint8_t val_encr = 0xd6;
	uint8_t val_decr = SBlockEncrypt(val_encr, InvSTable);

	std::cout << "Check s-block decryption with inverted s-box for 8bit symbol" << std::endl;

	std::cout << "Encrypted: " << std::hex << (int)val_encr << std::endl;
	std::cout << "Decrypted: " << std::hex << (int)val_decr;
	std::cout << "\tMust be: " << std::hex << (int)val << std::endl;
	std::cout << (val_decr == val? "Passed!" : "Failed") << std::endl;
}

void TestSBlockEncrSeq(std::vector<std::vector<uint8_t>>& STable)
{
	// Check s-block encryption for string
	std::string str = "HEHE";
	std::string exp_str_encr = "RnRn";
	std::string str_encr = SBlockEncryptSeq(str, STable);

	std::cout << "Check s-block encryption for string" << std::endl;

	std::cout << "String: " << str << std::endl;
	std::cout << "Encrypted: " << str_encr << std::endl;
	std::cout << "Must be : " << exp_str_encr << std::endl;
	std::cout << (str_encr == exp_str_encr ? "Passed!" : "Failed") << std::endl;
}

void TestSBlockDecrSeq1(std::vector<std::vector<uint8_t>>& STable)
{
	// Check s-block decryption with searching by s-box for string
	std::string str = "Hello World!";
	std::string exp_str_encr = SBlockEncryptSeq(str, STable);
	std::string str_decr = SBlockDecryptSeq(exp_str_encr, STable);

	std::cout << "Check s-block decryption with searching by s-box for string" << std::endl;

	std::cout << "Encrypted: " << exp_str_encr << std::endl;
	std::cout << "Decrypted: " << str_decr << std::endl;
	std::cout << "Must be : " << str << std::endl;
	std::cout << (str_decr == str? "Passed!" : "Failed") << std::endl;
}

void TestSBlockDecrSeq2(std::vector<std::vector<uint8_t>>& STable, std::vector<std::vector<uint8_t>>& InvSTable)
{
	// Check s-block decryption with inverted s-box for string
	std::string str = "Hello World!";
	std::string exp_str_encr = SBlockEncryptSeq(str, STable);
	std::string str_decr = SBlockEncryptSeq(exp_str_encr, InvSTable);

	std::cout << "Check s-block decryption with inverted s-box for string" << std::endl;

	std::cout << "Encrypted: " << exp_str_encr << std::endl;
	std::cout << "Decrypted: " << str_decr << std::endl;
	std::cout << "Must be : " << str << std::endl;
	std::cout << (str_decr == str? "Passed!" : "Failed") << std::endl;
}

void TestPBlockEncr(std::vector<uint8_t>& PVector)
{
	// Check p-block encryption for 8bit symbol
	uint8_t val = 0xaa;
	uint8_t exp_val_encr = 0x39;
	uint8_t val_encr = PBlockEncrypt(val, PVector);

	std::cout << "Check p-block encryption for 8bit symbol" << std::endl;

	std::cout << "Value: " << std::hex << (int)val << std::endl;
	std::cout << "Encrypted: " << std::hex << (int)val_encr;
	std::cout << "\tMust be: " << std::hex << (int)exp_val_encr << std::endl;
	std::cout << (val_encr == exp_val_encr ? "Passed!" : "Failed") << std::endl;
}

void TestPBlockDecr(std::vector<uint8_t>& PVector)
{
	// Check p-block decryption for 8bit symbol
	uint8_t val = 0xaa;
	uint8_t val_encr = 0x39;
	uint8_t val_decr = PBlockDecrypt(val_encr, PVector);

	std::cout << "Check p-block decryption for 8bit symbol" << std::endl;

	std::cout << "Encrypted: " << std::hex << (int)val_encr << std::endl;
	std::cout << "Decrypted: " << std::hex << (int)val_decr;
	std::cout << "\tMust be: " << std::hex << (int)val << std::endl;
	std::cout << (val_decr == val ? "Passed!" : "Failed") << std::endl;
}

void TestPBlockEncrSeq(std::vector<uint8_t>& PVector)
{
	// Check p-block encryption for string
	std::string str = "HEHE";
	std::string exp_str_encr = "PFPF";
	std::string str_encr = PBlockEncryptSeq(str, PVector);

	std::cout << "Check p-block encryption for string" << std::endl;

	std::cout << "String: " << str << std::endl;
	std::cout << "Encrypted: " << str_encr << std::endl;
	std::cout << "Must be : " << exp_str_encr << std::endl;
	std::cout << (str_encr == exp_str_encr ? "Passed!" : "Failed") << std::endl;
}

void TestPBlockDecrSeq(std::vector<uint8_t>& PVector)
{
	// Check p-block decryption for string
	std::string str = "Hello World!";
	std::string exp_str_encr = PBlockEncryptSeq(str, PVector);
	std::string str_decr = PBlockDecryptSeq(exp_str_encr, PVector);

	std::cout << "Check p-block decryption for string" << std::endl;

	std::cout << "Encrypted: " << exp_str_encr << std::endl;
	std::cout << "Decrypted: " << str_decr << std::endl;
	std::cout << "Must be : " << str << std::endl;
	std::cout << (str_decr == str ? "Passed!" : "Failed") << std::endl;
}
