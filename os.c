#include <stdio.h>
#include <string.h>

int main() {
    int n, i, q;
    char pid[20][10];
    int at[20], bt[20], rt[20];
    int ct[20], wt[20], tat[20];
    int time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%s %d %d", pid[i], &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    scanf("%d", &q);

    while(completed < n) {
        int done = 1;

        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time) {
                done = 0;

                if(rt[i] > q) {
                    time += q;
                    rt[i] -= q;
                }
                else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    completed++;
                }
            }
        }

        if(done)
            time++;
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("Waiting Time:\n");
    for(i = 0; i < n; i++)
        printf("%s %d\n", pid[i], wt[i]);

    printf("Turnaround Time:\n");
    for(i = 0; i < n; i++)
        printf("%s %d\n", pid[i], tat[i]);

    printf("Average Waiting Time: %.2f\n", avg_wt/n);
    printf("Average Turnaround Time: %.2f\n", avg_tat/n);

    return 0;
}
