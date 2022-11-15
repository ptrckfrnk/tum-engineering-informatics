/*****************************************************************
* Name: Philipp Kaeß
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 7: Towers of Hanoi
* File: hanoi.h
* File type: Template file
*****************************************************************/

//DO NOT CHANGE ANYTHING IN THIS FILE

#ifndef HANOI_H
#define HANOI_H
char *allocate_trace(int disks);
void move(int disks, char source, char target, char helper, char *trace);
int *write(char *array, char source, char target);



#endif //HANOI_H
