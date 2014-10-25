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
        Node* parent;
        int g;
        int h;
        T state;
        Node() {  }
        Node(T& x) {
            state = x;
            //x.print();
            h = x.h();
        }
    };
    
    class CompareNodes {
    public:
        bool operator()(Node& a, Node& b) {
            return a.h + a.g > b.h + b.g;
        }
    };
    
    bool over;
    priority_queue<Node,vector<Node>,CompareNodes> fringe;
    unordered_map <long,bool> explored;
    long nodeslookedat;
    
public:
    
    Astar() {
        over = false;
        nodeslookedat = 0;
    }
    
    ~Astar() {
        
    }
    
    void search(T problem) {
        Node start = Node(problem);
        start.parent = &start;
        start.g = 0;
        fringe.push(start);
        nodeslookedat++;
        explored[problem.hashkey()] = true;
        while(!over) {
            expand();
        }
        
    }
    
    int expand() {
        if(fringe.empty()) {
            over = true;
            return -1;
        }
        
        if(over) {
            return 0;
        }
        
        else {
            T temp = fringe.top().state;
            Node* mostpromising = new Node(temp);
            mostpromising->parent = fringe.top().parent;
            fringe.pop();
            
            if(mostpromising->h == 0) {
                over = true;
                printsolution(mostpromising);
                return 1;
            }
            
            vector<T> successors = mostpromising->state.successors();
            for(int i = 0; i < successors.size(); i++) {
                Node *successor = new Node(successors[i]);
                if (!explored[successor->state.hashkey()]) {
                    nodeslookedat++;
                    successor->g = mostpromising->g + successor->state.cost();
                    successor->parent = mostpromising;
                    fringe.push(*successor);
                    explored[successor->state.hashkey()] = true;
                }
            }
        }
        return 0;
    }
    
    void printsolution(Node* solution) {
        cout << "Solution Found!\n";
        cout << "Number of nodes expanded: " << nodeslookedat << "\n";
        list<T> solutionpath;
        while(solution->parent != solution) {
            solutionpath.push_front(solution->state);
            solution = solution->parent;
        }
        solutionpath.push_front(solution->state);
        solution->state.solution(solutionpath);
    }
    
};

#endif
