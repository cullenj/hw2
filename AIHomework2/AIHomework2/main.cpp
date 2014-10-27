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
    
    //Random Restart Hill Climbing
    Random_Restart<EQ> HCsearch;
    int n=50;
    int[] x = new int[n];
    for (int i = 0; i < n; i++) {
    x[i] = HCsearch.search();
    }
    int mean=0;
    double stddev=0;
    for (int j = 0; j < n; j++) {
        mean = mean + x[j];
    }
    mean = mean/n;
    for (int j = 0; j < n; j++) {
        stddev = stddev + pow(2, x[j] - mean);
    }
    stddev = sqrt(stddev/n);
    cout << "The average number of iterations is " << mean << endl;
    cout << "And the standard deviation is " << stddev << endl;
   
    
    return 0;
}

