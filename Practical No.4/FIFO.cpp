#include <iostream>
using namespace std;

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frame[3] = {-1, -1, -1};  // Fixed frame size of 3, initialized to -1
    int nextFrame = 0, pageFaults = 0;

    for (int i = 0; i < n; i++) {
        bool pageFound = false;

        // Check if page is already in frame
        for (int j = 0; j < 3; j++) {
            if (frame[j] == pages[i]) {
                pageFound = true;
                cout << "Page hit: " << pages[i] << endl;
                break;
            }
        }

        // If page not found, it's a page fault
        if (!pageFound) {
            frame[nextFrame] = pages[i];           // Replace page using FIFO order
            nextFrame = (nextFrame + 1) % 3;       // Update nextFrame index
            pageFaults++;
            cout << "Page fault: " << pages[i] << endl;
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl;
    return 0;
}