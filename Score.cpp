//
//  Score.cpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/24/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#include "Score.hpp"
Score::Score(int id, int code_Course_, int score):id(id), code_Course(code_Course_), score(score),course(code_Course){
};
int Score::getScore() {
    return score;
}
int Score:: getCredit() {
    return course.getCredit();
}

int Score::getCode() {
    return code_Course;
}

std::string Score::getCourseName() {
    return course.getName();
}

void Score::setScore(int score) {
    this->score = score;
}

ostream & operator<<(ostream &os, const Score &sco) {     //输入course还有对应的成绩
    os << sco.course << " " << sco.score;
    return os;
}