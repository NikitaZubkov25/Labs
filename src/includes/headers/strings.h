//
// Created by Katerina on 13.12.2022.
//

#ifndef LAB5_STRINGS_H
#define LAB5_STRINGS_H

int stringLength(const char* str, int start, int flag);

char* printFrom(const char* str, int start);

void findLongestWord(const char *str);

int strCompare(const char* str,const char* str2, int startFrom);

int findSimilarWord(const char *str, const char *str2);

void deleteWord(char* str, int start);

int findLengthOfLowest(char* str);

void swapForString(char **arr, int first, int second);

void HoareMethodForStrings(char** arr,int first,int last);

char** allocateStringArray(int argc, char** argv);

void printStringArray(int argc, char** arr);

#endif //LAB5_STRINGS_H
