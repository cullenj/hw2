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
private:
    vector<bool> items; //false means on the left bank
public:
    
    WGC(){
        vector<bool> items;
        items.push_back(false);  //wolf is on left bank
        items.push_back(false);  //goat is on left bank
        items.push_back(false);  //cabbage is on left bank
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
 /*
    vector<WGC> successors(){
        vector<WGC> successors;
        WGC successor;
        bool w=successor.items[0];
        bool g=successor.items[1];
        bool c=successor.items[2];
        if (w!=g && g!=c)
            vector
        
        
    }
  */
    
};

#endif
