//
//  Score.hpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/24/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#ifndef Score_hpp
#define Score_hpp

#include <stdio.h>
#include "Course.cpp"
#include <string>
class Score{
    int id;
    int code_Course;
    Course course;
    int score;
public:
    Score();
    Score(int id, int code_Course, int score);
    int getScore() ;                 //得到某成绩的成绩
    int getCredit() ;                //得到该成绩的学分
    int getCode() ;                  //得到该成绩的课程代码
    std::string getCourseName() ;    //得到该成绩的名称
    void setScore(int score);       //设置成绩的成绩
    friend ostream & operator<<(ostream &os, const Score &sco);
};

#endif /* Score_hpp */
