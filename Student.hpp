//
//  Student.hpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/24/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Score.cpp"
class Student{
    int id;
    std::string name;
    std::vector<Score> scores;
    unsigned int index;
public:
    Student();
    Student(int id, std::string name);
    int getScore(int code_Course);  //得到某课程代码的成绩
    int getId();                    //得到学生的ID
    std::string getName();          //得到学生的姓名
    int editCourse(int code_Course,int score); //修改某课程代码的成绩
    void pushScore(Score score);                //把某课程加到学生的课程列表中
    vector<Score> getScores();                  //返回学生的课程
    int getTotalScore();
    friend ostream & operator<<(ostream & os,const Student &s);
//    int popScore();
    
};
#endif /* Student_hpp */
