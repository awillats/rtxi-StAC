//
//  main.cpp
//  xRue
//
//  Created by Adam Willats on 7/19/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//

#include <iostream>
#include <vector>
#include "hmmFuns.hpp"
#include "dataFuns.hpp"

using namespace std;

//#include <stdio.h>
//using namespace std;



int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    vector<double> vFr = {.01,0.90};
    vector<double> vTr = {0.01,0.01};

    
    vector<int> q = genHMM(vFr,vTr,2e3);

    cout << q;    //returns a vector of ints
    
    return 0;
}


