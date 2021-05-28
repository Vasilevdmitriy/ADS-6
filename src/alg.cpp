// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
     std::ifstream file(filename);
     BST<std::string> tree;
     std::string temp1,word;
     int i;
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    
    while(!file.eof()){
        file >> temp1;
            if ((temp1[i] >= 'A' && temp1[i] <= 'Z') || (temp1[i] >= 'a' && temp1[i] <= 'z')) {
                if (temp1[i] >= 'A' && temp1[i] <= 'Z') {
                    temp1[i] += 32;
                }
                word += temp1[i];
            } 
            if(word != "" ) tree.add(word);

    }
    
    return tree;
    file.close();

}
