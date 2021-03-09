/*
Задача 18:
Направете сериализация и десериализация на структурата
typedef struct Person{
char name[20];
int age;
char gender;
}t_person;
 в XML формат по показания в лекцията начин.
 */

#include <stdio.h>
#include <stdlib.h>

static const char *FORMAT_PERSON_IN = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<person>\n<name>%s</name>\n<age>%d</age>\n<gender>%c</gender>\n</person>\n";
static const char *FORMAT_PERSON_OUT = "<person>\n<name>%s</name>\n<age>%d</age>\n<gender>%c</gender>\n</person>\n";
typedef struct Person{
    char name[20];
    int age;
    char gender;
} t_person;

void xmlParser(t_person person1, t_person person2);

int main(void){
    t_person d = {
        .name = "Dido",
        .age = 37,
        .gender = 'M'
    };
    t_person d2;
    xmlParser(d, d2);
    
    return 0;
}

void xmlParser(t_person person1, t_person person2){
    FILE *fp;
    fp = fopen("people.xml", "w+" );
    if(NULL == fp){
        printf("Failed to open fail.\n");
        exit(1);
    }
    fprintf(fp, FORMAT_PERSON_OUT, person1.name, person1.age, person1.gender);
    fseek(fp, 0, SEEK_SET);
    fscanf(fp, FORMAT_PERSON_IN, person2.name, &person2.age, &person2.gender);
    printf(FORMAT_PERSON_OUT, person2.name, person2.age, person2.gender);
    fclose(fp);
}