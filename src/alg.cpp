// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
         std::ifstream file(filename);
     BST<std::string> tree;
     std::string temp1;
     std::string word = "";
     int i;
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    
    while(!file.eof()){
        file >> temp1;
            i = 0;
            while(i < temp1.size()){
                    if (temp1[i] >= 'A' && temp1[i] <= 'Z') {
                        temp1[i] += 32;
                    }
                word += temp1[i];

                if(i == temp1.size()-1){
                    tree.add(word);
                    word = "";
                }
                i++;
            }
    }
    
    file.close();
    return tree;
}
