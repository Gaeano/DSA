#ifndef  STUDTYPE_H
#define STUDTYPE_H


typedef struct {
    char FName[40];
    char LName[40];
    char MI;
}Name;

typedef struct {
    Name name;
    int YrLvl;
    char Course[10];
}Studtype, *StudPtr;






#endif