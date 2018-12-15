/**
 *  @file  <GPIO.h>
 *  @brief <Header File of The Tiva C GPIO library.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <19-OCT-18>
 *
 */
#ifndef GPIO_H_
#define GPIO_H_

  #include"Micro_Config_Tiva.h"
  #include"MACROS_TIVA.h"
  #include"STD_TYPES.h"

   /* This MACRO IS the code to unlock a certain GPIO*/
   #define UNLOCK_CODE (0x4C4F434BU)

  /* This Enumeration has the clock codes for each GPIO*/
  typedef enum
  {
      GPIOA_CLOCK = 0x01,
      GPIOB_CLOCK = 0x02,
      GPIOC_CLOCK = 0x04,
      GPIOD_CLOCK = 0x08,
      GPIOE_CLOCK = 0x10,
      GPIOF_CLOCK = 0x20,
  }GPIO_CLOCKS;

  typedef enum
  {
      LOW,HIGH
  }DIGITAL_SIGNAL;

  typedef enum
  {
      INPUT,OUTPUT
  }DIO_MODE;

  typedef enum
  {
      PULL_RESISTANCE_DISABLE, PULL_RESISTANCE_ENABLE
  }INTERNAL_RESISTANCE;

  typedef enum
  {
      DIGTAL_DISABLE,DIGITAL_ENALBE,
  }Digital_EnableSignal;

  /* This Macro is Used to enable the clock for a certain GPIO*/
  #define GPIO_CLOCK_ENABLE(PORT_CLOCK) do{ REG32_ACCESS((SYSTEM_CTL_BASE),(GPIO_CLOCKGATE_OFFSET)) |= (PORT_CLOCK);}while(0)

  /* This Macro is Used to disable the clock for a certain GPIO*/
  #define GPIO_CLOCK_DISABLE(PORT_CLOCK) do{ REG32_ACCESS((SYSTEM_CTL_BASE),(GPIO_CLOCKGATE_OFFSET)) & = (~PORT_CLOCK);}while(0)

  /* This Macro is Used to unlock a certain GPIO*/
  #define GPIO_UNLOCK(PORT_BASE) do{ REG32_ACCESS((PORT_BASE), (GPIO_LOCK_offset)) = UNLOCK_CODE;}while(0)

  /* This Macro is Used to lock a certain GPIO*/
  #define GPIO_LOCK(PORT_BASE) do{ REG32_ACCESS((PORT_BASE), (GPIO_LOCK_offset)) = 0;}while(0)

  /* This Macro is Used to commit changes to a certain 8 pins of a GPIO*/
  #define GPIO_COMMIT_ENABLE_8PINS(PORT_BASE) do{ REG32_ACCESS((PORT_BASE), (GPIO_CR_offset)) |= 0xFF;}while(0)

  /* This Macro is Used to Does not commit changes to a certain 8 pins of a GPIO*/
  #define GPIO_COMMIT_DISABLE_8PINS(PORT_BASE) do{ REG32_ACCESS((PORT_BASE), (GPIO_CR_offset)) &= 0x00;}while(0)

  /* This Macro is Used to commit changes to a certain pin of a GPIO*/
  #define GPIO_COMMIT_ENABLE_PIN(PORT_BASE, PIN_NO) do{ REG32_ACCESS((PORT_BASE), (GPIO_CR_offset)) |= (1U<<PIN_NO);}while(0)

  /* This Macro is Used to does not commit changes to a certain pin of a GPIO*/
  #define GPIO_COMMIT_DISABLE_PIN(PORT_BASE, PIN_NO) do{ REG32_ACCESS((PORT_BASE), (GPIO_CR_offset)) &= ~(1U<<PIN_NO);}while(0)

  /* These two Macros are Used to select between an alternative Function or a normal GPIO function for a certain pin*/
  #define GPIO_ALFUN_ENABLE(PORT_BASE, PIN_NO) do{ REG32_ACCESS((PORT_BASE), (GPIO_AFS_offset)) |= (1U<<PIN_NO);}while(0)
  #define GPIO_ALFUN_DISABLE(PORT_BASE, PIN_NO) do{ REG32_ACCESS((PORT_BASE), (GPIO_AFS_offset)) &= ~(1U<<PIN_NO);}while(0)

  /* This Macro is Used to select between an alternative Function or a normal GPIO function for a certain number of pins*/
  #define GPIO_ALFUN_SETPINS(PORT_BASE, CODE) do{ REG32_ACCESS((PORT_BASE), (GPIO_AFS_offset)) = CODE;}while(0)

  /* This Macro is used to select the direction of a certain pin whether an input or output*/
  #define GPIO_DIR_SELECT(PORT_BASE,PIN_NO,DIR_MODE) do{\
                                                         REG32_ACCESS((PORT_BASE),(GPIO_DIR_offset)) &= ~(1U<<PIN_NO);\
                                                         REG32_ACCESS((PORT_BASE),(GPIO_DIR_offset)) |= (DIR_MODE<<PIN_NO);\
                                                       }while(0)
  /* This Macro is used to set the direction for a certain number of pins*/
  #define GPIO_DIR_SELECTPINS(PORT_BASE, CODE) do{ REG32_ACCESS((PORT_BASE), (GPIO_DIR_offset)) = CODE;}while(0)

  /* This Macro is used to select and enable the internal resistance of a certain pin.*/
  #define GPIO_INTERNAL_RESISTANCE(PORT_BASE,REG_OFFSET,PIN_NO,RISTANCE_STATE) do{\
                                                                                      REG32_ACCESS((PORT_BASE),(REG_OFFSET)) &= ~(1U<<PIN_NO);\
                                                                                      REG32_ACCESS((PORT_BASE),(REG_OFFSET)) |= (RISTANCE_STATE<<PIN_NO);\
                                                                                   }while(0)

  /* This Macro is used to enable the digital functionality of a certain pin*/
  #define GPIO_DIGITAL_ENABLE(PORT_BASE, PIN_NO) do{ REG32_ACCESS((PORT_BASE),(GPIO_DEN_offset)) |= (1U<<PIN_NO);}while(0)

  /* This Macro is used to disable the digital functionality or a certain pin*/
  #define GPIO_DIGITAL_DISABLE(PORT_BASE, PIN_NO) do{ REG32_ACCESS((PORT_BASE),(GPIO_DEN_offset)) &= ~(1U<<PIN_NO);}while(0)

  /* This Macro is used to enable the digital functionality for a certain number of pins*/
  #define GPIO_DIGITAL_ENABLE_PINS(PORT_BASE, CODE) do{ REG32_ACCESS((PORT_BASE),(GPIO_DEN_offset)) = CODE;}while(0)

  /* This Macro is used to Disables the digital functionality for a certain number of pins*/
   #define GPIO_DIGITAL_DISABLE_PINS(PORT_BASE, CODE) do{ REG32_ACCESS((PORT_BASE),(GPIO_DEN_offset)) = CODE;}while(0)

  /* This Macro is used to enable the analog functionality for a certain number of pins*/
  #define GPIO_ANALOG_ENABLE_PINS(PORT_BASE, CODE) do{ REG32_ACCESS((PORT_BASE),(GPIO_Analog_M_SEL_offset)) = CODE;}while(0)

  /* This Macro is used to select the desired alternative function of a certain pin.*/
   #define GPIO_ALF_CONTROL(PORT_BASE,REG_OFFSET,PIN_NO,Digital_Code) do{\
                                                                            REG32_ACCESS((PORT_BASE),(REG_OFFSET)) &= ~(0xFU<<(PIN_NO*4));\
                                                                            REG32_ACCESS((PORT_BASE),(REG_OFFSET)) |= (Digital_Code<<(PIN_NO*4));\
                                                                         }while(0)



#endif /* GPIO_H_ */
