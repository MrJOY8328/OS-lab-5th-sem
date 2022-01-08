#include <stdio.h>

void findCT(int n, int AT[], int BT[], int CT[])
{
    CT[0] = BT[0];
    for (int i = 1; i < n; i++)
    {
        CT[i] = (CT[i - 1] >= AT[i]) ? CT[i - 1] + BT[i] : AT[i] + BT[i];
    }
}

void findTAT(int n, int CT[], int AT[], int TAT[])
{
    for (int i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
    }
}

void findWT(int n, int TAT[], int BT[], int WT[])
{
    for (int i = 0; i < n; i++)
    {
        WT[i] = TAT[i] - BT[i];
    }
}

void findFCFS(int n,int pid[], int AT[], int BT[])
{
    int CT[n], TAT[n], WT[n];
    findCT(n, AT, BT, CT);
    findTAT(n, CT, AT, TAT);
    findWT(n, TAT, BT, WT);

    int total_WT = 0, total_TAT = 0;

    printf("\nAT  = Arival Time \nBT  = BrustTime \nCT  = Completion Time \nTAT = Turn Around Time \nWT  = Waiting Time\n\n");
    printf("Process\tAT \tBT \tCT \tTAT \tWT \n\n");
    for (int i = 0; i < n; i++)
    {
        total_WT += WT[i];
        total_TAT += TAT[i];
        printf(" %d \t%d \t%d \t%d \t%d \t%d \n", pid[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
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
    int pid[n], AT[n], BT[n];
    printf("Enter prosess id, arival time and burst time\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &pid[i], &AT[i], &BT[i]);
    }
    findFCFS(n, pid, AT, BT);
    return 0;
}