//
//  Student.cpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/24/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#include "Student.hpp"
Student::Student(){
    id = -1;
    name = "Nan";
    index = -1;
};

Student::Student(int id, std::string name):id(id),name(name), index(0){
    vector<Score> sco;
    scores = sco;
};

Student::Student(const Student & student) {
    this->id = student.id;
    this->name = student.name;
    this->index = student.index;
    this->scores = student.scores;
}



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

void Student::pushScore(Score &score) {
    scores.push_back(score);
}

vector<Score> & Student::getScores() {
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
    for( Score score : s.scores)
        os << score << " ";
    
    return os;
}

Student & Student::operator=(Student & student) {
    if(this == &student)
        return *this;
    this->id = student.id;
    this->name = student.name;
    this->scores = student.scores;
    this->index = student.index;
    return *this;
}

void Student::write2file(ostream & os) const {
    string path = "score.txt";
    for(Score sco : scores)
        os << id << " " << sco.getCode() << " " << sco.getScore() << "\n" ;
    
}
