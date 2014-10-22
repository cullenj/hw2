//
//  EQueens.h
//  AIHomework2
//
//  Created by David Kozloff on 10/20/14.
//  Copyright (c) 2014 Joseph Cullen. All rights reserved.
//

#ifndef AIHomework2__queens_h
#define AIHomework2__queens_h

#include <iostream>
#include <math.h>
#include <vector>
#include <list>

using namespace std;

class EQ{
    
public:
    vector<int> board;
    int n;
    string domain = "EQ ";
    
    EQ(){
        n=8;
        for(int i = 0; i < n; i++) {
            board.push_back(0);
        }
    }
    
    EQ(vector<int> b) {
        board = b;
        n = 8;
    }
    
    bool operator==(const EQ& other) {
        if(other.board.size()!= board.size()){
            return false;
        }
        for (int i = 0; i < other.board.size(); i++) {
            if(other.board[i] != board[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool operator!=(const EQ& other) {
        return !(operator==(other));
    }
    
    bool goal(){
        if(board.size()==n){
            return true;
        } else{
            return false;
        }
    }
    
    void move(int i, int j) {
        board[i] = j;
    }
    
    vector<EQ> successors() {
        vector<EQ> successors;
        EQ *successor;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i] != j) {
                    successor = new EQ(board);
                    successor->move(i,j);
                    successors.push_back(*successor);
                }
            }
        }
        return successors;
    }
    
    void print(){
        for(int j=0; j<n; j++){
            for (int i=0; i<n; i++){
                if (i==board[j]){
                    cout << "X ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
        for(int i=0; i<board.size();i++) {
            cout << board[i] << " ";
        }
        cout << "\n\n";
    }
    
    void solution(list<EQ> path) {
        cout << endl << "Length of Soln. Path: " << path.size() +1 << endl;
        (--path.end())->print();
    }
    
    long hashkey() {
        long hash = 0;
        for(int i = 0; i < board.size(); i++ ) {
            hash = board[i]*pow(10,i);
        }
        return hash;
    }
    
    int collisions() {
        int x = 0;
        for (int queen_pos=0; queen_pos < n; queen_pos++){
            for (int k=0; k < n;k++){
                if (queen_pos == board[k]) {x++; break;} //same row?
                else if ((board[k]-k)==(queen_pos-board.size())) {x++; break;} //down diagonal?
                else if ( board[k] - queen_pos == board.size()-k ) {x++; break;} //up diagonal?
            }
        }
        return x;
    }
    
    int cost() {
        return 1;
    }
    
    int h() {
        return 8 - collisions();
    }
    
};

#endif
