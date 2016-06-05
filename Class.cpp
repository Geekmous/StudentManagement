//
//  Class.cpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/24/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#include "Class.hpp"
Class::Class():size(0), students(0){
}

void Class::pushStudent(Student * student) {
    (this->size)++;
    students.push_back(*student);
}

void Class::popStudent(int id) {
    unsigned long size = students.capacity();
    for( int i = 0; i < size; i++) {
        if( students[i].getId() == id) {
            students.erase(students.begin() + i);
        }
    }
}
Student & Class::findStudent(int id) {
    unsigned long size = students.capacity();
    Student *student = nullptr;
    for(int i = 0; i < size; i++) {
        if(students[i].getId() == id) {
            student = &students[i];
        }
    }
    if( student == nullptr)
        cout << "there is no such person" << endl;
    return *student;
}

void  Class::writeToDisk() {
    auto stu_pd = students.begin();
    
    ofstream file_Student("student.txt", ios_base::out);
    ofstream file_Score("score.txt", ios_base::out);
    
    cout << "there has " << getSize() << endl;
    
    for(; stu_pd != students.end(); stu_pd++) {
        if( stu_pd + 1 < students.end() ) {
            file_Student << stu_pd->getId() << " " << stu_pd->getName() << "\n";
            cout << "write :::" << *stu_pd << endl;
            stu_pd->write2file(file_Score);
        }
        else {
        stu_pd->write2file(file_Score);
        file_Student << stu_pd->getId() << " " << stu_pd->getName();
        }
        
    }
    file_Student.close();
    file_Score.close();
    
}



void Class::readFromDisk() {
    ifstream file_Student("./student.txt");
    ifstream file_Score("./score.txt");
    //读取学生
    cout << "read student " << endl;
    while( !file_Student.eof()) {
        int id;
        std::string name;
        file_Student >> id >> name;
        Student student(id,name);
        students.push_back(student);
        cout << "read  " << id << name << endl;
    }
    //读取成绩
    vector<Score> scores;
    
    while( !file_Score.eof() ) {
        int id, code_Course, score;
        if(file_Score >> id >> code_Course >> score) {
            Score score1(id, code_Course, score);
            cout << "read from " << "id : " << id << " code : " << code_Course << " score : " << score << endl;
            for(int j = 0; j < students.capacity(); j++) {
                cout << "start loop " << endl;
                if( id == students[j].getId()) {
                    cout << "the score" << score1 << " will be push in to " << students[j];
                    students[j].pushScore(score1);
                }
            }
        }
        //scores.push_back(score1);
    }
    file_Score.close();
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

int Class::getSize() const{
    return this->size;
}
