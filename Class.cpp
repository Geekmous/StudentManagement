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
    
    for( auto stu_pd = students.begin(); stu_pd != students.end(); stu_pd++) {
        if( stu_pd->getId() == id) {
            students.erase(stu_pd);
            break;
        }
    }
}
void Class::findStudent(int id) {
    auto stu_pd = students.begin();
    bool flag = false;
    for(; stu_pd != students.end(); stu_pd++) {
        if(stu_pd->getId() == id) {
            cout << *stu_pd << endl;
            flag = true;
        }
    }
    if(flag == false)
        cout << "sorry there are no student of this id" << endl;
    
    
}
void Class::editStudent(int id,int id_change, string name, int code_Course , int score) {
    auto stu_pd = students.begin();
    for(; stu_pd != students.end(); stu_pd++) {
        if(stu_pd->getId() == id) {
            stu_pd->setId(id_change);
            stu_pd->setName(name);
            stu_pd->editCourse(code_Course, score);
        }
    }
}

void  Class::writeToDisk() {                        //将班级成员的信息写入到文件中
    auto stu_pd = students.begin();
    
    ofstream file_Student("student.txt", ios_base::out);
    ofstream file_Score("score.txt", ios_base::out);
    
   // cout << "there has " << getSize() << endl;
    
    for(; stu_pd != students.end(); stu_pd++) {
        if( stu_pd + 1 < students.end() ) {
            file_Student << stu_pd->getId() << " " << stu_pd->getName() << "\n";
            //cout << "write :::" << *stu_pd << endl;
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
    //cout << "read student " << endl;
    while( !file_Student.eof()) {
        int id;
        std::string name;
        file_Student >> id >> name;
        Student student(id,name);
        students.push_back(student);
    
    }
    //读取成绩
    vector<Score> scores;
    
    while( !file_Score.eof() ) {
        int id, code_Course, score;
        if(file_Score >> id >> code_Course >> score) {
            Score score1(id, code_Course, score);
            for(int j = 0; j < students.capacity(); j++) {
                
                if( id == students[j].getId()) {
                    students[j].pushScore(score1);
                }
            }
        }
    }
    file_Score.close();
    file_Student.close();
}

void Class::showAllStudent() {
    for(auto pd = students.begin(); pd < students.end(); pd++) {
        std::cout << pd->getId() << "  " << pd->getName() << "  ";
        vector<Score> score = pd->getScores();
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
    Course cour(code_Course);
    for(auto pd = students.begin(); pd < students.end(); pd++) {
        if (pd->getScore(code_Course) < 60) {
            std::cout << pd->getId() << "  " << pd->getName() << "  " << cour.getName() << " " << pd->getScore(code_Course) << endl;
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
