//knapsack problem
int main() {
    int itemCount = 5;
    int itemCosts[5] = {12, 1, 2, 1, 4};
    int itemValues[5] = {4, 2, 2, 1, 10};
    int maxWeight = 15;
    int currentWeight = maxWeight;
    float totalValue = 0;
    int itemsUsed[5] = {0};

    for (int i = 0; i < itemCount && currentWeight > 0; i++) {
        int bestItemIndex = -1;
        float bestValueRatio = 0;

        for (int j = 0; j < itemCount; j++) {
            if (!itemsUsed[j]) {
                float valueRatio = (float)itemValues[j] / itemCosts[j];
                if (valueRatio > bestValueRatio) {
                    bestValueRatio = valueRatio;
                    bestItemIndex = j;
                }
            }
        }

        if (bestItemIndex == -1) break;

        itemsUsed[bestItemIndex] = 1;
        currentWeight -= itemCosts[bestItemIndex];
        totalValue += itemValues[bestItemIndex];

        if (currentWeight >= 0) {
            printf("Added object %d (%d$, %dKg) completely in the bag. Space left: %d.\n",
                   bestItemIndex + 1, itemValues[bestItemIndex], itemCosts[bestItemIndex], currentWeight);
        } else {
            int percentage = (int)((1 + (float)currentWeight / itemCosts[bestItemIndex]) * 100);
            totalValue -= itemValues[bestItemIndex];
            totalValue += (1 + (float)currentWeight / itemCosts[bestItemIndex]) * itemValues[bestItemIndex];
            printf("Added %d%% (%d$, %dKg) of object %d in the bag.\n",
                   percentage, itemValues[bestItemIndex], itemCosts[bestItemIndex], bestItemIndex + 1);
        }
    }

    printf("Filled the bag with objects worth %.2f$.\n", totalValue);
    return 0;
}
