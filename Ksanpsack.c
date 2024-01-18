#include <stdio.h>
 void knapsack(int n, float weight[], float profit[], float ksnapsack_capacity)
{
    float x[20], tp = 0;
    int i, j, k;
    k = ksnapsack_capacity;
    for (i = 0; i < n; i++)
        x[i] = 0.0;
    for (i = 0; i < n; i++)
    {
        if (weight[i] > k)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            k = k - weight[i];
        }
    }
    if (i < n)
        x[i] = k / weight[i];
    tp = tp + (x[i] * profit[i]);
    printf("\nThe result vector is:- ");
    for (i = 0; i < n; i++)
        printf("%f\t", x[i]);
    printf("\nMaximum profit is:- %f", tp);
}
int main()
{
    float weight[20], profit[20], ksnapsack_capacity;
    int num_25, i, j;
    float ratio[20], temp;
    printf("\nEnter the no. of objects:- ");
    scanf("%d", &num_25);
    printf("\nEnter the waight and profits of each object:- ");
    for (i = 0; i < num_25; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
    }
    printf("\nEnter the ksnapsack_capacity of knapsack:- ");
    scanf("%f", &ksnapsack_capacity);
    for (i = 0; i < num_25; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }
    for (i = 0; i < num_25; i++)
    {
        for (j = i + 1; j < num_25; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    knapsack(num_25, weight, profit, ksnapsack_capacity);
    return (0);
}