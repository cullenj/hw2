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
#include "WGC.h"

using namespace std;


int main(int argc, const char * argv[])
{
    WGC test;
    EQ problem;
    Astar<EQ> Asearch;
    Asearch.search(problem);
    return 0;
}

