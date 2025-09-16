#ifndef studtype_H
#define studtype_H

typedef struct{
    char LName[16];
    char FName[26];
    char MI;
}Name;

typedef struct{
    Name name;
    char course[8];
    int id;
    int age;
}Studtype, *StudPtr;





#endif