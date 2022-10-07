ENCODER_ENABLE = yes
OLED_DRIVER_ENABLE = yes

SRC += oled_display.c

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball
PIMORONI_TRACKBALL_ADDRESS = 0x0A
SRC += drivers/sensors/pimoroni_trackball.c
QUANTUM_LIB_SRC += i2c_master.c
