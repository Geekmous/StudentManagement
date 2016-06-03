//
//  Menu.hpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/28/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp
#include "Class.cpp"
#include <stdio.h>
#include "iostream"
using namespace std;
class Menu {
    Class cla;
public:
    Menu();
    void start();
    void showMainMenu();
    void showStudentInformationMenu();
    void showGradeMenu();
    void showStatisticMenu();
    friend void searchStudent(Class &c, int student_id);
};

#endif /* Menu_hpp */
