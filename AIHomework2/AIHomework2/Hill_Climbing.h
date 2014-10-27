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
    
    T problem;
    T previous;
    
    Hill_Climbing(){ }

    bool Search(T problem){
        if (problem.h()==0) {
            cout << "Solution Found: " << endl;
            problem.print();
            return true;
        }
    
        T best = problem.successors()[0];
        
        for(int i=0;i<problem.successors().size();i++){
            if (problem.successors()[i].h()<best.h()){
                best = problem.successors()[i];
            }
        }
        
        if (previous == best) {
            return false;
        }
        
        cout << "Best successor is: " << endl;
        problem.print();
        cout << endl;
        
        previous = problem;
        
        return Search(best);
    }

};

#endif
