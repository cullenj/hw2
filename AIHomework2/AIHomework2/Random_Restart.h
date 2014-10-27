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
#include <time.h>

using namespace std;
template <class T>

class Random_Restart {
    
private:
    
public:
    T problem;
    long q;
    long* y;
    long* x;
    
    Random_Restart() {
        cout << "This is Random Restart Hill Climbing with domain " << problem.domain << endl << endl;
        q = time(NULL);
    }
    
    ~Random_Restart() {
        
    }
    
    long* search() {
        Hill_Climbing<T> searchalg;
        x = new long[2];
        y = new long[2];
        x[0] = -1;
        y[0] = 0;
        y[1] = 0;
        while(x[0] == -1) {
            searchalg.resetcount();
            q++;
            y[0] = y[0] + 1;
            cout << "Iteration " << y[0] << endl;
            problem.random(q);
            x = searchalg.Search(problem);
            y[1] += x[1];
        }
        cout << "After " << y[0] << " Iterations of Hill Climbing" << endl << endl;
        
        cout << "Total number of expansions " << y[1] << endl << endl;
        
        return y;
    }
    
    
};

#endif
