/**
 *  @file  <MICRO_CONFIG_TIVA.h>
 *  @brief <Header File of The Tiva C configuration.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <19-OCT-18>
 *
 */


#ifndef MICRO_CONFIG_TIVA_H_
#define MICRO_CONFIG_TIVA_H_

  #include"STD_TYPES.h"

  /* System control base address and offsets.*/
  #define SYSTEM_CTL_BASE                             (0x400FE000U)
  #define GPIO_CLOCKGATE_OFFSET                       (0x608U)
  #define ADC_CLOCK_ofsset                            (0x638U)
  #define ADC_SAMP_SPEED_ofsset                       (0x100U)
  #define GPTM_CLOCK_offset                           (0x604U)
  #define WGPTM_CLOCK_offset                          (0x65CU)
  #define QEI_CLOCK_offset                            (0x644U)


  /* This macro is used whenever we want to write data to the microcontroller*/
  #define GPIO_DATA_WRITE_OP_CODE                     (0x3FCU)

  /* GPIO PORT ADDRESS USING  APB Bus */
  #define GPIOPA_APB_BASE                             (0x40004000U)
  #define GPIOPB_APB_BASE                             (0x40005000U)
  #define GPIOPC_APB_BASE                             (0x40006000U)
  #define GPIOPD_APB_BASE                             (0x40007000U)
  #define GPIOPE_APB_BASE                             (0x40024000U)
  #define GPIOPF_APB_BASE                             (0x40025000U)

  /* GPIO PORT ADDRESS USING  AHB Bus */
  #define GPIOPA_AHB_BASE                             (0x40058000U)
  #define GPIOPB_AHB_BASE                             (0x40059000U)
  #define GPIOPC_AHB_BASE                             (0x4005A000U)
  #define GPIOPD_AHB_BASE                             (0x4005B000U)
  #define GPIOPE_AHB_BASE                             (0x4005C000U)
  #define GPIOPF_AHB_BASE                             (0x4005D000U)

  /* GPIO REGISTERS OFFSETS MAP */
  /* All PORTS Use This offset No Matter what interface Bus we Use we just OR PORT Base
   * with REG Offset */
  /* GPIO Registers Offset Can be Found @ P660 in the data sheet.*/
  #define GPIO_DATA_offset                            (0x000U)
  #define GPIO_DIR_offset                             (0x400U)
  #define GPIO_LOCK_offset                            (0x520U)
  #define GPIO_CR_offset                              (0x524U)
  #define GPIO_AFS_offset                             (0x420U)
  #define GPIO_PORT_CTL_offset                        (0x52CU)
  #define GPIO_PUR_offset                             (0x510U)
  #define GPIO_PDR_offset                             (0x514U)
  #define GPIO_DEN_offset                             (0x51CU)
  #define GPIO_Analog_M_SEL_offset                    (0x528U)

  /* ADC modules base addresses.*/
  #define ADC0_BASE                                   (0x40038000U)
  #define ADC1_BASE                                   (0x40039000U)

  /* ADC Registers Offset Can be Found @ P818 in the data sheet.*/
  #define ADC_ACTIVE_SS_offset                        (0x000U)
  #define ADC_RAW_INT_STAT_offset                     (0x004U)
  #define ADC_INT_STAT_CLEAR_offset                   (0x00CU)
  #define ADC_EVENT_SEL_offset                        (0x014U)
  #define ADC_TRIG_SOURCE_SEL_offset                  (0x01CU)
  #define ADC_Pro_SS_init_offset                      (0x028U)
  #define ADC_SS_PRI_offset                           (0x020U)
  #define ADC_CTL_offset                              (0x038U)
  #define ADC_SS0_MUX_offset                          (0x040U)
  #define ADC_SS0_CTL_offset                          (0x044U)
  #define ADC_SS0_RESULT_offset                       (0x048U)
  #define ADC_SS1_MUX_offset                          (0x060U)
  #define ADC_SS1_CTL_offset                          (0x064U)
  #define ADC_SS1_RESULT_offset                       (0x068U)
  #define ADC_SS2_MUX_offset                          (0x080U)
  #define ADC_SS2_CTL_offset                          (0x084U)
  #define ADC_SS2_RESULT_offset                       (0x088U)
  #define ADC_SS3_MUX_offset                          (0x0A0U)
  #define ADC_SS3_CTL_offset                          (0x0A4U)
  #define ADC_SS3_RESULT_offset                       (0x0A8U)


  /* Timer modules base addresses.*/
  #define Timer0_BASE                                 (0x40030000U)
  #define Timer1_BASE                                 (0x40031000U)
  #define Timer2_BASE                                 (0x40032000U)
  #define Timer3_BASE                                 (0x40033000U)
  #define Timer4_BASE                                 (0x40034000U)
  #define Timer5_BASE                                 (0x40035000U)
  #define WTimer0_BASE                                (0x40036000U)
  #define WTimer1_BASE                                (0x40037000U)
  #define WTimer2_BASE                                (0x4004C000U)
  #define WTimer3_BASE                                (0x4004D000U)
  #define WTimer4_BASE                                (0x4004E000U)
  #define WTimer5_BASE                                (0x4004F000U)

  /* Timers Registers Offset Can be Found @ P727 in the data sheet.*/
  #define GPTM_CONFIG_offset                          (0x000U)
  #define GPTM_A_MODE_offset                          (0x004U)
  #define GPTM_B_MODE_offset                          (0x008U)
  #define GPTM_CTL_offset                             (0x00CU)
  #define GPTM_SYNCH_offset                           (0x010U)
  #define GPTM_RAW_INT_STAT_offset                    (0x01CU)
  #define GPTM_INT_CLEAR_offset                       (0x024U)
  #define GPTM_A_I_LOAD_offset                        (0x028U)
  #define GPTM_B_I_LOAD_offset                        (0x02CU)
  #define GPTM_A_MATCH_offset                         (0x030U)
  #define GPTM_B_MATCH_offset                         (0x034U)
  #define GPTM_A_PRESCALE_offset                      (0x038U)
  #define GPTM_B_PRESCALE_offset                      (0x03CU)
  #define GPTM_A_offset                               (0x048U)
  #define GPTM_B_offset                               (0x04CU)
  #define GPTM_A_VALUE_offset                         (0x050U)
  #define GPTM_B_VALUE_offset                         (0x054U)
  #define GPTM_A_PSCALE_VALUE_offset                  (0x064U)
  #define GPTM_B_PSCALE_VALUE_offset                  (0x068U)


  /* QEI modules base addresses.*/
  #define QEI0_BASE                                   (0x4002C000U)
  #define QEI1_BASE                                   (0x4002D000U)

  /* QEI Registers Offset Can be Found @ P1311 in the data sheet.*/
  #define QEI_CTL_offset                              (0x000U)
  #define QEI_STATUS_offset                           (0x004U)
  #define QEI_POSITION_offset                         (0x008U)
  #define QEI_MAX_POS_offset                          (0x00CU)
  #define QEI_TIMER_LOAD_offset                       (0x010U)
  #define QEI_TIMER_offset                            (0x014U)
  #define QEI_VEL_COUNTER_offset                      (0x018U)
  #define QEI_VELOCITY_offset                         (0x01CU)
  #define QEI_INT_ENABLE_offset                       (0x020U)
  #define QEI_RAW_INT_STATUS_offset                   (0x024U)
  #define QEI_INT_STAT_CLEAR_offset                   (0x028U)

#endif /* MICRO_CONFIG_TIVA_H_ */
