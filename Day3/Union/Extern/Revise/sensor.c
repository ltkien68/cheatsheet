float temperature = 25.0;
int error_count = 0;

void sensor_read() {
    temperature += 0.5;
    if (temperature > 30) {
        temperature = 25.0;
        error_count++;
    }
}