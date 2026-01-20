#include <stdio.h>

int largestAltitude(int* gain, int gainSize) {
    int altitude = 0;
    int maxAltitude = 0;

    for (int i = 0; i < gainSize; i++) {
        altitude += gain[i];
        if (altitude > maxAltitude) {
            maxAltitude = altitude;
        }
    }

    return maxAltitude;
}

int main() {
    int gain[] = {-5, 1, 5, 0, -7};
    int gainSize = sizeof(gain) / sizeof(gain[0]);

    int result = largestAltitude(gain, gainSize);
    printf("Largest altitude: %d\n", result);

    return 0;
}
