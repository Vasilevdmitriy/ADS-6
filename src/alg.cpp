// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
     BST<std::string>Tree;
  char difFromAToa = 'a' - 'A';
  std::string word = "";
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return Tree;
  }
  while (!file.eof()) {
    char ch = file.get();
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      if (ch >= 'A' && ch <= 'Z')
        ch += difFromAToa;
      word += ch;
    } else if (word != "") {
      Tree.add(word);
      word = "";
    }
  }
  file.close();
  return Tree;
}
