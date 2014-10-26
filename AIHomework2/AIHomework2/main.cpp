//
//  main.cpp
//  AIHomework2
//
//  Created by Joe Cullen on 10/20/14.
//  Copyright (c) 2014 Joseph Cullen. All rights reserved.
//

#include <iostream>
#include <vector>
#include "EQ.h"
#include "Astar.h"
#include "Astarbeam.h"
#include "WGC.h"
#include "MB.h"
#include "Hill_Climbing.h"

using namespace std;


int main(int argc, const char * argv[])
{
    WGC test;
    //EQ problem;
    MB room;
    /*Astar<MB> MBsearch;
    MBsearch.search(room);*/
    //Astarbeam<MB> BeamMBsearch;
    //BeamMBsearch.setbeamwidth(5);
    //BeamMBsearch.search(room);

    /*
    Astar<WGC> WGCsearch;
    WGCsearch.search(test);
     */
    
    vector<int> board;
    board.push_back(1);
    board.push_back(5);
    board.push_back(0);
    board.push_back(8);
    board.push_back(3);
    board.push_back(7);
    board.push_back(2);
    board.push_back(0);
    
    
    Hill_Climbing<EQ> HCsearch;
    EQ problem(board);
    HCsearch.search(problem);
    
    /*
    Astarbeam<EQ> EQsearch;
    EQsearch.setbeamwidth(3);
    EQsearch.search(problem);
    
    Astar<EQ> otherEQsearch;
    otherEQsearch.search(problem);
    */
    
    return 0;
}

