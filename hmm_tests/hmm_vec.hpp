//
//  hmm_fs.hpp
//  hmm_tests
//
//  Created by Adam Willats on 8/16/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//

#ifndef hmm_vec_hpp
#define hmm_vec_hpp

#include <stdio.h>
#include <cassert>
#include <iostream>
#include <cmath>
#include <cfloat>

#include <vector>
#include <algorithm>


//2d vectors http://thispointer.com/creating-a-matrix-using-2d-vector-in-c-vector-of-vectors/

struct HMMv {
    int states, events;
    std::vector< std::vector<double> > A, B;
    std::vector<double> PI;
    
    //https://stackoverflow.com/questions/18795776/error-no-matching-function-for-call-to-when-constructing-an-unintialized-stru
    HMMv(): states(2), events(2) { ;}; 


    HMMv(int states, int events, std::vector< std::vector<double> > A, std::vector< std::vector<double> > B, std::vector<double> PI):
    states(states), events(events), A(A), B(B), PI(PI) {
        assert(states > 0); assert(events > 0);
        assert(!A.empty()); assert(!B.empty()); assert(!PI.empty());
    }

   friend std::vector<int> genStates(HMMv const& hmm);
   friend int* viterbi(HMMv const& hmm, std::vector<int> observed, const int n); 
};




#endif /* hmm_fs_hpp */
