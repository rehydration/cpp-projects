/*
Name: Nathan Zhou
Date: 10/4/22

Uses a vector pointer and a Student struct to store a list of students containing first and last name,
student id, and GPA. Allows the user to add and delete students and print the list.

 */

#include <iostream>
#include <cstring>
#include <vector>

struct Student { //student struct
  char fname[10], lname[10];
  int id;
  float gpa;
};

void add_student(std::vector<Student*>* list) { //adds a new student to the list, taking in first/last name, id, gpa
  Student* student = new Student(); //initialize Student pointer
  std::cout << "Enter the student's first name:\n";
  std::cin >> student->fname;
  std::cout << "Enter the student's last name:\n";
  std::cin >> student->lname;
  std::cout << "Enter the student's student ID:\n";
  std::cin >> student->id;
  std::cout << "Enter the student's GPA:\n";
  std::cin >> student->gpa;
  (*list).push_back(student); //adds Student pointer to back of vector
}

void print_students(std::vector<Student*>* list) { //prints all students in the list
  for (std::vector<Student*>::iterator it = (*list).begin(); it != (*list).end(); ++it) {
    std::cout << (*it)->fname << " " << (*it)->lname << ", " << (*it)->id << ", " << (*it)->gpa << "\n";
  }
}

void delete_student(std::vector<Student*>* list) { //takes in a student id, then deletes the student from the list
  std::cout << "Enter the student id to be deleted:\n";
  int id;
  std::cin >> id;

  for (std::vector<Student*>::iterator it = (*list).begin();; it != (*list).end()) { //iterate through whole list
    if ((*it)->id == id) { //matching id
      delete *it; //delete pointer
      (*list).erase(it); //delete element from vector
      return;      
    }
    else ++it; //move up iterator
  }
}

int main() {
  bool running = true;
  char input[10];
  std::vector<Student*>* list; //pointer to vector of struct pointers
  
  while (running) {
    std::cin >> input; //take in command
    if (strncmp(input, "ADD", 3) == 0) {
      add_student(list);
    }
    if (strncmp(input, "PRINT", 5) == 0) {
      print_students(list);
    }
    if (strncmp(input, "DELETE", 6) == 0) {
      delete_student(list);
    }
    if (strncmp(input, "QUIT", 4) == 0) running = false;
  }

  return 0;
}
