#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include "CourseCatalog.h"

using namespace std;

class Course : public CourseCatalog {
    private:
        string courseName;
        string textBook;
        int numStudents;
    public:
        Course();
        Course(string, string, int);
        
        string getCourseName();
        void setCourseName(string);
        string getTextBook();
        void setTextBook(string);
        int getNumStudents();
        void setNumStudents(int);
        void displayCourse();
        void increaseEnrollment(int);
        int compareCourse(Course);
};

#endif