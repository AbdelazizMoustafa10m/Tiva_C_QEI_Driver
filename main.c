

/**
 * main.c
 */
#include"QEI.h"

#define MAX_POS (0xFFFFFFFF)
#define ONE_SEC (16000000)

int main(void)
{
    QEI_Init(QEI0_BASE,QEI0_CLOCK,GPIOF_CLOCK);
    GPIO_AFSEL_FOR_QEI(GPIOPF_APB_BASE,0,1);
    QEI_Configuration(QEI0_BASE,QEI_Quadrature_PHASE_SIG,QEI_CAP_BOTH_PhA_PhB,QEI_NO_RESET_ON_INDEX,QEI_NO_SIG_SWAP,QEI_NO_INVERT,MAX_POS);
    QEI_VELOCITY_Configuration(QEI0_BASE,QEI_VEL_PRE_DIV_1,ONE_SEC);
    while(1)
    {
        uint32 Velocity = QEI_GET_VELOCITY(QEI0_BASE);
    }

}
