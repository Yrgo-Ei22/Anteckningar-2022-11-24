/********************************************************************************
* main.c: Demonstration av datastruktur för implementering av tryckknappar med
*         PCI-avbrott. I detta fall sker avläsning av en tryckknapp för
*         toggling av en lysdiod via en avbrottsrutin. För att göra motsvarande
*         objekt synliga i avbrottsrutinen så används globala datamedlemmar.
********************************************************************************/
#include "led.h"
#include "button.h"

/* Globala datamedlemmar: */
struct led l1;
struct button b1;

/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin för PCI-avbrott på I/O-port B, som i detta
*                    program anropas vid nedtryckning eller uppsläppning av
*                    tryckknapp b1. Vid nedtryckning av b1 togglas lysdiod l1.
********************************************************************************/
ISR (PCINT0_vect)
{
   if (button_is_pressed(&b1))
   {
      led_toggle(&l1);
   }

   return;
}

/********************************************************************************
* main: Ansluter en lysdiod till pin 8 / PORTB0 samt en tryckknapp till pin 13
*       / PORTB5, med PCI-avbrott aktiverat för toggling av lysdioden.
********************************************************************************/
int main(void)
{
   led_init(&l1, 8);
   button_init(&b1, 13);
   button_enable_interrupt(&b1);
   
   while (1)
   {

   }

   return 0;
}

