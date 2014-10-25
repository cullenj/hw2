//
//  main.cpp
//  AIHomework2
//
//  Created by Joe Cullen on 10/20/14.
//  Copyright (c) 2014 Joseph Cullen. All rights reserved.
//

#include <iostream>
#include "EQ.h"
#include "Astar.h"
#include "Astarbeam.h"
#include "WGC.h"
#include "MB.h"

using namespace std;


int main(int argc, const char * argv[])
{
    WGC test;
    EQ problem;
    MB room;
    Astar<MB> MBsearch;
    MBsearch.search(room);
    Astarbeam<MB> BeamMBsearch;
    BeamMBsearch.setbeamwidth(5);
    BeamMBsearch.search(room);
    
    /*
    Astarbeam<EQ> EQsearch;
    EQsearch.setbeamwidth(3);
    EQsearch.search(problem);
    Astar<EQ> otherEQsearch;
    otherEQsearch.search(problem);
    */
    
    return 0;
}

