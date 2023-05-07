#include <stdio.h>
#include <string.h>
#include "IsraeliQueue.h"
#include "HackEnrollment.h"

int friend1(void* a, void* b){
    int aa = *(int*)a;
    int bb = *(int*)b;
    return aa+bb;

}
int friend2(void* a, void* b)
{
    int aa = *(int*)a;
    int bb = *(int*)b;
    return aa;
}
int friend3(void* a, void* b)
{
    int aa = *(int*)a;
    int bb = *(int*)b;
    if(aa == bb){
        return 10;
    }

    return 4;
}

int friend4(void* a, void* b){
    int aa = *(int*)a;
    int bb = *(int*)b;
    return bb;

}
int friend5(void* a, void* b){
    int aa = *(int*)a;
    int bb = *(int*)b;
    return bb-aa;

}
int friend6(void* a, void* b){
    int aa = *(int*)a;
    int bb = *(int*)b;
    return bb-2*aa;

}

int compare(void* a, void* b){
    int aa = *(int*)a;
    int bb = *(int*)b;
    if(aa == bb){
        return 1;
    }

    return 0;
}

int main(int argc, char** argv)//TODO: check test 6,8,9,10
{
    if(argc!=6 && argc!=7)
    {
        printf("Usage: %s [-i] <students file> <courses file> <hackers file> <queues file> <output file> \n", argv[0]);
        return 1;
    }
    char* flag = argv[1];

    char* students_file = (argc==6) ? argv[1] : argv[2];
    char* courses_file = (argc==6) ? argv[2] : argv[3];
    char* hackers_file = (argc==6) ? argv[3] : argv[4];
    char* queues_file = (argc==6) ? argv[4] : argv[5];
    char* output_file = (argc==6) ? argv[5] : argv[6];

    FILE* students = fopen(students_file, "r");
    FILE* courses = fopen(courses_file, "r");
    FILE* hackers = fopen(hackers_file, "r");
    FILE* queues = fopen(queues_file, "r");
    FILE* out = fopen(output_file, "w");

    if(students == NULL || courses == NULL || hackers == NULL || queues == NULL || out == NULL)
    {
        printf("Error opening files\n");
        return 0;
    }

    EnrollmentSystem sys = createEnrollment(students, courses, hackers);
    readEnrollment(sys, queues);
    hackEnrollment(sys, out);
    fclose(students);
    fclose(courses);
    fclose(hackers);
    fclose(queues);
    return 0;
}
//FILE* courses = fopen("C:\\Users\\lasko\\CLionProjects\\ex1_mtm\\ExampleTest\\courses.txt", "r");
//FILE* students = fopen("C:\\Users\\lasko\\CLionProjects\\ex1_mtm\\ExampleTest\\students.txt", "r");
//FILE* hackers = fopen("C:\\Users\\lasko\\CLionProjects\\ex1_mtm\\ExampleTest\\hackers.txt", "r");
//FILE* queues = fopen("C:\\Users\\lasko\\CLionProjects\\ex1_mtm\\ExampleTest\\queues.txt", "r");

//if(students == NULL || courses == NULL || hackers == NULL){
//return 0;
//}
//EnrollmentSystem sys = createEnrollment(students, courses, hackers);
//readEnrollment(sys, queues);
//fclose(students);
//fclose(courses);
//fclose(hackers);
//fclose(queues);