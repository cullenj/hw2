//
//  main.cpp
//  AIHomework2
//
//  Created by Joe Cullen on 10/20/14.
//  Copyright (c) 2014 Joseph Cullen. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "EQ.h"
#include "Astar.h"
#include "Astarbeam.h"
#include "WGC.h"
#include "MB.h"
#include "Random_Restart.h"

using namespace std;


int main(int argc, const char * argv[])
{
    time_t begin;
    time_t end;
    /*
    //Domains
    WGC wgc;  //Wolf Goat Cabbage
    EQ eq;//Eight Queens
    MB mb;   //Monkey & Bananas
   
    //A*
    Astar<WGC> AstarWGC;
    Astar<EQ> AstarEQ;
    Astar<MB> AstarMB;
    
    time(&begin);
    AstarWGC.search(wgc);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    time(&begin);
    AstarEQ.search(eq);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    time(&begin);
    AstarMB.search(mb);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    
    //A* beam search
    Astarbeam<WGC> AstarbeamWGC;
    Astarbeam<EQ> AstarbeamEQ;
    Astarbeam<MB> AstarbeamMB;
    
    time(&begin);
    AstarbeamWGC.search(wgc);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    time(&begin);
    AstarbeamEQ.search(eq);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    time(&begin);
    AstarbeamMB.search(mb);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    */
    
    //Random Restart Hill Climbing
    Random_Restart<EQ> HCsearch;
    int n=80;
    int avexpansions = 0;
    long* x = new long[n];
    long* y = new long[2];
    for (int i = 0; i < n; i++) {
        y = HCsearch.search();
        avexpansions += y[1];
        x[i] = y[0];
    }
    long mean=0;
    double stddev=0;
    for (int j = 0; j < n; j++) {
        mean = mean + x[j];
    }
    avexpansions = avexpansions / mean;
    mean = mean/n;
    for (int j = 0; j < n; j++) {
        stddev = stddev + pow(x[j] - mean,2);
    }
    stddev = sqrt(stddev/n);
    cout << "The average number of iterations is " << mean << endl;
    cout << "And the standard deviation is " << stddev << endl;
    cout << "And average number of expansions for both bad and good searches  " << avexpansions << endl;
   
    
    return 0;
}

