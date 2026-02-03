#define CLEAR_LCD                 0x01
#define RESET_CUR_HOME            0x02
#define GOTO_LINE1_POS0           0x80
#define GOTO_LINE2_POS0           0xC0
#define DISPLAY_ON_CURSOR_ON      0x0E
#define DISPLAY_ON_CURSOR_BLINK   0x0F
#define DISPLAY_ON_CURSOR_OFF     0xC0
#define MODE_8BIT_LINE1           0x30
#define MODE_8BIT_LINE2           0x38
#define SHIFT_CUR_LEFT            0x07
#define SHIFT_CUR_RIGHT           0x06
#define DSP_OFF                   0x08

//lcd_pin_connections

#define LCD_DATA  0
#define LCD_RS    8
#define LCD_RW    11
#define LCD_EN    9