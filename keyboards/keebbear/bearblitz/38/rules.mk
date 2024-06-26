# Build Options

SERIAL_DRIVER = vendor

#AUTO SHIFT
AUTO_SHIFT_ENABLE = yes

#POINTING DEVICE
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_spi

#COMBO
COMBO_ENABLE = yes

#LCD
QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
QUANTUM_PAINTER_DRIVERS = st7789_spi

SRC += lvgl_helpers.c \
	   display.c \
	   keebbear.c

#AUDIO
AUDIO_ENABLE = no
MUSIC_ENABLE = no

#HAPTIC FEEBACK
HAPTIC_ENABLE = no
