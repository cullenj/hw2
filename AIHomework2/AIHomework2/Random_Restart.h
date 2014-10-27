//
//  Random_Restart.h
//  AIHomework2
//
//  Created by David Kozloff on 10/26/14.
//  Copyright (c) 2014 Joseph Cullen. All rights reserved.
//

#ifndef AIHomework2_Random_Restart_h
#define AIHomework2_Random_Restart_h

#include "Hill_Climbing.h"

using namespace std;
template <class T>

class Random_Restart {
    
private:
    
public:
    T problem;
    int n;
    
    Random_Restart() {
    }
    
    ~Random_Restart() {
        
    }
    
    int search() {
        n = 0;
        bool over = false;
        Hill_Climbing<T> searchalg;
        while(!over) {
            n++;
            problem.random();
            over = searchalg.Search(problem);
        }
        cout << "After " << n << " Iterations" << endl;
        return n;
    }
    
    
};

#endif
