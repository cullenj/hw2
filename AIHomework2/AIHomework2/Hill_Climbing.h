//
//  Hill_Climbing.h
//  AIHomework2
//
//  Created by Joe Cullen on 10/20/14.
//  Copyright (c) 2014 Joseph Cullen. All rights reserved.
//

#ifndef AIHomework2_Hill_Climbing_h
#define AIHomework2_Hill_Climbing_h

#include <iostream>

using namespace std;
template <class T>

class Hill_Climbing{
    
public:
    
    T previous;
    long* x;
    long nodeslookedat;
    
    Hill_Climbing(){
        T temp;
        nodeslookedat = 0;
        x = new long[2];
        cout << "This is Hill Climbing with domain " << temp.domain << endl << endl;
    }

    long* Search(T problem){
        
        nodeslookedat++;
        
        if (problem.h()==0) {
            cout << "Solution Found: " << endl;
            problem.print();
            x[0] = 1;
            x[1] = nodeslookedat;
            return x;
        }
    
        T best = problem.successors()[0];
        
        for(int i=0;i<problem.successors().size();i++){
            if (problem.successors()[i].h()<best.h()){
                best = problem.successors()[i];
            }
        }
        
        if (previous == best) {
            best.print();
            x[0] = -1;
            x[1] = nodeslookedat;
            return x;
        }
        
        cout << "Best successor is: " << endl;
        problem.print();
        cout << endl;
        
        previous = problem;
        
        return Search(best);
    }

};

#endif
