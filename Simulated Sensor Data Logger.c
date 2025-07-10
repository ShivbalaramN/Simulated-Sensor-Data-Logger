#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // For sleep()

// Simulate sensor readings
float getTemperature() {
    return 20.0 + (rand() % 1000) / 100.0;  // 20.00 to 40.00 °C
}

float getHumidity() {
    return 30.0 + (rand() % 500) / 10.0;    // 30.0 to 90.0 %
}

int getLightIntensity() {
    return rand() % 1001;                  // 0 to 1000 Lux
}

void logData(FILE *fp, float temp, float humidity, int light) {
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strcspn(timestamp, "\n")] = 0;  // remove newline

    fprintf(fp, "%s - Temp: %.2f °C, Humidity: %.1f %%, Light: %d Lux\n",
            timestamp, temp, humidity, light);
    fflush(fp);  // Ensure it's written immediately
}

int main() {
    FILE *fp = fopen("sensor_log.txt", "a");
    if (!fp) {
        printf("Error opening file!\n");
        return 1;
    }

    srand(time(NULL)); // Seed random number generator

    printf("Simulating sensor data logging...\n");

    for (int i = 0; i < 10; i++) { // Simulate 10 readings
        float temp = getTemperature();
        float humidity = getHumidity();
        int light = getLightIntensity();

        logData(fp, temp, humidity, light);

        sleep(1); // Wait for 1 second before next reading
    }

    fclose(fp);
    printf("Sensor data logging complete. Check 'sensor_log.txt'.\n");
    return 0;
}
