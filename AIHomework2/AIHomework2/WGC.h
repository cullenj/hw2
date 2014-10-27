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
#include <limits>


using namespace std;

class WGC {
public:
    vector<bool> items; //LEFT means on the left bank
    string action;
    bool LEFT = false;
    bool RIGHT = true;
    
    WGC(){
        items.push_back(LEFT);  //wolf is on left bank
        items.push_back(LEFT);  //goat is on left bank
        items.push_back(LEFT);  //cabbage is on left bank
        items.push_back(LEFT); //boat is on left bank
        action="start: ";
    }
    
    WGC(bool w,bool g, bool c, bool b, string act){
        items.push_back(w);
        items.push_back(g);
        items.push_back(c);
        items.push_back(b);
        action=act;
    }
    
    bool operator==(const WGC& other){
        return (other.items[0]==items[0] && other.items[1]==items[1] && other.items[2]==items[2] && other.items[3] == items[3]);
    }
    
    bool operator!=(const WGC& other) {
        return !(operator==(other));
    }
    
    bool goal(){
        if(items[0]==items[1]==items[2]==items[3]==RIGHT) {return RIGHT;}
        else {return LEFT;}
    }

    vector<WGC> successors(){
        vector<WGC> successors;
        bool w=items[0];
        bool g=items[1];
        bool c=items[2];
        bool b=items[3];
        
        if(valid()) {
        //move wolf
            if (b == w)
                successors.push_back(WGC(!w,g,c,!b,"move wolf "));
        //move goat
            if (b == g)
                successors.push_back(WGC(w,!g,c,!b,"move goat "));
        //move cabbage
            if (b == c)
                successors.push_back(WGC(w,g,!c,!b,"move cabbage "));
        //move boat
        successors.push_back(WGC(w,g,c,!b,"move boat "));
        }
        return successors;
    }
    
    void print(){
        cout << "wolf is at "<< items[0] << endl;
        cout << "goat is at "<< items[1] << endl;
        cout << "cabbage is at "<< items[2] << endl << endl;
        
    }
    
    void solution(list<WGC> path) {
        cout << endl << "Length of Soln. Path: " << path.size() - 1 << endl;
        list<WGC>::iterator itr = path.begin();
        while(itr != path.end()) {
            cout << itr->action << "\n";
            itr++;
        }
    }
    
    bool valid() {
        bool w=items[0];
        bool g=items[1];
        bool c=items[2];
        bool b=items[3];
        if (g==c && g != b) {
            return false;
        }
        if (g==w && g!= b) {
            return false;
        }
        return true;
    }
    
    /*
    int h(){
        bool w=items[0];
        bool g=items[1];
        bool c=items[2];
        return !w+!g+!c;
    }*/
    
    
    int h() {
        bool w=items[0];
        bool g=items[1];
        bool c=items[2];
        if ((w && !g && !c)||(!w && !g && c)) {
            return 1;
        }
        else
            return 2*!w + !g + 2*!c;
    }
    /*
    int h() {
        bool w=items[0];
        bool g=items[1];
        bool c=items[2];
        if (w && g && c)
            return 0;
        else return 1;
    }
     */
    
    int cost(){
        return 1;
    }
    
    long hashkey(){
        long hash;
        hash=items[0]+items[1]*pow(10,1)+items[2]*pow(10,3)+items[3]*pow(10,4);
        return hash;
    }
    
};

#endif
