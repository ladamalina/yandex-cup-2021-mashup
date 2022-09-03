#include <cassert>
#include <iostream>
#include <string>

std::string str2bits(const std::string& str) {
  size_t str_len = str.size();
  std::string bits;
  bits.reserve(str_len / 3);
  uint16_t i = 0;
  while (i < str_len) {
    if (str[i] == 'o') {
      bits += '1';
      i += 3;
    } else if (str[i] == 'z') {
      bits += '0';
      i += 4;
    }
  }
  bits.shrink_to_fit();
  return bits;
}

int main() {
//  assert(str2bits("one") == "1");
//  assert(str2bits("oneone") == "11");
//  assert(str2bits("onezero") == "10");
//  assert(str2bits("zerozero") == "00");
//  assert(str2bits("zerozeroonezerozero") == "00100");

  std::string str1, str2;
  std::getline(std::cin, str1);
  std::getline(std::cin, str2);

  auto bits1 = str2bits(str1);
  auto bits2 = str2bits(str2);
  if (bits1.size() == bits2.size()) {
    if (bits1 == bits2) {
      std::cout << '=';
    } else if (bits1 > bits2) {
      std::cout << '>';
    } else {
      std::cout << '<';
    }
  } else if (bits1.size() > bits2.size()) {
    std::cout << '>';
  } else {
    std::cout << '<';
  }
}
