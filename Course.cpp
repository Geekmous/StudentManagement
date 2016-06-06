//
//  Course.cpp
//  StudentSystem
//
//  Created by 潘俊霖 on 5/24/16.
//  Copyright © 2016 潘俊霖. All rights reserved.
//

#include "Course.hpp"
Course::Course(int code):code_Course(code){
    ifstream fis("./Course.txt");
    std::string name_temp;
    int credit_temp, code_temp;
    if(fis.is_open()) {
        while(!fis.eof()) {
            fis >> code_temp >> name_temp >> credit_temp;
            if(code_temp == code) {
                this->code_Course = code_temp;
                this->name_Course = name_temp;
                this->credit = credit_temp;
            }
        }
    }else {
        this->code_Course = -1;
        this->name_Course = "NAN";
        this->credit = -1;
    }
    fis.close();
};


int Course::getCode() const {
    return code_Course;
};
std::string Course::getName() const {
    return name_Course;
};
int Course::getCredit() const {
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
