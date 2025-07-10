import random
import time
from datetime import datetime

# Simulate temperature sensor (20°C to 30°C)
def get_temperature():
    return round(random.uniform(20.0, 40.0), 2)

# Simulate humidity sensor (30% to 80%)
def get_humidity():
    return round(random.uniform(30.0, 90.0), 1)

# Simulate light sensor (0 to 1000 Lux)
def get_light_intensity():
    return random.randint(0, 1000)

# Log data to file with timestamp
def log_data(temp, humidity, light):
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    log_line = f"{timestamp} - Temp: {temp}°C, Humidity: {humidity}%, Light: {light} Lux"
    
    # Print to console
    print(log_line)

    # Append to file
    with open("sensor_log.txt", "a") as file:
        file.write(log_line + "\n")

# Main function
def main():
    print("Simulated Sensor Data Logger Running...\n")

    for _ in range(10):  # Simulate 10 readings
        temp = get_temperature()
        humidity = get_humidity()
        light = get_light_intensity()

        log_data(temp, humidity, light)
        time.sleep(1)  # 1-second interval

    print("\nLogging complete. Check 'sensor_log.txt'.")

if __name__ == "__main__":
    main()
