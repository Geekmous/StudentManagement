//
//  Course.hpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/24/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#ifndef Course_hpp
#define Course_hpp
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Course{
    int code_Course;
    std::string name_Course;
    int credit;
public:
    Course();
    Course(int code);                                   //根据code_Course创建Course类
    int getCode();                                      //得到课程的代码
    std::string getName();                              //得到课程的名字
    int getCredit();                                    //得到课程的学分
    friend ostream & operator<<(ostream & os, const Course & course);
};

#endif /* Course_hpp */
