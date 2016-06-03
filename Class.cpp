//
//  Class.cpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/24/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#include "Class.hpp"
void Class::pushStudent(Student student) {
    students.push_back(student);
}

void Class::popStudent(int id) {
    unsigned long size = students.capacity();
    for( int i = 0; i < size; i++) {
        if( students[i].getId() == id) {
            students.erase(students.begin() + i);
        }
    }
}
Student* Class::findStudent(int id) {
    unsigned long size = students.capacity();
    Student *student = nullptr;
    for(int i = 0; i < size; i++) {
        if(students[i].getId() == id) {
            student = &students[i];
        }
    }
    return student;
}

void  Class::writeToDisk() {
    unsigned long size = students.capacity();
    
    ofstream file_Student("student.txt", ios_base::out);
    ofstream file_Score("score.txt", ios_base::out);
    
    
    //这里似乎还有优化的空间
    for(int i = 0; i < size; i++) {
        
        file_Student << students[i].getId() << " " << students[i].getName() << "\n";
        vector<Score> score = students[i].getScores();
        for(int j = 0; j < score.capacity(); j++) {
            file_Score << students[i].getId() << " " << score[j].getCode() << " " << score[j].getScore() << "\n";
        }
    }
    
    file_Student.close();
    file_Score.close();
    
}



void Class::readFromDisk() {
    //首先先读取Course
    ifstream file_Course("./Course.txt");
    ifstream file_Student("./student.txt");
    ifstream file_Score("./score.txt");
    vector<Course> courses;
    if(file_Course.is_open()) {
        while ( !file_Course.eof() ){
            int code_Course;
            std::string name;
            int credit;
            file_Course >> code_Course >> name >> credit;
            cout << code_Course << name << credit << endl;
            Course course(code_Course);
            courses.push_back(course);
        }
        cout << "size of " << courses.capacity() << endl;
    }
    else cout << "reading Course.txt failure " << endl;
    //再读取学生
    
    
    while( !file_Student.eof()) {
        int id;
        std::string name;
        file_Student >> id >> name;
        Student student(id,name);
        students.push_back(student);
        
    }
    //读取成绩
    vector<Score> scores;
    while( !file_Score.eof()) {
        int id;
        int code_Course;
        int score;
        
        file_Score >> id >> code_Course >> score;
        Course * course = nullptr;
        for(int i = 0; i < courses.capacity(); i++) {
            if( courses[i].getCode() == code_Course) {
                course = &courses[i];
            }
        }
        Score score1(id, code_Course, score);
        for(int j = 0; j < students.capacity(); j++) {
            if( id == students[j].getId()) {
                students[j].pushScore(score1);
            }
        }
        scores.push_back(score1);
    }
    file_Score.close();
    file_Course.close();
    file_Student.close();
}

void Class::showAllStudent() {
    for( int i = 0; i < students.capacity(); i++) {
        std::cout << students[i].getId() << "  " << students[i].getName() << "  ";
        vector<Score> score = students[i].getScores();
        for(int j = 0; j < score.capacity(); j++) {
            std::cout << score[j].getCourseName() << "  " << score[j].getScore() << "  ";
        }
        std::cout << endl;
    }
}

void Class::showScoreOfCourse(int code_Course) {
    for(int i = 0; i < students.capacity(); i++) {
        std::cout << students[i].getId() << "  " << students[i].getName() << "  " << students[i].getScore(code_Course) << endl;
    }
}

void Class::StatisticFailure(int code_Course) {
    int count = 0;
    for(int i = 0; i < students.capacity(); i++) {
        if (students[i].getScore(code_Course) < 60) {
            std::cout << students[i].getId() << "  " << students[i].getName() << "  " << students[i].getScore(code_Course) << endl;
            count++;
        }
    }
    std::cout << count << " student(s) fail the exam" << endl;
}

void Class::sortByCourse(int code_course, int mode){
    //先降序排好,然后再根据mode的值进行正向或者反向输出
    
    vector<Student> students_temp = students;
    
    for(int i = 0; i < students_temp.capacity(); i++) {
        for (int j = 0; j < students_temp.capacity() - 1 - i; j++) {
            if( students_temp[j].getScore(code_course) < students_temp[j + 1].getScore(code_course)) {
                Student temp = students_temp[j];
                students_temp[j] = students_temp[j + 1];
                students_temp[j + 1] = temp;
            }
        }
    }
    //在屏幕上输出
    std::cout << "COURSE" << ":" << code_course << endl;
    std::cout << "ID" << "        " << "NAME" << "        " << "Score" << std::endl;
    for(int i = 0; i < students_temp.capacity(); i++) {
        std::cout << students_temp[i].getId() << "        " << students_temp[i].getName() << "        " << students_temp[i].getScore(code_course) << endl;
    }
    
    
    
    
}
void Class::sortByTotalScore() {
    vector<Student> students_temp = students;
    
    for(int i = 0; i < students_temp.capacity(); i++) {
        for (int j = 0; j < students_temp.capacity() - 1 - i; j++) {
            if( students_temp[j].getTotalScore() > students_temp[j + 1].getTotalScore()) {
                Student temp = students_temp[j];
                students_temp[j] = students_temp[j + 1];
                students_temp[j + 1] = temp;
            }
        }
    }
    
    std::cout << "ID" << "        " << "NAME" << "        " << "TotalScore" << std::endl;
    for(int i = 0; i < students_temp.capacity(); i++) {
        std::cout << students_temp[i].getId() << "        " << students_temp[i].getName() << "        " << students_temp[i].getTotalScore() << endl;
    }
    
}

vector<Student> Class::getStudents() {
    return students;
}
