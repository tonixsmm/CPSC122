#include "Course.h"

int main(){
    Course c1;
    Course c2("CPSC122", "Gaddis", 28);

    cout << c2.getCourseName() << endl;

    c2.displayCourse();

    c2.increaseEnrollment(1);

    Course * cpscCourses = new Course[20];

    for (int i = 0; i < 20; i++){
        cpscCourses[i].displayCourse();
    }
}