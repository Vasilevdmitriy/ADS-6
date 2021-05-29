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
     int ban;
     int c =32;
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    
    while(!file.eof()){
        file >> temp1;
            i = 0;
           while(i < temp1.size()){
               ban = 0;
               while((temp1[i] >= 'a') && (temp1[i] <= 'z') || (temp1[i] >= 'A') && (temp1[i] <= 'Z')) {
                  if ((temp1[i] >= 'A') && (temp1[i] <= 'Z'))
                    temp1[i] += c;
                    word +=temp1[i];
                ban=1;
                i++;
              }
              
              if(ban != 0){
                  tree.add(word);
                    word.clear();
              }
              i++;
           }
           
    }
    
    file.close();
    return tree;
}
