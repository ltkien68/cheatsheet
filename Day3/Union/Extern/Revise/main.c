#include <stdio.h>
#include "sensor.h"

int main() {
    for (int i = 0; i < 11; i++) {
        printf("%d:\n", i);
        sensor_read();
        printf("Temperature = %0.1f\n", temperature);
        printf("Error count = %d\n", error_count);
    }

    return 0;
}