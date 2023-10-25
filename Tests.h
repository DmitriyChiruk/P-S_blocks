#pragma once

#include <iostream>

#include "CryptoMethods.h"

// Check s-block encryption for 8bit symbol
void TestSBlockEncr(std::vector<std::vector<uint8_t>>& STable);


// Check s-block decryption with searching by s-box for 8bit symbol
void TestSBlockDecr1(std::vector<std::vector<uint8_t>>& STable);

// Check s-block decryption with inverted s-box for 8bit symbol
void TestSBlockDecr2(std::vector<std::vector<uint8_t>>& InvSTable);


// Check s-block encryption for string
void TestSBlockEncrSeq(std::vector<std::vector<uint8_t>>& STable);

// Check s-block decryption with searching by s-box for string
void TestSBlockDecrSeq1(std::vector<std::vector<uint8_t>>& STable);

// Check s-block decryption with inverted s-box for string
void TestSBlockDecrSeq2(std::vector<std::vector<uint8_t>>& STable, std::vector<std::vector<uint8_t>>& InvSTable);



// Check p-block encryption for 8bit symbol
void TestPBlockEncr(std::vector<uint8_t>& PVector);

// Check p-block decryption for 8bit symbol
void TestPBlockDecr(std::vector<uint8_t>& PVector);

// Check p-block encryption for string
void TestPBlockEncrSeq(std::vector<uint8_t>& PVector);

// Check p-block decryption for string
void TestPBlockDecrSeq(std::vector<uint8_t>& PVector);