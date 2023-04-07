//#include "lab3.h"
//#include "helpers.h"
//
//
//void task1(TVSeries *arr, int len) {
//    int k;
//    input(&k, 1, 100, "Input num of episodes:");
//    TVSeriesArray newArray = findSeriesWithFewEpisodes(arr, len, k);
//    printAllSeries(newArray.arr, newArray.len);
//}
//
//void task2(TVSeries **arr, int *len) {
//    char *name;
//    printf("Enter name of series you wanna delete:");
//    input_string(&name);
//    removeSeries((*arr), len, name);
//}
//
//void menu(TVSeries **arr, int *len) {
//    int choice;
//    while (1) {
//        printf("\n------------------------------\n");
//        printf("1.Show current series\n2.Add new series");
//        printf("\n3.Find series that have less than k episodes\n4.Remove series with special name\n0.Exit");
//        printf("\n------------------------------\n\n");
//        input(&choice, 0, 4, "Your Choice:");
//        switch (choice) {
//            case 0:
//                exit(0);
//            case 1:
//                printAllSeries(*arr, *len);
//                break;
//            case 2:
//                inputSeries(arr, len);
//                break;
//            case 3:
//                task1(*arr, *len);
//                break;
//            case 4:
//                task2(arr, len);
//                break;
//            default:
//                break;
//        }
//    }
//}