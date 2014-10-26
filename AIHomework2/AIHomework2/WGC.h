//
//  WGC.h
//  AIHomework2
//
//  Created by Joe Cullen on 10/20/14.
//  Copyright (c) 2014 Joseph Cullen. All rights reserved.
//

#ifndef AIHomework2_WGC_h
#define AIHomework2_WGC_h


#include <iostream>
#include <math.h>
#include <vector>


using namespace std;

class WGC {
public:
    vector<bool> items; //false means on the left bank
    string action;
    
    WGC(){
        items.push_back(false);  //wolf is on left bank
        items.push_back(false);  //goat is on left bank
        items.push_back(false);  //cabbage is on left bank
        action="start: ";
    }
    
    WGC(bool w,bool g, bool c,string act){
        items.push_back(w);
        items.push_back(g);
        items.push_back(c);
        action=act;
    }
    
    bool operator==(const WGC& other){
        if (other.items[0]==items[0] && other.items[1]==items[1] && other.items[2]==items[2]){
            return true;
        } else{
            return false;
        }
    }
    
    bool operator!=(const WGC& other) {
        return !(operator==(other));
    }
    
    bool goal(){
        if(items[0]==items[1]==items[2]==true) {return true;}
        else {return false;}
    }

    vector<WGC> successors(){
        vector<WGC> successors;
        bool w=items[0];
        bool g=items[1];
        bool c=items[2];
        //move wolf
        if (c!=g){
            successors.push_back(WGC(!w,g,c,"move wolf"));
        }
        //move goat
        successors.push_back(WGC(w,!g,c,"move goat"));
        //move cabbage
        if (g!=w){
            successors.push_back(WGC(w,g,!c,"move cabbage"));
        }
        return successors;
    }
    
    void print(){
        cout << "wolf is at "<< items[0] << endl;
        cout << "goat is at "<< items[1] << endl;
        cout << "cabbage is at "<< items[2] << endl;
    }
    
    void solution(list<WGC> path) {
        cout << endl << "Length of Soln. Path: " << path.size() +1 << endl;
        list<WGC>::iterator itr = path.begin();
        itr++;
        while(itr != path.end()) {
            cout << itr->action << "\n";
            itr++;
        }
    }
    
    int h(){
        int h=8;
        bool w=items[0];
        bool g=items[1];
        bool c=items[2];
        if (w==true){
            h=h-4;
            if (g==true){
                h=h-2;
                if (c==true){
                    h=h-2;
                }
            }
        }
        return h;
    }
    
    int cost(){
        return 1;
    }
    
    long hashkey(){
        long hash;
        hash=items[0]+items[1]*pow(10,1)+items[2]*pow(10,3);
        return hash;
    }
    
};

#endif
