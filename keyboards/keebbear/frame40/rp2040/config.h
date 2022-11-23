// Copyright 2022 @geigeigeist
// SPDX-License-Identifier: GPL-2.0+

#pragma once

/* Key matrix configuration. */
#define MATRIX_ROW_PINS \
    { GP4, GP5, GP6, GP7 }
#define MATRIX_COL_PINS \
    { GP8, GP9, GP29, GP28, GP27, GP26 }

/* Handedness. */
#define MASTER_RIGHT

// To use the handedness pin, resistors need to be installed on the PCB.
// If so, uncomment the following code, and undefine MASTER_RIGHT above.
//#define SPLIT_HAND_PIN GP29
// If you've soldered the handedness pull-up on the upper side instead of the
// left one, uncomment the following line.
//#define SPLIT_HAND_PIN_LOW_IS_LEFT // High -> right, Low -> left.

/* serial.c configuration (for split keyboard). */
#define SOFT_SERIAL_PIN GP1

/* CRC. */
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

/* Cirque trackpad over SPI. */
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20
#define POINTING_DEVICE_CS_PIN GP21

/* OLED over i2c. */
#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_16_9

/* i2c */
#define I2C_DRIVER I2CD1

/* communication between sides */
#define SERIAL_PIO_USE_PIO1

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

