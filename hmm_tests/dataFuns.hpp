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
//using namespace std;


//NOTE: this bad programming practice, surely this must go into the cpp??
//but can't get it to compile that way
template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
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

//std::vector<double> pullParamLine(std::ifstream&);

#endif /* dataFuns_hpp */
