//
//  main_decode.cpp
//  hmm_tests
//
//  Created by Adam Willats on 8/16/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include "hmm_fs.cpp"
#include "hmm_fs.hpp"

#include "hmmFuns.hpp"
#include "dataFuns.hpp"


//#include "hmmFuns.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    
    vector<double> vFr = {0.1, 0.6};
    vector<double> vTr = {0.1, 0.1};
    
    int numElements = 350;
    vector<int> q = genHMM(vFr,vTr,numElements);
    cout <<q;
//int* observed = &q[0];
    int* observed = q.data();

    
    
    double A0[2] = {1-vTr[0], vTr[0]};
    double A1[2] = {vTr[1], 1-vTr[1]};
    double *A[2] = {A0, A1};
    
    double B0[2] = {1-vFr[0], vFr[0]};
    double B1[2] = {1-vFr[1], vFr[1]};
    double *B[2] = {B0, B1};

    //ideally this would be the transition probabilities...?
    double PI[2] = {.5,.5};
    
    for (int i = 1; i >= 0; i--)
        cout << PI[i];
    /*
    double B0[2] = {0.9, 0.1};
    double B1[2] = {0.2, 0.8};
    double *B[2]= {B0, B1};
    double PI[2] = {0.2, 0.8};
    int observed[] = {0, 0, 1,1, 0, 0,1,1,1,0,0,1,1};
    */
    
    HMM hmm(2, 2, A, B, PI);
    
    //int numElements =sizeof(observed)/sizeof(*observed);
    cout<<"--"<<numElements<<"--";
    int *guessed = viterbi(hmm, observed, numElements);
    
    
    for (int i = numElements - 1; i >= 0; i--)
        cout << observed[i] << " ";
    cout << endl;

    for (int i = numElements - 1; i >= 0; i--)
        cout << guessed[i] << " ";
    /*
    cout << endl;
    
    HMMLog hmmlog(2, 2, A, B, PI);
    delete[] viterbi(hmmlog, observed, 5);
    */
    return 0;
    
}
