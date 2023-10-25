#pragma once

#include <vector>
#include <string>

std::vector<std::vector<uint8_t>> InvertSBox(const std::vector<std::vector<uint8_t>>& SBox);
void PrintSBox(const std::vector<std::vector<uint8_t>>& SBox);
void PrintPBox(const std::vector<uint8_t>& PBox);

uint8_t SBlockEncrypt(const uint8_t input, std::vector<std::vector<uint8_t>>& SBlockTable);
uint8_t SBlockDecrypt(const uint8_t input, std::vector<std::vector<uint8_t>>& SBlockTable);
std::string SBlockEncryptSeq(std::string &Seq, std::vector<std::vector<uint8_t>>& SBlockTable);
std::string SBlockDecryptSeq(std::string &Seq, std::vector<std::vector<uint8_t>>& SBlockTable);

uint8_t PBlockEncrypt(const uint8_t input, std::vector<uint8_t>& PBlockVector);
uint8_t PBlockDecrypt(const uint8_t input, std::vector<uint8_t>& PBlockVector);
std::string PBlockEncryptSeq(std::string& Seq, std::vector<uint8_t>& PBlockVector);
std::string PBlockDecryptSeq(std::string& Seq, std::vector<uint8_t>& PBlockVector);
