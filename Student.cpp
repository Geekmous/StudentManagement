//
//  Student.cpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/24/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#include "Student.hpp"
Student::Student(int id, std::string name):id(id),name(name){
    index = 0;
};

int Student::getScore(int code_Course) {
    unsigned long size = scores.size();
    for( int i = 0; i < size; i++) {
        if( scores[i].getCode() == code_Course) {
            return scores[i].getScore();
        }
    }
    return -1;
}

int Student::getId() {
    return id;
    
}

std::string Student::getName() {
    return name;
}

int Student::editCourse(int code_Course, int score) {
    long size = scores.size();
    int flag = 0;
    for ( int i = 0; i < size; i++) {
        if( scores[i].getCode() == code_Course) {
            scores[i].setScore(score);
            flag = 1;
        }
        
    }
    return flag;
}

void Student::pushScore(Score score) {
    scores.push_back(score);
}

vector<Score> Student::getScores() {
    return scores;
}
int Student::getTotalScore() {
    int sum = 0;
    for(int i = 0; i < scores.capacity(); i++) {
        sum += scores[i].getScore();
    }
    return sum;
}

ostream & operator<<(ostream &os, const Student &s) {
    os << s.id << " " << s.name << " ";
    for(int i = 0; i < s.scores.capacity(); i++) {
        os << s.scores[i] << " ";
    }
    return os;
}


