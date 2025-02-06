#include <stdio.h>

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringConcat(char dest[], char src[]) {
    int i = 0, j = 0;
    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i++] = src[j++];
    }
    dest[i] = '\0';
}

int stringCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

void insertSubstring(char str[], char sub[], int pos) {
    int i = stringLength(str);
    int j = 0;
    while (i >= pos) {
        str[i + stringLength(sub)] = str[i];
        i--;
    }
    i = pos;
    while (sub[j] != '\0') {
        str[i++] = sub[j++];
    }
}

void deleteSubstring(char str[], int start, int length) {
    int i = start;
    while (str[i + length] != '\0') {
        str[i] = str[i + length];
        i++;
    }
    str[i] = '\0';
}

int main() {
    char str1[100], str2[100], sub[100];
    int pos, start, length;

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[stringLength(str1) - 1] = '\0';

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[stringLength(str2) - 1] = '\0';

    printf("Length of the first string: %d\n", stringLength(str1));

    stringConcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    int cmp = stringCompare(str1, str2);
    if (cmp == 0) {
        printf("Strings are equal.\n");
    } else if (cmp < 0) {
        printf("First string is less than second string.\n");
    } else {
        printf("First string is greater than second string.\n");
    }

    printf("Enter substring to insert: ");
    fgets(sub, sizeof(sub), stdin);
    sub[stringLength(sub) - 1] = '\0';
    printf("Enter position to insert substring: ");
    scanf("%d", &pos);
    insertSubstring(str1, sub, pos);
    printf("String after insertion: %s\n", str1);

    printf("Enter position to start deletion: ");
    scanf("%d", &start);
    printf("Enter length of substring to delete: ");
    scanf("%d", &length);
    deleteSubstring(str1, start, length);
    printf("String after deletion: %s\n", str1);

    return 0;
}
