//
//  Class.hpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/24/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#ifndef Class_hpp
#define Class_hpp
#include <vector>
#include <stdio.h>
#include "Student.cpp"

class Class {
    vector<Student> students;
    int size;
    
public:
    void pushStudent(Student student);
    void popStudent(int id);
    Student* findStudent(int id);
    void writeToDisk();
    void readFromDisk();
    void showAllStudent();
    void showScoreOfCourse(int code_Course);
    void StatisticFailure(int code_Course);
    void sortByCourse(int code_Course,int mode = 0); //mode 0 为降序,1为升序,default 0;
    void sortByTotalScore();
    vector<Student> getStudents();
};

#endif /* Class_hpp */
