#include <iostream>
using namespace std;

#define MAX_FRAMES 10 

void LRUPageReplacement(int pages[], int n, int frameSize) {
    int frame[MAX_FRAMES]; 
    int pageFaults = 0;  
    
    for (int i = 0; i < frameSize; i++) {
        frame[i] = -1; 
    }

    for (int i = 0; i < n; i++) {
        bool pageFound = false;
        int lruIndex = -1;      
        int lruCounter = 0;     

        for (int j = 0; j < frameSize; j++) {
            if (frame[j] == pages[i]) {
                pageFound = true; 
                break;
            }
        }

        if (!pageFound) {
            
            for (int j = 0; j < frameSize; j++) {
                if (frame[j] == -1) {
                    lruIndex = j;
                    break;
                }
                if (j == frameSize - 1) {
                    lruIndex = lruCounter; 
                }
                lruCounter++;
            }
            frame[lruIndex] = pages[i]; 
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
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 20, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frameSize = 3;

    LRUPageReplacement(pages, n, frameSize);

    return 0;
}
