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
    
    Hill_Climbing(){ }

    void search(T problem){
        
        if (problem.h()==0) {
            problem.print();
            return;
        }
    
        T best = problem.successors()[0];
        
        for(int i=0;i<problem.successors().size();i++){
            if (problem.successors()[i].h()<best.h()){
                best = problem.successors()[i];
            }
        }
        
        cout << "Best successor is: " << endl;
        problem.print();
        cout << endl;
        
        search(best);
    }

};

#endif
