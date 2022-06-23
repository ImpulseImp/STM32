// LEDs PINs    green = 0 | blue = 7 | red = 14
// PORT B


#define PERIPH_BASE 0x40000000UL
#define AHB1_OFFSET 0x00020000UL
#define AHB1_PERIPH_BASE PERIPH_BASE + AHB1_OFFSET // 0x4002 0000
#define GPIOB_OFFSET 0x400UL   // the same as 0x00000400UL
#define GPIOB_BASE  AHB1_PERIPH_BASE + GPIOB_OFFSET // 0x4002 0400
#define RCC_OFFSET 0x3800UL //
#define RCC_BASE AHB1_PERIPH_BASE + RCC_OFFSET  //0x4002 3800
#define AHB1EN_R_OFFSET 0x30UL
#define RCC_AHB1EN_R (*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET)) //we have to type cast it
#define GPIOB_CLK_EN  (1U<<1) // 0000 0000 0000 0000 0000 0000 0000 0010
#define MODER_OFFSET 0x00UL

#define GPIOB_MODE_R (*(volatile unsigned int *)(GPIOB_BASE + MODER_OFFSET))

#define USER_LED1_MODER (1U<<0)
#define USER_LED2_MODER (1U<<14)
#define USER_LED3_MODER (1U<<28)

#define ODR_OFFSET 0x14UL
#define GPIOB_OD_R (*(volatile unsigned int *)(GPIOB_BASE + ODR_OFFSET))

#define USER_LED1 (1U<<0) //green
#define USER_LED2 (1U<<7)  // blue
#define USER_LED3 (1U<<14) //red


int main (void)
{
   /* Enable clock access to Port B */

   RCC_AHB1EN_R |= GPIOB_CLK_EN;

   /* Configure LEDs PINs as outputs */

   GPIOB_MODE_R |= USER_LED1_MODER | USER_LED2_MODER | USER_LED3_MODER;



   while(1)
   {

    // Turn on all LEDs

  	GPIOB_OD_R |= USER_LED1 | USER_LED2 | USER_LED3;

   }

}


