#include <stdio.h>

typedef struct {
    int hour;
    int min;
    int sec;
} Time;

Time addTime(Time t1, Time t2) {
    Time result;
    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min + result.sec / 60;
    result.sec %= 60;
    result.hour = t1.hour + t2.hour + result.min / 60;
    result.min %= 60;
    return result;
}

Time subtractTime(Time t1, Time t2) {
    Time result;
    result.sec = t1.sec - t2.sec;
    result.min = t1.min - t2.min;
    result.hour = t1.hour - t2.hour;
    if (result.sec < 0) {
        result.sec += 60;
        result.min--;
    }
    if (result.min < 0) {
        result.min += 60;
        result.hour--;
    }
    return result;
}

void displayTime(Time t) {
    printf("Time: %02d:%02d:%02d\n", t.hour, t.min, t.sec);
}

void readTime(Time *t) {
    printf("Enter hours, minutes, and seconds:\n");
    scanf("%d %d %d", &t->hour, &t->min, &t->sec);
}

int main() {
    Time t1, t2, result;

    printf("Enter first time:\n");
    readTime(&t1);

    printf("Enter second time:\n");
    readTime(&t2);

    result = addTime(t1, t2);
    printf("Sum of times:\n");
    displayTime(result);

    result = subtractTime(t1, t2);
    printf("Difference of times:\n");
    displayTime(result);

    return 0;
}
