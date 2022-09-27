#include <iostream>

using namespace std;

class Student 
{
	public:
		int age;
		string name;
};

Student createStudent(int age, string name)
{
	Student student;
	
	student.age = age;
	student.name = name;

	cout << "Student age: " << student.age << endl;
	cout << "Student name: " << student.name << endl;
	return (student);	
}

int main()
{
	Student s1;

	s1 = createStudent(13, "Hoho");

	cout << "The same student age: " << s1.age << endl;
	cout << "The same student name: " << s1.name << endl;
	return (0);
}
