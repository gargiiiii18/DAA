#include <stdio.h>
#include <stdlib.h>

struct Fruit {
    float weight;
    float value;
};

int compare(const void *a, const void *b) {
    struct Fruit *fruitA = (struct Fruit *)a;
    struct Fruit *fruitB = (struct Fruit *)b;
    float ratio1 = fruitA->value / fruitA->weight;
    float ratio2 = fruitB->value / fruitB->weight;
    return ratio2 - ratio1;
}

float maxNutrition(float capacity, struct Fruit fruits[], int n) {
    int i;
     float totalValue = 0;
    qsort(fruits, n, sizeof(struct Fruit), compare);
    for (i = 0; i < n; i++) {
        if (capacity >= fruits[i].weight) {
            totalValue += fruits[i].value;
            capacity -= fruits[i].weight;
        } else {
            float fraction = capacity / fruits[i].weight;
            totalValue += fruits[i].value * fraction;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n;
    float capacity;
    struct Fruit fruits[100]; // Fixed-size array for Turbo C
    int i; // declare i here
    clrscr();
    printf("Enter the number of fruits: ");
    scanf("%d", &n);
    
    printf("\nEnter the weight and nutritional value of each fruit:\n");
    for (i = 0; i < n; i++) {
        printf("Weight and Nutritional Value of fruit %d: ", i + 1);
        scanf("%f %f", &fruits[i].weight, &fruits[i].value);
    }
    
    printf("\nEnter the capacity of the backpack: ");
    scanf("%f", &capacity);
    
    printf("\nMaximum total nutritional value: %.2f\n", maxNutrition(capacity, fruits, n));
    getch();
    
    return 0;
}
