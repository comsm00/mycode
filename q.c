#include <stdio.h>

int main() {
    int n = 4;
    int tq = 2;

    int at[4] = {0, 1, 2, 3};
    int bt[4] = {10, 5, 8, 6};
    int rt[4], ct[4], tat[4], wt[4];
    int visited[4] = {0};
    char p[4][3] = {"P1", "P2", "P3", "P4"};

    int queue[100];
    int front = 0, rear = 0;
    int time = 0, completed = 0;
    float avgTAT = 0, avgWT = 0;

    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }

    queue[rear++] = 0;
    visited[0] = 1;

    while (completed < n) {
        if (front == rear) {
            time++;
            for (int i = 0; i < n; i++) {
                if (at[i] <= time && rt[i] > 0 && visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int i = queue[front++];

        int exec;
        if (rt[i] > tq)
            exec = tq;
        else
            exec = rt[i];

        time += exec;
        rt[i] -= exec;

        for (int j = 0; j < n; j++) {
            if (at[j] <= time && rt[j] > 0 && visited[j] == 0) {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        if (rt[i] > 0) {
            queue[rear++] = i;
        } else {
            ct[i] = time;
            completed++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgTAT += tat[i];
        avgWT += wt[i];
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    avgTAT /= n;
    avgWT /= n;

    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);
    printf("Average Waiting Time = %.2f\n", avgWT);

    return 0;
}#include <stdio.h>

#define MAX_P 10
#define MAX_R 10

void calculateNeed(int n, int m, int max[MAX_P][MAX_R], int alloc[MAX_P][MAX_R], int need[MAX_P][MAX_R]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

int isSafe(int n, int m, int alloc[MAX_P][MAX_R], int need[MAX_P][MAX_R], int avail[MAX_R], int safeSeq[MAX_P]) {
    int work[MAX_R], finish[MAX_P] = {0};
    int count = 0;

    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int ok = 1;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        ok = 0;
                        break;
                    }
                }

                if (ok) {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
            return 0;
    }

    return 1;
}

int main() {
    int n, m, pno;
    int alloc[MAX_P][MAX_R], max[MAX_P][MAX_R], need[MAX_P][MAX_R];
    int avail[MAX_R], req[MAX_R], safeSeq[MAX_P];

    printf("Enter number of processes and resources: ");
    scanf("%d%d", &n, &m);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    calculateNeed(n, m, max, alloc, need);

    if (isSafe(n, m, alloc, need, avail, safeSeq)) {
        printf("Safe sequence: ");
        for (int i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
    } else {
        printf("System is not safe\n");
        return 0;
    }

    printf("Enter process number: ");
    scanf("%d", &pno);

    printf("Enter request:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &req[i]);

    for (int i = 0; i < m; i++) {
        if (req[i] > need[pno][i]) {
            printf("Error: Request > Need\n");
            return 0;
        }
        if (req[i] > avail[i]) {
            printf("Error: Request > Available\n");
            return 0;
        }
    }

    for (int i = 0; i < m; i++) {
        avail[i] -= req[i];
        alloc[pno][i] += req[i];
        need[pno][i] -= req[i];
    }

    if (isSafe(n, m, alloc, need, avail, safeSeq)) {
        printf("Request granted\nNew Safe sequence: ");
        for (int i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
    } else {
        printf("Request denied (unsafe)\n");
    }

    return 0;
}
