#include <lab4.h>


void input(int *var, int min, int max, char *string) {
    printf("%s", string);
    while (!scanf("%d", var) || (*var > max && max != INT_MAX) ||
           (*var < min && min != INT_MIN) || getchar() != '\n') {
        printf("Wrong input! Enter again:");
        rewind(stdin);
    }
}

void input_string(char **str) {
    char c;
    int size = 1;
    *str = calloc(1, 1);
    while ((c = getchar()) != '\n') {
        (*str) = realloc(*str, size * sizeof(char));
        (*str)[size - 1] = c;
        size++;
    }
    (*str) = realloc(*str, size * sizeof(char));
    (*str)[size - 1] = '\0';

};

void printSeries(const TVSeries series) {
    printf("Name: %s\n", series.name);
    printf("Number of episodes: %d\n", series.numEpisodes);
    printf("Number of seasons: %d\n", series.numSeasons);
    printf("Release date: %s\n", series.releaseDate.date);
}

int validateDate(const char *dateStr) {
    if (strlen(dateStr) != 10 || dateStr[2] != '.' || dateStr[5] != '.') {
        return false;
    }

    char *endPtr;
    long day = strtol(dateStr, &endPtr, 10);
    if (*endPtr != '.') {
        return false;
    }
    long month = strtol(endPtr + 1, &endPtr, 10);
    if (*endPtr != '.') {
        return false;
    }
    long year = strtol(endPtr + 1, &endPtr, 10);

    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2100) {
        return false;
    }

    return true;
}


void addSeries(TVSeries **arr, int *len, int numEpisodes, char *name, Date releaseDate, int numSeasons) {
    TVSeries newSeries = {numEpisodes, name, releaseDate, numSeasons};
    (*arr) = realloc((*arr), ((*len) + 1) * sizeof(TVSeries));
    (*arr)[(*len)] = newSeries;
    (*len)++;
}


void inputSeries(TVSeries **arr, int *len) {
    int choice = 0;
    char *name;
    Date releaseDate;
    int numEpisodes, numSeasons;

    while (true) {
        input(&choice, 0, 1, "1.Enter one more TV series.\n0.Stop\n");
        if (choice == 0) {
            return;
        }
        printf("Enter name of series:");
        input_string(&name);
        do {
            printf("Enter release date(day.month.year):");
            scanf("%s",releaseDate.date);
        } while (!(validateDate(releaseDate.date)));
        input(&numSeasons, 1, 100, "Enter num of seasons:");
        input(&numEpisodes, 1, 1000, "Enter num of episodes:");
        addSeries(arr, len, numEpisodes, name, releaseDate, numSeasons);
    }
}

void printAllSeries(TVSeries *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("-------------------\n");
        printSeries(arr[i]);
        printf("-------------------\n");
    }
}

void removeSeries(TVSeries **arr, int *len, const char *date) {
    for (int i = (*len) - 1; i >= 0; i--) {
        if (!strcmp((*arr)[i].releaseDate.date, date)) {
            free((*arr)[i].name);
            for (int j = i; j < (*len) - 1; j++) {
                (*arr)[j] = (*arr)[j + 1];
            }
            (*len)--;
            *arr = realloc(*arr, (*len) * sizeof(TVSeries));
            printf("\nSuccessfully deleted!\n");
        }
    }
}

void initialSeries(TVSeries **arr, int *len) {
    Date releaseSaul = {"08.02.2015"};
    Date releaseBB = {"20.01.2008"};
    Date releasePB = {"12.09.2013"};
    Date releaseQG = {"23.12.2020"};
    addSeries(arr, len, 63, "Better call Saul", releaseSaul, 6);
    addSeries(arr, len, 70, "Breaking Bad", releaseBB, 5);
    addSeries(arr, len, 20, "Peaky Blinders", releasePB, 1);
    addSeries(arr, len, 7, "The Queen's Gambit", releaseQG, 1);
}

TVSeriesArray findSeriesWithFewerSeasons(TVSeries *seriesArray, int numSeries) {
    int minSeasons = seriesArray[0].numSeasons;
    for (int i = 1; i < numSeries; i++) {
        if (seriesArray[i].numSeasons < minSeasons) {
            minSeasons = seriesArray[i].numSeasons;
        }
    }

    int count = 0;
    for (int i = 0; i < numSeries; i++) {
        if (seriesArray[i].numSeasons == minSeasons) {
            count++;
        }
    }

    TVSeries *minSeriesArray = (TVSeries *) malloc(count * sizeof(TVSeries));

    int j = 0;
    for (int i = 0; i < numSeries; i++) {
        if (seriesArray[i].numSeasons == minSeasons) {
            minSeriesArray[j] = seriesArray[i];
            j++;
        }
    }
    TVSeriesArray result = {minSeriesArray, count};
    return result;
}

void task1(TVSeries *arr, int len) {
    TVSeriesArray newArray = findSeriesWithFewerSeasons(arr, len);
    printAllSeries(newArray.arr, newArray.len);
}

void task2(TVSeries **arr, int *len) {
    char* str = malloc(1);
    do{
        printf("Enter release date to delete(day.month.year):");
        input_string(&str);
    } while(!validateDate(str));
    removeSeries(arr, len, str);
}

void menu(TVSeries **arr, int *len) {
    int choice;
    while (1) {
        printf("\n------------------------------\n");
        printf("1.Show current series\n2.Add new series");
        printf("\n3.Show series with fewer seasons\n4.Remove series with special date\n0.Exit");
        printf("\n------------------------------\n\n");
        input(&choice, 0, 4, "Your Choice:");
        switch (choice) {
            case 0:
                free(*arr);
                printf("see you");
                exit(0);
            case 1:
                printAllSeries(*arr, *len);
                break;
            case 2:
                inputSeries(arr, len);
                break;
            case 3:
                task1(*arr, *len);
                break;
            case 4:
                task2(arr, len);
                break;
            default:
                break;
        }
    }
}