//
//  dataFuns.hpp
//  xRue
//
//  Created by Adam Willats on 7/19/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//

#ifndef dataFuns_hpp
#define dataFuns_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


//NOTE: this bad programming practice, surely this must go into the cpp??
//but can't get it to compile that way
template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "[";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last)
            out << ", ";
    }
    out << "]";
    return out;
}
#endif /* dataFuns_hpp */
