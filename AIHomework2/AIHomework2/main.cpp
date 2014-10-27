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
    wgc.seth(false);
    AstarWGC.search(wgc);
    wgc.seth(true);
    AstarWGC.reset();
    AstarWGC.search(wgc);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    
    time(&begin);
    eq.seth(false);
    AstarEQ.search(eq);
    eq.seth(true);
    AstarEQ.reset();
    AstarEQ.search(eq);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    
    time(&begin);
    mb.seth(false);
    AstarMB.search(mb);
    mb.seth(true);
    AstarMB.reset();
    AstarMB.search(mb);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    
    //A* beam search
    Astarbeam<WGC> AstarbeamWGC;
    Astarbeam<EQ> AstarbeamEQ;
    Astarbeam<MB> AstarbeamMB;
    AstarbeamWGC.setbeamwidth(3);
    AstarbeamEQ.setbeamwidth(4);
    AstarbeamMB.setbeamwidth(4);
    
    time(&begin);
    wgc.seth(false);
    AstarbeamWGC.search(wgc);
    wgc.seth(true);
    AstarbeamWGC.reset();
    AstarbeamWGC.search(wgc);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    time(&begin);
    eq.seth(false);
    AstarbeamEQ.search(eq);
    eq.seth(true);
    AstarbeamEQ.reset();
    AstarbeamEQ.search(eq);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    time(&begin);
    mb.seth(false);
    AstarbeamMB.search(mb);
    mb.seth(true);
    AstarbeamMB.reset();
    AstarbeamMB.search(mb);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    
    
    //Random Restart Hill Climbing
    Random_Restart<EQ> HCsearch;
    int n=50;
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
    cout << "The average number of calls to Hill Climbing is " << mean << endl;
    cout << "And the standard deviation is " << stddev << endl;
    cout << "And average number of expansions for both successful and unsuccessful Hill Climbing searches  " << avexpansions << endl;
   
    
    return 0;
}

