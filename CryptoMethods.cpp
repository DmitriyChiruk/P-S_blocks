#include <iostream>
#include <bitset>

#include "CryptoMethods.h"

//std::vector<std::vector<uint8_t>> InitSBox()
//{
//	std::vector<std::vector<uint8_t>> SBox(15, std::vector<uint8_t>(15, 0));
//
//	for (auto row : SBox)
//	{
//		for (auto el : row)
//		{
//
//		}
//	}
//	return SBox;
//}

std::vector<std::vector<uint8_t>> InvertSBox(const std::vector<std::vector<uint8_t>>& SBox)
{
	std::vector<std::vector<uint8_t>> InvSBox(SBox.size(), std::vector<uint8_t>(SBox[0].size(), 0));

	for (size_t i = 0; i < SBox.size(); i++)
	{
		for (size_t j = 0; j < SBox[0].size(); j++)
		{
			uint8_t left, right;

			left = SBox[i][j] / 16;
			right = SBox[i][j] - (left * 16);

			InvSBox[left][right] = i * 16 + j;
		}
	}

	return InvSBox;
}


void PrintSBox(const std::vector<std::vector<uint8_t>>& SBox)
{
	for (auto row : SBox)
	{
		for (auto el : row)
		{
			if (el < 16)
			{
				std::cout << "0" << std::hex << (int)el << "  ";
			}
			else
			{
				std::cout << std::hex << (int)el << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void PrintPBox(const std::vector<uint8_t>& PBox)
{
	for (auto el : PBox)
	{
		
		std::cout << (int)el << "  ";
	}
	std::cout << std::endl;
}

uint8_t SBlockEncrypt(const uint8_t input, std::vector<std::vector<uint8_t>> &SBlockTable)
{
	uint8_t left, right;
	
	left = input / 16;
	right = input - (left * 16);

	// std::cout << "left: " << std::hex << (int)left << std::endl;
	// std::cout << "right: " << std::hex << (int)right << std::endl;

	return SBlockTable[left][right];
}

uint8_t SBlockDecrypt(const uint8_t input, std::vector<std::vector<uint8_t>>& SBlockTable)
{
	for (uint8_t i = 0; i < SBlockTable.size(); i++)
	{
		for (uint8_t j = 0; j < SBlockTable.size(); j++)
		{
			if (SBlockTable[i][j] == input)
			{
				return i*16 + j;
			}
		}
	}

	return NULL;
}

std::string SBlockDecryptSeq(std::string &Seq, std::vector<std::vector<uint8_t>>& SBlockTable)
{
	std::string Res = "";

	int i = 0;
	while (Seq[i] != '\0')
	{
		Res += SBlockDecrypt(Seq[i], SBlockTable);
		++i;
	}

	return Res;
}

std::string SBlockEncryptSeq(std::string &Seq, std::vector<std::vector<uint8_t>>& SBlockTable)
{
	std::string Res = "";

	int i = 0;
	while (Seq[i] != '\0')
	{
		Res += SBlockEncrypt(Seq[i], SBlockTable);
		++i;
	}

	return Res;
}

uint8_t PBlockEncrypt(const uint8_t input, std::vector<uint8_t>& PBlockVector)
{
	const std::bitset<8> bit_input(input);
	std::bitset<8> res;

	for (uint8_t i = 0; i < 8; i++)
	{
		res[8 - PBlockVector[7 - i]] = bit_input[i];
	}

	/*
	uint8_t bit_seq[8];
	uint8_t significant_bit = uint8_t(1)<<7;
	uint8_t res = 0;

	for (uint8_t i = 0; i < 8; i++)
	{
		bit_seq[i] = uint8_t (input & significant_bit);
		significant_bit >>= 1;

		if (i + 1 > PBlockVector[i])
		{
			bit_seq[i] <<= (i + 1) - PBlockVector[i];
		}
		else
		{
			bit_seq[i] >>= PBlockVector[i] - (i + 1);
		}

		res += bit_seq[i];
	}
	*/

	return uint8_t(res.to_ulong());
}

uint8_t PBlockDecrypt(const uint8_t input, std::vector<uint8_t>& PBlockVector)
{
	const std::bitset<8> bit_input(input);
	std::bitset<8> res;

	for (uint8_t i = 0; i < 8; i++)
	{
		res[i] = bit_input[8 - PBlockVector[7 - i]];
	}

	return uint8_t(res.to_ulong());
}

std::string PBlockEncryptSeq(std::string& Seq, std::vector<uint8_t>& PBlockVector)
{
	std::string Res = "";

	int i = 0;
	while (Seq[i] != '\0')
	{
		Res += PBlockEncrypt(Seq[i], PBlockVector);
		++i;
	}

	return Res;
}

std::string PBlockDecryptSeq(std::string& Seq, std::vector<uint8_t>& PBlockVector)
{
	std::string Res = "";

	int i = 0;
	while (Seq[i] != '\0')
	{
		Res += PBlockDecrypt(Seq[i], PBlockVector);
		++i;
	}

	return Res;
}
