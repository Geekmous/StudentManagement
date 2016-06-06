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
    //cla.writeToDisk();
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
    cout << "your choice :";
    while( !(cin >> choice) || (choice > 4 || choice < 0)) {
        cin.clear();
        while( cin.get() != '\n')
            continue;
        cout << "bad input and input again" << endl;
        cout << "your choice :";
    }
    
    switch(choice) {
        case 1: showStudentInformationMenu();break;
        case 2: showGradeMenu();break;
        case 3: showStatisticMenu();break;
        case 4: choice = 1;break;
        default: choice = 0,cout << "bad input and input again" << endl;
    }
    
}

void Menu::showStudentInformationMenu() {
    cout << "show all students" << endl;
    cla.showAllStudent();
    int choice = 0;
    do {
        cout << "********************************" << endl;
        cout << "       1.add student            " << endl;
        cout << "       2.edit student           " << endl;
        cout << "       3.delete student         " << endl;
        cout << "       4.quit                   " << endl;
        cout << "********************************" << endl;
        cout << "Your choice : ";
        cout << "your choice :";
        while( !(cin >> choice) || (choice > 4 || choice < 0)) {
            cin.clear();
            while( cin.get() != '\n')
                continue;
            cout << "bad input and input again" << endl;
            cout << "your choice :";
        }
        
        switch (choice) {
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
                    int id_change;
                    string name_change;
                    cout << "please input the changed id and name :" << endl;
                    while( !(cin >> id_change >> name_change)) {
                        cin.clear();
                        while( cin.get() != '\n')
                            continue;
                        cout << "bad input and input again" << endl;
                        cout << "please input the changed id and name :" << endl;
                    }
                    
                    int code_Course, score;
                    cout << "input the code of Course and score (exit if input other words)" << endl;
                    cout << "code     score" << endl;
                    while( cin >> code_Course >> score) {
                        cla.editStudent(id, id_change, name_change, code_Course, score);
                    }
                    
                    
                }
                cla.writeToDisk();
                break;
                
            }
            case 3: {
                int id;
                cout << "please input the id of student you want to delete:" << endl;
                while ( !(cin >> id)) {
                    cin.clear();
                    while(cin.get() != '\n')
                        continue;
                    cout << " bad input and input again " << endl;
                    cout << "please input the id of student you want to delete:" << endl;

                    
                }
                cla.popStudent(id);
                cla.writeToDisk();
                break;
            }
            case 4: choice = 1;break;
            default :choice = 0;
        }
        
    }while(!choice);
    
}

void searchCourse(Class &c,const int code_Course) {
    vector<Student> students = c.getStudents();
    Course course(code_Course);
    for(int i = 0; i < students.capacity(); i++) {
        cout << students[i].getId() << " " << students[i].getName() << " " << course.getName() << " " << students[i].getScore(code_Course) << endl;
    }
}

void Menu::showGradeMenu() {
    cout << "********************************" << endl;
    cout << "       1.Search Student         " << endl;
    cout << "       2.Search  Course         " << endl;
    cout << "********************************" << endl;
    int choice = 0;
    cout << "your choice :";
    while( !(cin >> choice) || (choice > 2 || choice < 0)) {
        cin.clear();
        while( cin.get() != '\n')
            continue;
        cout << "bad input and input again" << endl;
        cout << "your choice :";
    }
    
    switch (choice){
        case 1:cout << " please input Student ID : " << endl;int id; cin >> id; cla.findStudent(id);break;
        case 2:cout << " please input Student Course code : " << endl;int code;cin >> code;searchCourse(cla, code);break;
        default: choice = 0;
    }
    
}
void Menu::showStatisticMenu() {
    cout << "********************************" << endl;
    cout << "       1.Course failure         " << endl;
    cout << "       2.Sort Scores            " << endl;
    cout << "       3.Sort ToTalScores       " << endl;
    cout << "       4.exit                   " << endl;
    cout << "********************************" << endl;
    int choice = 0;
    cout << "your choice :";
    while( !(cin >> choice) || (choice > 4 || choice < 0)) {
        cin.clear();
        while( cin.get() != '\n')
            continue;
        cout << "bad input and input again" << endl;
        cout << "your choice :";
    }
    switch (choice) {
        case 1: cout << "please input the code of the course :";int code_Cour; cin >> code_Cour;cla.StatisticFailure(code_Cour);break;
        case 2: cout << "please input the code of the course:";int code_Cours; cin >> code_Cours; cla.sortByCourse(code_Cours);break;
        case 3: cla.sortByTotalScore();break;
        case 4:break;
        default: choice = 0;
        }
}


int main(void) {
    Menu menu;
    menu.start();
    
    return 0;
}