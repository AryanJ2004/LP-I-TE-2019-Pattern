#include <iostream>
using namespace std;

#define MAX_FRAMES 10 

void FIFOPageReplacement(int pages[], int n, int frameSize) {
    int frame[MAX_FRAMES];  
    bool pageFound;         
    int pageFaults = 0;      
    int nextFrame = 0;       


    for (int i = 0; i < frameSize; i++) {
        frame[i] = -1; 
    }

    for (int i = 0; i < n; i++) {
        pageFound = false;

        for (int j = 0; j < frameSize; j++) {
            if (frame[j] == pages[i]) {
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            frame[nextFrame] = pages[i];
            nextFrame = (nextFrame + 1) % frameSize;
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
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3,2,1,20,1,7,0,1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frameSize = 3;

    FIFOPageReplacement(pages, n, frameSize);

    return 0;
}
