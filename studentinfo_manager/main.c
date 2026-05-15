#include <stdio.h>
#include <stdlib.h>


typedef struct StudentNode{
    char firstName[50];
    char lastName[50];
    int roll;
    float cgpa;
    int courseId[5];
    struct StudentNode* next;
} Student;

int main(){
    Student* head = NULL;
    	
    return 0;
}

Student* addStudent(){
    Student* new_student = (Student*) malloc(sizeof(Student));
    if (new_student == NULL){
	printf("Error: System is out of memory");
   	return NULL;
    }

   printf("First Name: ");
   scanf("%49s", new_student->firstName);
   
   printf("Last Name: ");
   scanf("%49s", new_student->lastName);

   printf("Roll Number: ");
   scanf("%d", &new_student->roll);

   printf("CGPA: ");
   scanf("%f", &new_student->cgpa); 
}

