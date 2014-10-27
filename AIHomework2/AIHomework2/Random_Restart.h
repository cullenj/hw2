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
    int n;
    long q;
    
    Random_Restart() {
        cout << "This is Random Restart Hill Climbing with domain " << problem.domain << endl << endl;
        q = time(NULL);
    }
    
    ~Random_Restart() {
        
    }
    
    long* search() {
        n = 0;
        Hill_Climbing<T> *searchalg;
        long * x = new long[2];
        long * y = new long[2];
        x[0] = -1;
        while(x[0] == -1) {
            q++;
            searchalg = new Hill_Climbing<T>;
            n++;
            cout << "Iteration " << n << endl;
            problem.random(q);
            x = searchalg->Search(problem);
            y[1] += x[1];
        }
        y[0] = n;
        cout << "After " << n << " Iterations of Hill Climbing" << endl << endl;
        
        return y;
    }
    
    
};

#endif
