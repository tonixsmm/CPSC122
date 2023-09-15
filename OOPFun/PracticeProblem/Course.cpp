#include "Course.h"

Course::Course() : CourseCatalog(){
    courseName = "";
    textBook = "";
    numStudents = 0;
}

Course::Course(string courseNameParam, string textBookParam, int numStudentsParam) : CourseCatalog(courseNameParam){
    courseName = courseNameParam;
    textBook = textBookParam;
    numStudents = numStudentsParam;
}

string Course::getCourseName(){
    return courseName;
}

void Course::setCourseName(string newCourseName){
    courseName = newCourseName;
}

string Course::getTextBook(){
    return textBook;
}

void Course::setTextBook(string newTextBook){
    textBook = newTextBook;
}

int Course::getNumStudents(){
    return numStudents;
}

void Course::setNumStudents(int newNumStudents){
    numStudents = newNumStudents;
}

void Course::displayCourse(){
    cout << "Course name: " << courseName << endl;
    cout << "Textbook: " << textBook << endl;
    cout << "Number of students enrolled: " << numStudents << endl;
}

void Course::increaseEnrollment(int newNumStudents) {
    numStudents += newNumStudents;
}

int Course::compareCourse(Course otherCourse){
    if (courseName < otherCourse.getCourseName()){
        return -1;
    }
    else if (courseName > otherCourse.getCourseName()){
        return 1;
    }
    else {
        if (textBook < otherCourse.getTextBook()){
            return -1;
        }
        else if (textBook > otherCourse.getTextBook()){
            return 1;
        }
        else {
            if (numStudents < otherCourse.getNumStudents()){
                return -1;
            }
            else if (numStudents > otherCourse.getNumStudents()){
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}