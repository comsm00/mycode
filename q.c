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
}
