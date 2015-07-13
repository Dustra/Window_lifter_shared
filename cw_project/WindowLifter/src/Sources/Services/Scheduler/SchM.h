#ifndef _SchM_H_
#define _SchM_H_


#include "SchM_Types.h"



extern void SchM_Init(SchConfigType *Sch_Config_ptr);
extern void SchM_Stop(void);
extern void SchM_Start(void);
extern void SchM_OsTick(void);
extern void SchM_Background(void);












#endif