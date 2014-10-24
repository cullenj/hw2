//
//  Astar.h
//  AIHomework2
//
//  Created by David Kozloff on 10/20/14.
//  Copyright (c) 2014 Joseph Cullen. All rights reserved.
//

#ifndef AIHomework2_Astar_h
#define AIHomework2_Astar_h

#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;
template <class T>

class Astar {
    
private:
    
    struct Node
    {
        Node* previous;
        int g;
        int h;
        T state;
        //Node() {  }
        Node(T& x) {
            state = x;
            h = x.h();
        }
    };
    
    class CompareNodes {
    public:
        bool operator()(Node& a, Node& b) {
            return a.h + a.g < b.h + b.g;
        }
    };
    
    bool over;
    priority_queue<Node,vector<Node>,CompareNodes> fringe;
    unordered_map <long,bool> explored;
    
public:
    
    Astar() {
        over = false;
    }
    
    ~Astar() {
        
    }
    
    void search(T problem) {
        Node start = Node(problem);
        start.g = 0;
        fringe.push(start);
        explored[problem.hashkey()] = true;
        while(!over) {
            expand();
        }
    }
    
    void expand() {
        if(fringe.empty()) {
            over = true;
        }
        
        else {
            Node mostpromising = fringe.top();
            mostpromising.state.print();
            fringe.pop();
            
            if(mostpromising.h == 0) {
                over = true;
            }
            
            vector<T> successors = mostpromising.state.successors();
            for(int i = 0; i < successors.size(); i++) {
                
                Node successor = Node(successors[i]);
                if (!explored[successor.state.hashkey()]) {
                    successor.g = mostpromising.g + successor.state.cost();
                    fringe.push(successor);
                }
                
            }
        }
    }
    
};

#endif
