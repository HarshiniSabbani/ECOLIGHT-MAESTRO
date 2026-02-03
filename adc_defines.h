
//clock defines
#define FCLK  12000000
#define CCLK  (FCLK*5)
#define PCLK  (CCLK/4)
#define ADCLK 3000000
#define CLKDIV ((PCLK/ADCLK)-1)

//defines for ADCR sfr
#define CLKDIV_BITS 8
#define PDN_BIT     21
#define ADC_CONV_START_BIT  24

//defines for ADDR sfr
#define  DIGITAL_DATA_BITS  6
#define  DONE_BIT           31
