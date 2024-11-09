#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int bt[n], priority[n], wt[n], tat[n];
    int avg_wt = 0, avg_tat = 0;

    // Input burst time and priority for each process
    cout << "Enter burst time and priority for each process:\n";
    for(int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> bt[i];
        cout << "Process " << i + 1 << " Priority: ";
        cin >> priority[i];
    }

    // Bubble sort to arrange processes by priority (lower number = higher priority)
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(priority[j] > priority[j + 1]) {
                // Swap priority
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time
    wt[0] = 0; // First process has 0 waiting time
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Display results with process IDs based on sorted order
    cout << "Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << priority[i] << "\t\t" << bt[i] 
             << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Display average waiting and turnaround times
    cout << "Average Waiting Time: " << (float)avg_wt / n << "\n";
    cout << "Average Turnaround Time: " << (float)avg_tat / n << "\n";

    return 0;
}
