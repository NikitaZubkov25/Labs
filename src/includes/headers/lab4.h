#ifndef LAB5_LAB4_H
#define LAB5_LAB4_H


#include <stdio.h>
#include <stdlib.h>
#include "string.h"

enum bool {
    false, true
};

typedef union {
    char date[11];
} Date;

typedef struct {
    int numEpisodes;
    char *name;
    Date releaseDate;
    int numSeasons;
} TVSeries;


typedef struct {
    TVSeries *arr;
    int len;
} TVSeriesArray;

void input(int *var, int min, int max, char *string);

void input_string(char **str);

void printSeries(const TVSeries series);

TVSeriesArray findSeriesWithFewerSeasons(TVSeries *seriesArray, int numSeries);

void addSeries(TVSeries **arr, int *len, int numEpisodes, char *name, Date releaseDate, int numSeasons);

void removeSeries(TVSeries **arr, int *len, const char *name);

int validateDate(const char *dateStr);

void inputSeries(TVSeries **arr, int *len);

void printAllSeries(TVSeries *arr, int len);

void initialSeries(TVSeries **arr, int *len);

void task1(TVSeries *arr, int len);

void task2(TVSeries **arr, int *len);

void menu(TVSeries **arr, int *len);

#endif //LAB5_LAB4_H
