/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Josh
 *
 * Created on January 16, 2018, 5:06 PM
 */

#include <iostream>
#include "ArrayList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ArrayList<int> list; 
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(5);
    list.add(6);
    list.add(3,4);
    
    for(int i = 0; i < list.size(); i++){
        cout << list.get(i) << ",";
    }
    cout << endl;
    
    list.remove(4);
    
    for(int i = 0; i < list.size(); i++){
        cout << list.get(i) << ",";
    }
    cout << endl;
    
    list.add(4,5);
    
    
    for(int i = 0; i < list.size(); i++){
        cout << list.get(i) << ",";
    }
        
    
    return 0;
}

