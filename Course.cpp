//
//  Course.cpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/24/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#include "Course.hpp"
Course::Course(){};
Course::Course(int code):code_Course(code){
    ifstream fis("./Course.txt");
    std::string name_temp;
    int credit_temp;
    int code_temp;
    if(fis.is_open()) {
        while(!fis.eof()) {
            fis >> code_temp >> name_temp >> credit_temp;
            if(code_temp == code) {
                code_Course = code_temp;
                name_Course = name_temp;
                credit = credit_temp;
            }
        }
    }
    fis.close();
};


int Course::getCode() {
    return code_Course;
};
std::string Course::getName(){
    return name_Course;
};
int Course::getCredit() {
    return credit;
};

ostream & operator<<(ostream & os, const Course & course) {
    os << course.code_Course << " " << course.name_Course << " " << course.credit;
    return os;
}

/*int main(int argc, char *argv[]) {
    ifstream fis("./Course.txt");
    int code;
    std::string name;
    int credit;
    if(fis.is_open()) {
        while(!fis.eof()){
            fis >> code >> name >> credit;
            Course course(code);
            std::cout << "the code is " << course.getCode() << "   the name is  " << course.getName() << "  the credit is  " << course.getCredit() << std::endl;
    }
    }
}*/
