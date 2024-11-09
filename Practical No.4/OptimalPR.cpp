#include <iostream>
using namespace std;
#define MAX_FRAMES 10 

void OptimalPageReplacement(int pages[], int n, int frameSize) {
    int frame[MAX_FRAMES]; 
    int pageFaults = 0;    
    for (int i = 0; i < frameSize; i++) {
        frame[i] = -1; 
    }

    for (int i = 0; i < n; i++) {
        bool pageFound = false; 


        for (int j = 0; j < frameSize; j++) {
            if (frame[j] == pages[i]) {
                pageFound = true; 
                break;
            }
        }

        if (!pageFound) {
            int replaceIndex = -1; 
            int farthest = -1;  

            for (int j = 0; j < frameSize; j++) {
                if (frame[j] == -1) {
                    replaceIndex = j;
                    break;
                }

                int k;
                for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) {
                        break;
                    }
                }

                if (k == n) {
                    replaceIndex = j;
                    break;
                }

                if (k > farthest) {
                    farthest = k;
                    replaceIndex = j;
                }
            }

            frame[replaceIndex] = pages[i];
            pageFaults++;
            cout << "Page fault: " << pages[i] << endl;
        } else {
            cout << "Page hit: " << pages[i] << endl;
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl;
}

int main() {
    /* You can take input for pages and framesize from user and pass it to the function accordingly*/
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2,0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frameSize = 3;

    OptimalPageReplacement(pages, n, frameSize);

    return 0;
}