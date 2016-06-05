//
//  Menu.cpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/28/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#include "Menu.hpp"
Menu::Menu(){
    cla.readFromDisk();
    cla.writeToDisk();
    //cout << "read From Disk" << endl;
    vector<Student> student = cla.getStudents();
    for(int i = 0; i < student.capacity(); i++) {
        cout << student[i] << endl;
    }
    
}
void Menu::start() {
    showMainMenu();
}

void Menu::showMainMenu() {
    cout << "************Main   Menu***********" << endl;
    cout << "      1.Student information       " << endl;
    cout << "      2.Student Grade             " << endl;
    cout << "      3.Grade Statistic           " << endl;
    cout << "      4.exit                      " << endl;
    cout << "************Main   Menu***********" << endl;
    int choice = 0;
    while ( !choice ) {
        cin >> choice;
        switch(choice) {
            case 1: showStudentInformationMenu();break;
            case 2: showGradeMenu();break;
            case 3: showStatisticMenu();break;
            case 4:choice = 1;break;
            default: choice = 0;
        }
    }
    
}

void Menu::showStudentInformationMenu() {
    cout << "show all students" << endl;
    cla.showAllStudent();
    int choise = 0;
    do {
        cout << "********************************" << endl;
        cout << "       1.add student            " << endl;
        cout << "       2.edit student           " << endl;
        cout << "       3.delete student         " << endl;
        cout << "       4.quit                   " << endl;
        cout << "********************************" << endl;
        cout << "Your choice : ";
        while (!(cin >> choise)) {      //bad input
            cout << "error input and input again " << endl;
            cout << "Your choice : ";
            cin.clear();
            while( cin.get() != '\n')
                continue;
        }
        
        switch (choise) {
            case 1: {
                
                        cout << "add student " << endl;
                        cout << "please input ID Name :" << endl;
                        int id, code_Course, scores;
                        string name;
                
                        while( !(cin >> id >> name) ) {
                            cout << "eooro input and please input again" << endl;
                            cout << "please input ID Name :" << endl;
                            cin.clear();
                            while( cin.get() != '\n' )
                                continue;
                        }
                
                        Student student(id, name);
                        cout << " please input CourseCode and Scores(exit with q) " << endl;
                
                        while( (cin >> code_Course >> scores) ) {
                            Score sco(id, code_Course,scores);
                            student.pushScore(sco);
                        }
                
                        Student stu = student;
                        cout << stu << endl;
                        cla.pushStudent(&student);
                        cla.writeToDisk();
                        break;
                    }
            case 2: {
                int id;
                cout << "please input the id of student :" << endl;
                
                if( cin >> id ) {
                    Student stu = cla.findStudent(id);
                    cout << stu << endl;
                    //单独修改
                    
                }
                cla.writeToDisk();
                break;
                
            }
            case 3: {
                int id;
                cout << "please input the id of student you want to delete:" << endl;
                cla.popStudent(id);
                cla.writeToDisk();
                break;
            }
            case 4: choise = 1;break;
            default :choise = 0;
        }
        
    }while(!choise);
    
}

void searchStudent(Class &c, int student_id) {
    Student student = c.findStudent(student_id);
    cout << student << endl;
}
void searchCourse(Class &c,const int code_Course) {
    vector<Student> students = c.getStudents();
    for(int i = 0; i < students.capacity(); i++) {
        cout << students[i].getId() << " " << students[i].getName() << " " << students[i].getScore(code_Course) << endl;
    }
}

void Menu::showGradeMenu() {
    cout << "********************************" << endl;
    cout << "       1.Search Student         " << endl;
    cout << "       2.Search  Course         " << endl;
    cout << "********************************" << endl;
    int choise = 0;
    while ( !choise ) {
        cin >> choise;
        switch (choise){
            case 1:cout << " please input Student ID : " << endl;int id; cin >> id; searchStudent(cla, id);break;
            case 2:cout << " please input Student Course code : " << endl;int code;cin >> code;searchCourse(cla, code);break;
            default: choise = 0;
        }
    }
}
void Menu::showStatisticMenu() {
    cout << "********************************" << endl;
    cout << "       1.Course failure         " << endl;
    cout << "       2.Sort Scores            " << endl;
    cout << "       3.Sort ToTalScores       " << endl;
    cout << "********************************" << endl;

}









int main(void) {
    Menu menu;
    menu.start();
    
    return 0;
}