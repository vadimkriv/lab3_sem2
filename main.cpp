#include <iostream>
#include <string>
using namespace std;
class School {
protected:
    string name;
    int numStudents;
public:
    School(const string& name, int numStudents) : name(name), numStudents(numStudents) {}
    virtual void printInfo() {
        cout << "School Name: " << name << endl;
        cout << "Number of Students: " << numStudents << endl;
    }
};
class SpecializedSchool : public School {
private:
    string specialization;
public:
    SpecializedSchool(const string& name, int numStudents, const string& specialization)
        : School(name, numStudents), specialization(specialization) {}
    void printInfo() override {
        School::printInfo();
        cout << "Specialization: " << specialization << endl;
    }
};
int main() {
    School school("ABC School", 100);
    SpecializedSchool specializedSchool("XYZ School", 50, "Science");
    school.printInfo();
    specializedSchool.printInfo();
    School* schoolPtr = &school;
    schoolPtr->printInfo();
    schoolPtr = &specializedSchool;
    schoolPtr->printInfo();
    return 0;
}
