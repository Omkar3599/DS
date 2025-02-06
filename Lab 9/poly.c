#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
};

struct PolyNode* createNode(int coeff, int exp) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct PolyNode* addPolynomials(struct PolyNode* poly1, struct PolyNode* poly2) {
    struct PolyNode* result = NULL;
    struct PolyNode** lastPtrRef = &result;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            *lastPtrRef = createNode(poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            *lastPtrRef = createNode(poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int newCoeff = poly1->coeff + poly2->coeff;
            if (newCoeff != 0) {
                *lastPtrRef = createNode(newCoeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    while (poly1 != NULL) {
        *lastPtrRef = createNode(poly1->coeff, poly1->exp);
        poly1 = poly1->next;
        lastPtrRef = &((*lastPtrRef)->next);
    }

    while (poly2 != NULL) {
        *lastPtrRef = createNode(poly2->coeff, poly2->exp);
        poly2 = poly2->next;
        lastPtrRef = &((*lastPtrRef)->next);
    }

    return result;
}

void printPolynomial(struct PolyNode* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct PolyNode* inputPolynomial() {
    struct PolyNode* poly = NULL;
    struct PolyNode** lastPtrRef = &poly;
    int n, coeff, exp;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        *lastPtrRef = createNode(coeff, exp);
        lastPtrRef = &((*lastPtrRef)->next);
    }
    return poly;
}

int main() {
    printf("Input first polynomial:\n");
    struct PolyNode* poly1 = inputPolynomial();

    printf("Input second polynomial:\n");
    struct PolyNode* poly2 = inputPolynomial();

    struct PolyNode* result = addPolynomials(poly1, poly2);

    printf("Resulting Polynomial: ");
    printPolynomial(result);

    return 0;
}
