/*
 * QEI.h
 *
 *  Created on: Dec 14, 2018
 *      Author: Abdelaziz
 */

#ifndef QEI_H_
#define QEI_H_

#include"Micro_Config_Tiva.h"
#include"MACROS_TIVA.h"
#include"GPIO.h"

/**
 *  @file  <QEI.h>
 *  @brief <Header File of The Quadrature Encoder Interface(QEI) Module of the Tm4c123 controller.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <14-Dec-18>
 *
 */


  /* The following group of definitions represent the Bit Numbers in QEICTL Register in Tm4c123.*/
  #define QEI_ENABLE_BIT                                (0)          /* ENABLE*/
  #define QEI_VEL_ENABLE_BIT                            (5)          /* VELEN*/

  /* The following group of definitions represent the Bit Numbers in QEIRIS/QEIICR Register in Tm4c123.*/
  #define QEI_ERROR_INTERRUPT_FLAG_BIT                  (3)          /* INTERROR */
  #define QEI_DIR_CHANGE_INTERRUPT_FLAG_BIT             (2)          /* INTDIR   */
  #define QEI_VEL_TIMER_EXP_INTERRUPT_FLAG_BIT          (1)          /* INTTIMER */
  #define QEI_INDEX_PULSE_D_INTERRUPT_FLAG_BIT          (0)          /* INTINDEX */

  /* The following group of definitions represent the Bit Numbers in QEISTAT Register in Tm4c123.*/
  #define QEI_ROTATION_DIR_BIT                          (1)          /* DIRECTION*/

  /* This Macro Defines the digital code encoded in GPIOCTL Register to select the QEI Alternative Function*/
  #define QEI_Digital_Code                              (6)


  /* This Enumeration has the clock codes for each QEI Module*/
  typedef enum
  {
      QEI0_CLOCK = 0x1,     QEI1_CLOCK = 0x2,

  }QEI_CLOCKS;

  /* This Enumeration select the signal Mode for each QEI Module*/
  typedef enum
  {
      QEI_Quadrature_PHASE_SIG = 0x00000000,        QEI_CLOCK_DIR_SIG      = 0x00000004,

  }QEI_SIG_MODE;

  /* This Enumeration Select the signal capture mode for each QEI Module*/
  typedef enum
  {
      QEI_CAP_PhA_ONLY       =     0x00000000,       QEI_CAP_BOTH_PhA_PhB     =  0x00000008,

  }Signal_CAP_Mode;

  /* This Enumeration Select the Reset state for each QEI Module*/
  typedef enum
  {
      QEI_NO_RESET_ON_INDEX  =     0x00000000,       QEI_RESET_ON_INDEX_CHANGE =  0x00000010,

  }Reset_State;

  /* This Enumeration Selects between signal swapping or not  for each QEI Module*/
  typedef enum
  {
      QEI_NO_SIG_SWAP        =     0x00000000,       QEI_SWAP_SIGNAL      =       0x00000002,

  }SWAP_State;

  /* This Enumeration Selects the velocity predevide value  for each QEI Module*/
  typedef enum
  {
      QEI_VEL_PRE_DIV_1      =      0x00000000,     QEI_VEL_PRE_DIV_2      =      0x00000040,
      QEI_VEL_PRE_DIV_4      =      0x00000080,     QEI_VEL_PRE_DIV_8      =      0x000000C0,
      QEI_VEL_PRE_DIV_16     =      0x00000100,     QEI_VEL_PRE_DIV_32     =      0x00000140,
      QEI_VEL_REW_DIV_64     =      0x00000180,     QEI_VEL_PRE_DIV_128    =      0x000001C0,
  }Velocity_PreDevide;

  /* This Enumeration Selects the velocity predevide value for each QEI Module*/
  typedef enum
  {
      QEI_NO_FILTER          =      0x00000000,     QEI_FILTCNT_3          =      0x00012000,
      QEI_FILTCNT_4          =      0x00022000,     QEI_FILTCNT_5          =      0x00032000,
      QEI_FILTCNT_6          =      0x00042000,     QEI_FILTCNT_7          =      0x00052000,
      QEI_FILTCNT_8          =      0x00062000,     QEI_FILTCNT_9          =      0x00072000,
      QEI_FILTCNT_10         =      0x00082000,     QEI_FILTCNT_11         =      0x00092000,
      QEI_FILTCNT_12         =      0x000A2000,     QEI_FILTCNT_13         =      0x000B2000,
      QEI_FILTCNT_14         =      0x000C2000,     QEI_FILTCNT_15         =      0x000D2000,
      QEI_FILTCNT_16         =      0x000E2000,     QEI_FILTCNT_17         =      0x000F2000,
  }Input_Filter_State;

  /* This Enumeration Selects the Inversion state for the signal and the index for each QEI Module*/
  typedef enum
  {
      QEI_NO_INVERT          =      0x00000000,     QEI_INVERT_INDEX       =      0x00000800,
      QEI_INVERT_PhA         =      0x00000200,     QEI_INVERT_PhB         =      0x00000400,
      QEI_INVERT_A_B         =      0x00000600,     QEI_INVERT_A_B_I       =      0x00000E00,
  }Signal_invert_State;

  /* This Enumeration has the interrupt state codes for each QEI Module*/
  typedef enum
  {
      QEI_NO_Interrupts      =      0x00000000,     QEI_Error_INT_ENABLE   =      0x00000008,
      QEI_DIR_CH_INT_ENABLE  =      0x00000004,     QEI_T_EXP_INT_ENABLE   =      0x00000002,
      QEI_INDEX_INT_ENABLE   =      0x00000600,
  }Interrupt_State;


  /* This Macro is Used to enable the desired QEI Module*/
  #define QEI_ENABLE(QEI_BASE) do{ SET_BIT(QEI_BASE,QEI_CTL_offset,QEI_ENABLE_BIT);}while(0)


  /**
   *  @brief <QEI_Init(uint32 QEI_Base, QEI_CLOCKS Clock, GPIO_CLOCKS PORT_CLOCK)>
   *  <This function will be used to Initiate the QEI Module in The Tm4c123 by enabling module clock and PORT clock.>
   *
   *  @param uint32        <QEI_Base>          <The Base Address of the desired QEI Module.>
   *  @param QEI_CLOCKS    <Clock>             <The Clock code for the desired QEI Module.>
   *  @param GPIO_CLOCKS   <PORT_CLOCK>        <The Clock code for the desired GPIO PORT that will be used by the QEI Module.>
   *
   *  @return <This Function Returns Void.>
   *
   */
   void QEI_Init(uint32 QEI_Base, QEI_CLOCKS Clock, GPIO_CLOCKS PORT_CLOCK);

   /**
    *  @brief < void GPIO_AFSEL_FOR_QEI(uint32 PORT_BASE, uint8 PhA_PIN_NO, uint8 PhB_PIN_NO)>
    *  <This function will be used to Select the QEI alternative function for .>
    *
    *  @param uint32   <PORT_BASE>            <The Base Address of the desired GPIO.>
    *  @param uint8    <PhA_PIN_NO>           <GPIO PIN number used as PhA for the QEI Module.>
    *  @param uint8    <PhB_PIN_NO>           <GPIO PIN number used as PhB for the QEI Module.>
    *
    *  @return <This Function Returns Void.>
    *
    */
    void GPIO_AFSEL_FOR_QEI(uint32 PORT_BASE, uint8 PhA_PIN_NO, uint8 PhB_PIN_NO);

    /**
     *  @brief <void QEI_Configuration(uint32 QEI_Base, QEI_SIG_MODE Signal_Mode, Signal_CAP_Mode Capture_Mode,Reset_State Reset_State,
     *                                 SWAP_State Swap_State, Signal_invert_State INV_state, uint32 MAX_Postion);>
     *  <This function will be used to Configure The QEI Module in the Tm4c123 Controller.>
     *
     *  @param uint32               <QEI_Base>       <The Base Address of the desired Timer Module.>
     *  @param QEI_SIG_MODE         <Signal_Mode>    <The Signal Mode for the QEI Module whether its Quadrature phase or clock/Dir .>
     *  @param Signal_CAP_Mode      <Capture_Mode>   <The signal Capture mode for the QEI module.>
     *  @param Reset_State          <Reset_State>    <The Reset state of the QEI whether using reset on index change or not.>
     *  @param SWAP_State           <Swap_State>     <The swap state of the signals entering the QEI Module.>
     *  @param uint32               <MAX_Postion>    <The Maximum position for the QEI Module.>
     *  @param Signal_invert_State  <INV_state>      <The Inversion state of the signals entering the QEI Module.>
     *
     *  @return <This Function Returns Void.>
     *
     */
     void QEI_Configuration(uint32 QEI_Base, QEI_SIG_MODE Signal_Mode, Signal_CAP_Mode Capture_Mode, Reset_State Reset_State,
                            SWAP_State Swap_State,Signal_invert_State INV_state, uint32 MAX_Postion);

     /**
      *  @brief void QEI_VELOCITY_Configuration(uint32 QEI_Base, Velocity_PreDevide Pre_Devision, uint32 Vel_LOAD_Value)>
      *  <This function will be used to configure using the QEI Module for Velocity Capture .>
      *
      *  @param uint32               <QEI_Base>          <The Base Address of the desired QEI Module.>
      *  @param Velocity_PreDevide   <Pre_Devision>      <This Selects the different pre devision values for velocity.>
      *  @param uint32               <Vel_LOAD_Value>    <The value loaded in the velocity timer.>
      *
      *  @return <This Function Returns Void.>
      *
      */
      void QEI_VELOCITY_Configuration(uint32 QEI_Base, Velocity_PreDevide Pre_Devision, uint32 Vel_LOAD_Value);

     /**
      *  @brief <void QEI_INPUT_Filter_CONFIGURE(uint32 QEI_Base, Input_Filter_State Filter_Select)>
      *  <This function will be used to configure using input filter or not for the QEI Module and selects the desired filter.>
      *
      *  @param uint32               <QEI_Base>          <The Base Address of the desired QEI Module.>
      *  @param Input_Filter_State   <Filter_Select>     <This Selects the different input filter modes for the QEI Module.>
      *
      *  @return <This Function Returns Void.>
      *
      */
      void QEI_INPUT_Filter_CONFIGURE(uint32 QEI_Base, Input_Filter_State Filter_Select);

      /**
       *  @brief <void QEI_Interrupts_Configure(uint32 QEI_Base, Interrupt_State Int_state)>
       *  <This function will be used to configure using Generating interrupts or not for the QEI Module.>
       *
       *  @param uint32               <QEI_Base>          <The Base Address of the desired QEI Module.>
       *  @param Interrupt_State      <Int_state>         <The Selects the desired interrupt to be generated by the QEI Module.>
       *
       *  @return <This Function Returns Void.>
       *
       */
       void QEI_Interrupts_Configure(uint32 QEI_Base, Interrupt_State Int_state);

       /**
        *  @brief <uint32 QEI_GET_POSITION(uint32 QEI_Base)>
        *  <This function will be used to Get the position from a desired QEI Module.>
        *
        *  @param  uint32               <QEI_Base>                   <The Base Address of the desired QEI Module.>
        *
        *  @return uint32               <The Position of the QEI >
        *
        */
        uint32 QEI_GET_POSITION(uint32 QEI_Base);

        /**
         *  @brief <uint32 QEI_GET_VELOCITY(uint32 QEI_Base)>
         *  <This function will be used to Get the velocity from a desired QEI Module.>
         *
         *  @param  uint32               <QEI_Base>                  <The Base Address of the desired QEI Module.>
         *
         *  @return uint32               <The Velocity of the QEI >
         *
         */
         uint32 QEI_GET_VELOCITY(uint32 QEI_Base);

         /**
          *  @brief <sint32 QEI_GET_DIRECTION(uint32 QEI_Base)>
          *  <This function will be used to Get the Direction of rootation from a desired QEI Module.>
          *
          *  @param  uint32               <QEI_Base>                  <The Base Address of the desired QEI Module.>
          *
          *  @return Sint32               <The Direction of rotation of the QEI >
          *
          */
          sint32 QEI_GET_DIRECTION(uint32 QEI_Base);


#endif /* QEI_H_ */
