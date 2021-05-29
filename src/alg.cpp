// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
     std::ifstream file(filename);
     BST<std::string> tree;
     std::string word;
     char ch;
     int c =32;
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    
    while(!file.eof()){
        ch=file.get();
        if(((ch >= 'a')&&(ch <= 'z'))||((ch >= 'A')&&(ch <= 'Z'))){
            if((ch >= 'A')&&(ch <= 'Z'))
                    ch +=c;
                word +=ch;
               
        } else if(word != ""){
                 std::cout<<word<<std::endl;
                tree.add(word);
                word.clear();

        }
    }
    
    file.close();
    return tree;
}
