//
//  MB.h
//  AIHomework2
//
//  Created by Joe Cullen on 10/20/14.
//  Copyright (c) 2014 Joseph Cullen. All rights reserved.
//

#ifndef AIHomework2_MB_h
#define AIHomework2_MB_h

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class MB {

public:
    struct animal
    {
        bool hold_bananas;
        bool hold_chair;
        bool hold_stick;
        bool on_chair;
        unsigned location;
    };
    
    struct fruit
    {
        bool hanging;
        unsigned location;
    };
    
    unsigned chair;
    unsigned stick;

    animal monkey = *new animal();
    fruit bananas = *new fruit();
    
    string domain="MB ";
    
    MB()
    {
        monkey.hold_bananas=false;
        monkey.hold_chair=false;
        monkey.hold_stick=false;
        monkey.on_chair=false;
        monkey.location=1;
        bananas.hanging=true;
        bananas.location=4;
        chair = 2;
        stick = 3;
    }
    
    MB(unsigned m_loc,unsigned b_loc,unsigned c_loc,unsigned s_loc,
       bool hb, bool hc, bool hs, bool on, bool hang)
    {
        monkey.hold_bananas=hb;
        monkey.hold_chair=hc;
        monkey.hold_stick=hs;
        monkey.on_chair=on;
        monkey.location=m_loc;
        bananas.hanging=hang;
        bananas.location=b_loc;
        chair = c_loc;
        stick = s_loc;
    }
  
    bool operator==(const MB& other) {
        if(other.monkey.hold_bananas==monkey.hold_bananas &&
           other.monkey.hold_chair==monkey.hold_chair &&
           other.monkey.hold_stick==monkey.hold_stick &&
           other.monkey.on_chair==monkey.on_chair &&
           other.bananas.hanging==bananas.hanging &&
           other.bananas.location==bananas.location &&
           other.chair==chair &&
           other.stick==stick)
        {return true;} else {return false;}
            
    }
    
    bool operator!=(const MB& other) {
        return !(operator==(other));
    }
    
    bool goal(){
        return monkey.hold_bananas;
    }
    
    vector<MB> successors() {
        vector<MB> successors;
    //generate monkey moves
        for (unsigned i=0;i<4; i++){
            MB room(i,bananas.location,chair,stick,monkey.hold_bananas,
                monkey.hold_chair,monkey.hold_stick,monkey.on_chair,bananas.hanging);
            successors.push_back(room);
        }
    //generate monkey grabs
        if (monkey.location==stick && !monkey.hold_stick){
            MB room(monkey.location,bananas.location,chair,stick,monkey.hold_bananas,
                    monkey.hold_chair,true,monkey.on_chair,bananas.hanging);
            successors.push_back(room);
        }
     
        if (monkey.location==chair && !monkey.hold_chair){
            MB room(monkey.location,bananas.location,chair,stick,monkey.hold_bananas,
                    true,monkey.hold_stick,monkey.on_chair,bananas.hanging);
            successors.push_back(room);
        }

        if (monkey.location==bananas.location && monkey.on_chair && monkey.hold_stick){
            MB room(monkey.location,bananas.location,chair,stick,true,
                    monkey.hold_chair,monkey.hold_chair,monkey.on_chair,bananas.hanging);
            successors.push_back(room);
        }
    //generate monkey drops

        if (monkey.location==stick && monkey.hold_stick){
            MB room(monkey.location,bananas.location,chair,monkey.location,monkey.hold_bananas,
                    monkey.hold_chair,false,monkey.on_chair,bananas.hanging);
            successors.push_back(room);
        }
        
        if (monkey.location==chair && monkey.hold_chair){
            MB room(monkey.location,bananas.location,monkey.location,stick,monkey.hold_bananas,
                    false,monkey.hold_stick,monkey.on_chair,bananas.hanging);
            successors.push_back(room);
        }
        
    //generate monkey on chair
        if (monkey.location==chair && !monkey.hold_chair){
            MB room(monkey.location,bananas.location,chair,stick,monkey.hold_bananas,
                    monkey.hold_chair,monkey.hold_stick,true,bananas.hanging);
            successors.push_back(room);
        }
        
        return successors;
    }
    
    void print(){
        cout << "no print yet" << endl;
        
    }
    
    void solution(list<MB> path) {
        cout << endl << "Length of Soln. Path: " << path.size() +1 << endl;
        (--path.end())->print();
    }
    
    int cost() {
        return 1;
    }
    
    int h() {
        return 1;
    }
    
    // not finished!
    long hashkey() {
        long hash = 0;
        for(int i = 0; i < 4; i++ ) {
            hash = monkey.location*pow(10,i);
        }
        return hash;
    }
    
};


#endif
