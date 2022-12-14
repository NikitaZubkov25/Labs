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
#endif //LAB5_STRINGS_H
