#include <stdio.h>
#include <stdint.h>

typedef uint8_t Register;

typedef enum {
    MOTOR_ON,
    MOTOR_OFF
} MOTOR_STATUS;

typedef enum {
    OK,
    OVERHEAT_ERROR,
    EMERGENCY_STOP,
    MOTOR_ERROR
} SYSTEM_STATUS;

#define MOTOR1_PIN      4
#define MOTOR2_PIN      2
#define SENSOR_PIN      0
#define EMERGENCY_PIN   7

#define SET_PIN(reg, bit)       ((reg) |= (1UL << (bit)))
#define CLEAR_PIN(reg, bit)     ((reg) &= ~(1UL << (bit)))
#define TOGGLE_PIN(reg, bit)    ((reg) ^= (1UL << (bit)))
#define READ_PIN(reg, bit)      (((reg) >> (bit)) & 1UL) 

typedef void (*MotorCommand)(Register*);

MOTOR_STATUS motor1_stt = MOTOR_OFF;
MOTOR_STATUS motor2_stt = MOTOR_OFF;

void motor1_on(Register *reg) {
    motor1_stt = MOTOR_ON;
    SET_PIN(*reg, MOTOR1_PIN);
}

void motor1_off(Register *reg) {
    motor1_stt = MOTOR_OFF;
    CLEAR_PIN(*reg, MOTOR1_PIN);
}

void motor2_on(Register *reg) {
    motor2_stt = MOTOR_ON;
    SET_PIN(*reg, MOTOR2_PIN);
}

void motor2_off(Register *reg) {
    motor2_stt = MOTOR_OFF;
    CLEAR_PIN(*reg, MOTOR2_PIN);
}

SYSTEM_STATUS systemCheck(Register reg) {
    if (READ_PIN(reg, SENSOR_PIN) == 1) {
        return OVERHEAT_ERROR;
    }
    if (READ_PIN(reg, EMERGENCY_PIN) == 1) {
        return EMERGENCY_STOP;
    }
    if (motor1_stt != MOTOR_ON || motor2_stt != MOTOR_ON) {
        return MOTOR_ERROR;
    }
    return OK;
}

int main() {
    Register gpio = 0x00;
    MotorCommand cmd;
    SYSTEM_STATUS sys;

    cmd = motor1_on;
    cmd(&gpio);
    printf("MOTOR 1 ON: 0x%02X\n", gpio);

    cmd = motor2_on;
    cmd(&gpio);
    printf("MOTOR 2 ON: 0x%02X\n", gpio);

    SET_PIN(gpio, SENSOR_PIN);
    printf("SENSOR SET: 0x%02X\n", gpio);

    sys = systemCheck(gpio);
    if (sys == OVERHEAT_ERROR) {
        printf("System Overheat\n");
        SET_PIN(gpio, EMERGENCY_PIN);
        printf("EMERGENCY STOP SET: 0x%02X\n", gpio);

        sys = systemCheck(gpio);
        if (sys == EMERGENCY_STOP) {
            printf("System Emergency Stop!\n");
        }
    }  else if (sys == MOTOR_ERROR) {
        printf("Motor error\n");
    } else {
        printf("OK\n");
    }

    return 0;
}
