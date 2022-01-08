#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortAccoordingPriority(int n, int pid[], int BT[], int PP[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (PP[i] < PP[j])  //higher number higher priority   make it > for opposite
            {
                swap(&PP[i], &PP[j]);
                swap(&BT[i], &BT[j]);
                swap(&pid[i], &pid[j]);
            }
        }
    }
}

void findTAT(int n, int BT[], int TAT[])
{
    TAT[0] = BT[0];
    for (int i = 1; i < n; i++)
    {
        TAT[i] = TAT[i - 1] + BT[i];
    }
}

void findWT(int n, int TAT[], int BT[], int WT[])
{
    for (int i = 0; i < n; i++)
    {
        WT[i] = TAT[i] - BT[i];
    }
}

void findPriorityScheduling(int n, int pid[], int BT[], int PP[])
{
    int TAT[n], WT[n];
    sortAccoordingPriority(n, pid, BT, PP);
    findTAT(n, BT, TAT);
    findWT(n, TAT, BT, WT);

    int total_WT = 0, total_TAT = 0;
    printf("\nBT  = BrustTime \nTAT = Turn Around Time \nWT  = Waiting Time \nPP  = Process Priority\n\n");
    printf("Process\tPP \tBT \tTAT \tWT \n\n");
    for (int i = 0; i < n; i++)
    {
        total_WT += WT[i];
        total_TAT += TAT[i];
        printf(" %d \t%d \t%d \t%d \t%d\n", pid[i], PP[i], BT[i], TAT[i], WT[i]);
    }

    float avg_WT = (float)total_WT / (float)n;
    float avg_TAT = (float)total_TAT / (float)n;

    printf("\nAverage waiting time = %.2f\n", avg_WT);
    printf("Average turn around time = %.2f\n\n", avg_TAT);
}

int main()
{
    int n;
    printf("Enter the number of process : ");
    scanf("%d", &n);
    int pid[n], BT[n], PP[n];
    printf("Enter prosess id, burst time and proiority\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &pid[i], &BT[i], &PP[i]);
    }
    findPriorityScheduling(n, pid, BT, PP);
    return 0;
}