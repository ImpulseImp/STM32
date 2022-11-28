#include "stm32f411xe.h"

#define GPIOAEN				(1U<<0)

///asdas

/*
 * 
 * 
 * 
 * add new feature
 */
int main() {
	/*Enable clock access to GPIO A*/
	RCC->AHB1ENR |= GPIOAEN;

	/*Set PA5 to output pin*/
	GPIOA->MODER |= (1U << 10);
	GPIOA->MODER &= ~(1U << 11);

	/*Set PA5 high*/
	GPIOA->ODR |= (1U << 5);

}
