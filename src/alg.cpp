// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"


BST<std::string> makeTree(const char* filename) {
  BST<std::string>tree;
  char c = 'a' - 'A';
  std::string word = "";
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return tree;
  }
  while (!file.eof()) {
    char ch = file.get();
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      if (ch >= 'A' && ch <= 'Z')
        ch += c;
      word += ch;
    } else if (word != "") {
      tree.add(word);
      word.clear();
    }
  }
  file.close();
  return tree;
}
