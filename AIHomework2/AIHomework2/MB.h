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
    
    string domain = "Monkey & Bananas ";
    unsigned chair;
    unsigned stick;
    bool whichh = false;

    animal monkey = *new animal();
    fruit bananas = *new fruit();
    string action;
    
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
        action="Start:";
    }
    
    MB(unsigned m_loc,unsigned b_loc,unsigned c_loc,unsigned s_loc,
       bool hb, bool hc, bool hs, bool on, bool hang, string act, bool h)
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
        action=act;
        whichh = h;
    }
    
    void seth(bool b) {
        whichh = b;
    }
  
    bool operator==(const MB& other) {
        if(other.monkey.location==monkey.location &&
           other.monkey.hold_bananas==monkey.hold_bananas &&
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
        for (unsigned i=1;i<=4; i++){
            if(!monkey.on_chair) {
                if (monkey.hold_stick){
                    
                    MB room(i,bananas.location,chair,i,monkey.hold_bananas,
                            monkey.hold_chair,monkey.hold_stick,monkey.on_chair,bananas.hanging,"move to "+to_string(i)+":",whichh);
                    successors.push_back(room);
                } else if (monkey.hold_chair){
                    MB room(i,bananas.location,i,stick,monkey.hold_bananas,
                            monkey.hold_chair,monkey.hold_stick,monkey.on_chair,bananas.hanging,"move to "+to_string(i)+":",whichh);
                    successors.push_back(room);
                } else{
                    MB room(i,bananas.location,chair,stick,monkey.hold_bananas,
                            monkey.hold_chair,monkey.hold_stick,monkey.on_chair,bananas.hanging,"move to "+to_string(i)+":",whichh);
                    successors.push_back(room);
                }
            }
        }
    //generate monkey grabs
        if (monkey.location==stick && !monkey.hold_stick && !monkey.hold_chair && !monkey.hold_bananas){
            MB room(monkey.location,bananas.location,chair,stick,monkey.hold_bananas,
                    monkey.hold_chair,true,monkey.on_chair,bananas.hanging,"grab stick:",whichh);
            successors.push_back(room);
        }
     
        if (monkey.location==chair && !monkey.hold_chair && !monkey.on_chair && !monkey.hold_stick && !monkey.hold_bananas){
            MB room(monkey.location,bananas.location,chair,stick,monkey.hold_bananas,
                    true,monkey.hold_stick,monkey.on_chair,bananas.hanging,"grab chair: ",whichh);
            successors.push_back(room);
        }
        if (monkey.location==bananas.location && monkey.on_chair && monkey.hold_stick && bananas.hanging){
            MB room(monkey.location,bananas.location,chair,stick,monkey.hold_bananas,
                    monkey.hold_chair,monkey.hold_stick,monkey.on_chair,!bananas.hanging,"knock down bananas:",whichh);
            successors.push_back(room);
        }
        if (monkey.location==bananas.location && !bananas.hanging && !monkey.on_chair && !monkey.hold_stick && !monkey.hold_chair){
            MB room(monkey.location,bananas.location,chair,stick,true,
                    monkey.hold_chair,monkey.hold_stick,monkey.on_chair,bananas.hanging,"pick up bananas:",whichh);
            successors.push_back(room);
        }
    //generate monkey drops

        if (monkey.location==stick && monkey.hold_stick){
            MB room(monkey.location,bananas.location,chair,monkey.location,monkey.hold_bananas,
                    monkey.hold_chair,false,monkey.on_chair,bananas.hanging,"drop stick:",whichh);
            successors.push_back(room);
        }
        
        if (monkey.location==chair && monkey.hold_chair){
            MB room(monkey.location,bananas.location,monkey.location,stick,monkey.hold_bananas,
                    false,monkey.hold_stick,monkey.on_chair,bananas.hanging,"drop chair:",whichh);
            successors.push_back(room);
        }
        
    //generate monkey on chair
        if (monkey.location==chair && !monkey.hold_chair){
            MB room(monkey.location,bananas.location,chair,stick,monkey.hold_bananas,
                    monkey.hold_chair,monkey.hold_stick,true,bananas.hanging,"move onto chair:",whichh);
            successors.push_back(room);
        }
    //monkey gets off of chair
        if (monkey.location==chair && monkey.on_chair){
            MB room(monkey.location,bananas.location,chair,stick,monkey.hold_bananas,
                    monkey.hold_chair,monkey.hold_stick,false,bananas.hanging,"get off chair:",whichh);
            successors.push_back(room);
        }
        
        return successors;
    }
    
    void print(){
        cout << "Monkey is at: " << monkey.location << endl;
        cout << "on chair: " << monkey.on_chair << endl;
        cout << "holding chair: " << monkey.hold_chair << endl;
        cout << "holding stick: " << monkey.hold_stick << endl;
        cout << "holding bananas: " << monkey.hold_bananas << endl;
        cout << "bananas are at: " << bananas.location << " and hanging: " << bananas.hanging << endl;
        cout << "chair is at: " << chair << endl;
        cout << "stick is at: " << stick << endl;
        cout << "------------------------" << endl;
    }
    
    void solution(list<MB> path) {
        cout << endl << "Length of Soln. Path: " << path.size() - 1 << endl;
        list<MB>::iterator itr = path.begin();
        while(itr != path.end()) {
            cout << itr->action << "\n";
            itr++;
        }
    }
    
    int cost() {
        return 1;
    }
    
    int h () {
        if(whichh) {
            int c = 12;
            c = c - 4 * (chair == bananas.location) - 4 * (stick == bananas.location) - 4 * monkey.hold_bananas;
            return c;
        }
        else {
            int c=12;
            if (!bananas.hanging) {
                c=c-9;
                if (!monkey.hold_stick) {
                    c--;
                }
                if (!monkey.on_chair) {
                    c--;
                }
                if (monkey.hold_bananas) {
                    c--;
                }
            }
            else if (chair==bananas.location) {
                c=c-4;
                if (monkey.hold_stick) {
                    c=c-2;
                    if (monkey.location == bananas.location) {
                        c--;
                        if (monkey.on_chair) {
                            c--;
                        }
                    }
                }
            }
            else if (monkey.location == chair) {
                c--;
                if (monkey.hold_chair) {
                    c=c-2;
                    if (monkey.location == bananas.location) {
                        c--;
                    }
                }
            }
            return c;
        }
    }

    
    long hashkey() {
        long hash = 0;
        hash=monkey.location+monkey.on_chair*pow(10,1)+monkey.hold_bananas*pow(10,2)+
        monkey.hold_chair*pow(10,3)+monkey.hold_stick*pow(10,4)+chair*pow(10,5)+
        stick*pow(10,6)+bananas.location*pow(10,7)+bananas.hanging*pow(10,8);
        return hash;
    }
    
    
    
};


#endif
