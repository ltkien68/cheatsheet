#include <stdio.h>
#include <stdint.h>

typedef uint8_t Register;

typedef enum {
    LIGHT_ON,
    LIGHT_OFF
} LIGHT_STATUS;

typedef enum {
    OK,
    PRIORITY_MODE,
    NO_VEHICLE,
    LIGHT_FAULT
} SYSTEM_STATUS;

#define RED_PIN         5
#define YELLOW_PIN      3
#define GREEN_PIN       1
#define PRIORITY_BTN    7
#define WAITING_SENSOR  0

#define SET_PIN(reg, bit)       ((reg) |= (1UL << (bit)))
#define CLEAR_PIN(reg, bit)     ((reg) &= ~(1UL << (bit)))
#define TOGGLE_PIN(reg, bit)    ((reg) ^= (1UL << (bit)))
#define READ_PIN(reg, bit)      (((reg) >> (bit)) & 1UL)

typedef void (*LightCommand)(Register*);

LIGHT_STATUS red_stt = LIGHT_OFF;
LIGHT_STATUS yellow_stt = LIGHT_OFF;
LIGHT_STATUS green_stt = LIGHT_OFF;

void red_on(Register *reg) {
    red_stt = LIGHT_ON;
    SET_PIN(*reg, RED_PIN);
}

void red_off(Register *reg) {
    red_stt = LIGHT_OFF;
    CLEAR_PIN(*reg, RED_PIN);
}

void yellow_on(Register *reg) {
    yellow_stt = LIGHT_ON;
    SET_PIN(*reg, YELLOW_PIN);
}

void yellow_off(Register *reg) {
    yellow_stt = LIGHT_OFF;
    CLEAR_PIN(*reg, YELLOW_PIN);
}

void green_on(Register *reg) {
    green_stt = LIGHT_ON;
    SET_PIN(*reg, GREEN_PIN);
}

void green_off(Register *reg) {
    green_stt = LIGHT_OFF;
    CLEAR_PIN(*reg, GREEN_PIN);
}

SYSTEM_STATUS systemCheck(Register reg) {
    if (READ_PIN(reg, PRIORITY_BTN) == 1) {
        return PRIORITY_MODE;
    }
    if (READ_PIN(reg, WAITING_SENSOR) == 0) {
        return NO_VEHICLE;
    }
    if (green_stt != LIGHT_ON) {
        return LIGHT_FAULT;
    } else {
        return OK;
    }
}

int main() {
    Register gpio = 0x00;
    LightCommand cmd;
    SYSTEM_STATUS sys;

    cmd = green_on;
    cmd(&gpio);
    printf("GREEN ON: 0x%02X\n", gpio);

    SET_PIN(gpio, WAITING_SENSOR);
    printf("Vehicle waiting: 0x%02X\n", gpio);

    sys = systemCheck(gpio);
    if (sys == OK) {
        printf("Sensor: No vehicle\n");
        printf("System: OK!\n");
    }

    SET_PIN(gpio, PRIORITY_BTN);

    sys = systemCheck(gpio);
    if (sys == PRIORITY_MODE) {
        printf("MODE: Priority mode\n");

        cmd = green_off;
        cmd(&gpio);
        printf("Green Light OFF: 0x%02X\n", gpio);

        cmd = red_on;
        cmd(&gpio);
        printf("Red Light ON: 0x%02X\n", gpio);
    }

    CLEAR_PIN(gpio, PRIORITY_BTN);
    printf("Priority Mode: Disable\n");

    cmd = green_off;
    cmd(&gpio);
    printf("Green Light OFF: 0x%02X\n", gpio);

    sys = systemCheck(gpio);
    if (sys == LIGHT_FAULT) {
        printf("Green Light: Light fault\n");
    }

    return 0;
}