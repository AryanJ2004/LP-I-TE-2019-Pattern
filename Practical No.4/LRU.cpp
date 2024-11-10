#include <iostream>
using namespace std;

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int frameSize = 3;
    int n = sizeof(pages) / sizeof(pages[0]);
    int frame[frameSize] = {-1, -1, -1};  // Initialize frame with -1 (empty)
    int lastUsed[frameSize] = {0};         // Array to track last used index of pages
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        bool pageFound = false;

        // Check if the page is already in the frame (hit)
        for (int j = 0; j < frameSize; j++) {
            if (frame[j] == pages[i]) {
                pageFound = true;
                cout << "Page hit: " << pages[i] << endl;
                lastUsed[j] = i;  // Update the recent access index of the page
                break;
            }
        }

        // If page not found, handle page fault
        if (!pageFound) {
            pageFaults++;
            int lruIndex = -1;
            int minIndex = n;  // Set to a large number initially

            // Find the least recently used (LRU) page
            for (int j = 0; j < frameSize; j++) {
                if (frame[j] == -1) {  // Empty frame slot
                    lruIndex = j;
                    break;
                }
                if (lastUsed[j] < minIndex) {
                    minIndex = lastUsed[j];
                    lruIndex = j;
                }
            }

            // Replace the LRU page
            frame[lruIndex] = pages[i];
            lastUsed[lruIndex] = i;  // Update the last used index
            cout << "Page fault: " << pages[i] << endl;
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl;
    return 0;
}
