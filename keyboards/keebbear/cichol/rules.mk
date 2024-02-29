SERIAL_DRIVER = vendor

COMBO_ENABLE = yes

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
QUANTUM_PAINTER_DRIVERS = st7789_spi

RAW_ENABLE = yes

SRC += lvgl_helpers.c \
	   display.c \
	   code.c \
	   design.c \
	   game.c \
	   arrpad.c \
	   lower.c \
	   raise.c \
	   cog.c
