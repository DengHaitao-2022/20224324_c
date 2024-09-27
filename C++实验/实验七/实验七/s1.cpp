#include <iostream>
#include <string>

std::string encrypt(const std::string& plaintext, const std::string& key) {
	std::string ciphertext;
	for (size_t i = 0; i < plaintext.size(); ++i) {
		char plainChar = plaintext[i];
		int keyDigit = key[i % key.size()] - '0';
		char cipherChar = ((plainChar - 32 + keyDigit) % 89) + 32;
		ciphertext.push_back(cipherChar);
	}
	return ciphertext;
}

int main() {
	std::string key;
	std::string plaintext;
	while (std::getline(std::cin, key) && std::getline(std::cin, plaintext)) {
		std::string ciphertext = encrypt(plaintext, key);
		std::cout << ciphertext << std::endl;
	}
	return 0;
}
