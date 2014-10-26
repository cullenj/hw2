//
//  Astarbeam.h
//  AIHomework2
//
//  Created by David Kozloff on 10/20/14.
//  Copyright (c) 2014 Joseph Cullen. All rights reserved.
//

#ifndef AIHomework2_Astarbeam_h
#define AIHomework2_Astarbeam_h

#include <unordered_map>
#include <vector>

using namespace std;
template <class T>

class Astarbeam {
    
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
    
    bool over;
    vector<Node> fringe;
    unordered_map <long,bool> explored;
    long nodeslookedat;
    int beamwidth;
    int HUpperBound;
    
public:
    
    Astarbeam() {
        HUpperBound = 0;
        over = false;
        nodeslookedat = 0;
        beamwidth = 0;
    }
    
    ~Astarbeam() {
        
    }
    
    void setbeamwidth(int x) {
        beamwidth = x;
    }
    
    void search(T problem) {
        Node start = Node(problem);
        start.parent = &start;
        start.g = 0;
        fringe.push_back(start);
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
            Node* mostpromising = getcurrentbest();
            
            if(mostpromising->h == 0) {
                over = true;
                printsolution(mostpromising);
                return 1;
            }
            
            vector<T> successors = mostpromising->state.successors();
            for(int i = 0; i < successors.size(); i++) {
                Node *successor = new Node(successors[i]);
                if (!explored[successor->state.hashkey()]) {
                    successor->g = mostpromising->g + successor->state.cost();
                    successor->parent = mostpromising;
                    if (valid(successor->h + successor->g)) {
                        nodeslookedat++;
                        fringe.push_back(*successor);
                        explored[successor->state.hashkey()] = true;
                    }
                }
            }
        }
        return 0;
    }
    
    bool valid(int f) {
        if (fringe.size() < beamwidth) {
            if (f > fringe[HUpperBound].h + fringe[HUpperBound].g) {
                HUpperBound = (int) fringe.size() - 1;
            }
            return true;
        }
        else if(f < fringe[HUpperBound].h + fringe[HUpperBound].g) {
            fringe.erase( fringe.begin() + HUpperBound );
            HUpperBound = 0;
            for(int i = 0; i < fringe.size(); i++) {
                if (fringe[i].h + fringe[i].g > fringe[HUpperBound].h + fringe[HUpperBound].g)
                    HUpperBound = i;
            }
            if (f > fringe[HUpperBound].h + fringe[HUpperBound].g)
                HUpperBound = (int) fringe.size();
            return true;
        }
        else
            return false;
    }
    
    Node* getcurrentbest() {
        int currentlowest = 0;
        for(int i = 0; i < fringe.size(); i++) {
            if (fringe[i].h < fringe[currentlowest].h)
                currentlowest = i;
        }
        Node* best = new Node(fringe[currentlowest].state);
        best->parent = fringe[currentlowest].parent;
        best->g = fringe[currentlowest].g;
        fringe.erase(fringe.begin() + currentlowest);
        return best;
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
