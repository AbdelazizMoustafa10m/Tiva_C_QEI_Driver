/**
 *  @file  <MACROS_TIVA>
 *  @brief <Header File of The Tiva C Macros.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <19-OCT-18>
 *
 */
#ifndef MACROS_TIVA_H_
#define MACROS_TIVA_H_

    /* This line access an 32 bit IO register ,  volatile keyword is to prevent optimization*/
    #define REG32_ACCESS(BASE , OFFSET)    (*(volatile uint32 *)( (BASE) | (OFFSET)))


    /* Note That in Tiva when Reading From The GPIO Data The Bit Masked with the address is the only value
     *  will be Read and the rest will be cleared */
    /* This line checks if a certain PIN in any PORT is set and returns true if yes*/
    #define IS_PIN_SET(PORT_BASE,PIN_NO)   (REG32_ACCESS((PORT_BASE) , (GPIO_DATA_offset |GPIO_DATA_WRITE_OP_CODE)) & (1U<<PIN_NO))

     /* This line checks if a certain Pin in any PORT is cleared and returns true if yes*/
    #define IS_PIN_CLEAR(PORT_BASE,PIN_NO)  (!IS_PIN_SET((PORT_BASE),(PIN_NO)))

    /* This line sets a certain Pin in any PORT*/
    #define SET_PIN(PORT_BASE,PIN_NO)  do{\
                                                    REG32_ACCESS(PORT_BASE , (GPIO_DATA_offset |GPIO_DATA_WRITE_OP_CODE)) |= (1U<<PIN_NO) ;\
                                              }while(0)
    /* This line clears a certain Pin in any PORT*/
    #define CLEAR_PIN(PORT_BASE,PIN_NO)    do{\
                                                    REG32_ACCESS(PORT_BASE , (GPIO_DATA_offset |GPIO_DATA_WRITE_OP_CODE)) &= (uint32) ~(1U<<PIN_NO) ;\
                                              }while(0)

    /* This line checks if a certain bit in any register is set and returns true if yes*/
    #define IS_BIT_SET(PORT_BASE,REG_offset,PIN_NO)    (REG32_ACCESS((PORT_BASE) , (REG_offset)) & (1U<<PIN_NO))

     /* This line checks if a certain bit in any register is cleared and returns true if yes*/
    #define IS_BIT_CLEAR(PORT_BASE,REG_offset,PIN_NO)  (!(REG32_ACCESS((PORT_BASE) , (REG_offset)) & (1U<<PIN_NO)))

    /* This line sets a certain bit in any register*/
    #define SET_BIT(PORT_BASE,REG_offset,PIN_NO)  do{\
                                                        REG32_ACCESS(PORT_BASE , (REG_offset)) |= (1U<<PIN_NO) ;\
                                                    }while(0)
    /* This line clears a certain bit in any register*/
    #define CLEAR_BIT(PORT_BASE,REG_offset,PIN_NO)  do{\
                                                          REG32_ACCESS(PORT_BASE , (REG_offset)) &= (uint32) ~(1U<<PIN_NO) ;\
                                                     }while(0)

    /* This line reads a certain register*/
    #define READ_REGISTER(PORT_BASE,REG_offset)    do{\
                                                          REG32_ACCESS((PORT_BASE) , (REG_offset));\
                                                     }while(0)





#endif /* MACROS_TIVA_H_ */
