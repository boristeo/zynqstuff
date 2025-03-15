#include <stdint.h>

#include "ps7_init.h"
//#include "xparameters.h"
//#include "xgpio_l.h"
//#include "xil_printf.h"

#define LED_DELAY   20000000
#define LED_CHANNEL  0

#define XGPIO_DATA_OFFSET  0x0   /**< Data register for 1st channel */
#define XGPIO_TRI_OFFSET  0x4   /**< I/O direction reg for 1st channel */
#define XGPIO_DATA2_OFFSET  0x8   /**< Data register for 2nd channel */
#define XGPIO_TRI2_OFFSET  0xC   /**< I/O direction reg for 2nd channel */
#define XGPIO_CHAN_OFFSET  8  /**< Channel offeset */

#define GPIO_REG_BASEADDR 0x41200000

#define XPS_SYS_CTRL_BASEADDR		0xF8000000U	/* AKA SLCR */
#define SlcrUnlock()	*(volatile uint32_t*)(XPS_SYS_CTRL_BASEADDR + 0x08) = 0xDF0DDF0D;
#define SlcrLock()		*(volatile uint32_t*)(XPS_SYS_CTRL_BASEADDR + 0x04) = 0x767B767B;

int main(void) {
  ps7_init();
  ps7_post_config();
  // Set the direction for all signals to be inputs except the LED output
  *(volatile uint32_t*) (GPIO_REG_BASEADDR + LED_CHANNEL * XGPIO_CHAN_OFFSET + XGPIO_TRI_OFFSET) = ~0xf;

  // Loop forever blinking the LED
  for (;;) {
    //uint32_t data = *(volatile uint32_t*) (GPIO_REG_BASEADDR + LED_CHANNEL * XGPIO_CHAN_OFFSET + XGPIO_DATA_OFFSET);
	*(volatile uint32_t*) (GPIO_REG_BASEADDR + 0 * XGPIO_CHAN_OFFSET + XGPIO_DATA_OFFSET) = 1;
	for (int64_t delay = 0; delay < LED_DELAY; delay++)
		asm __volatile("");
	*(volatile uint32_t*) (GPIO_REG_BASEADDR + 0 * XGPIO_CHAN_OFFSET + XGPIO_DATA_OFFSET) = 2;
	for (int64_t delay = 0; delay < LED_DELAY; delay++)
		asm __volatile("");
  }
}

//void _start() {
//  ps7_init();
//  ps7_post_config();
//  main();
//}
void __libc_init_array() {}
void __libc_fini_array() {}
void exit(int) {}
