
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

// amount of memory to be allocated for heap storage must be specified for every ANSI C++ program with the bur_heap_size variable
unsigned long bur_heap_size = 0xFFFF; 

void _INIT ProgramInit(void)
{
	i=0;
	go=0;
	BR_PLT_TURN_1=1;
	BR_PLT_BELT_1=1;
	BR_CNV=1;
	BR_PLT_CNV=1;
	BR_PLT_GO=1;
	BR_PLT_UP=0;
	BR_PLT_DOWN=0;
	k=0;
	BR_PLT_EL_FULL = 1;

}

void _CYCLIC ProgramCyclic(void)
{
	if((BR_PLT_FRONT == 1) && (BR_PLT_BACK == 1) && (k==0))
	{
		BR_PLT_CNV=0;
		BR_PLT_GO=0;
		BR_PLT_EL_FULL = 1;
		BR_PLT_UP = 1;
		k++;
	}
	if((BR_PLT_EL_MOVING == 0) && (k==1))
	{
		k++;
	}
	if((BR_PLT_EL_MOVING == 1) && (k==2))
	{
		k++;
	}
	if((BR_PLT_EL_MOVING == 0) && (k==3))
	{
		BR_PLT_UP = 0;
		k++;
	}
	if(BR_PLT_SENS_1 == 1 && (i==0) && (go<2))
	{
		BR_PLT_BELT_1=1;
		BR_CNV=1;
		i++;
	}
	if((BR_PLT_SENS_1 == 0) && (i==1))
	{	
		i++;
	}
	if((BR_PLT_SENS_1 == 1) && (i==2))
	{
		i++;
	}
	if((BR_PLT_SENS_1 == 0) && (i==3))
	{
		i++;
	}
	if((BR_PLT_SENS_1 == 1) && (i==4))
	{
		i++;
	}
	if((BR_PLT_SENS_1 == 0) && (i==5))
	{
		i++;
	}
	if((BR_PLT_SENS_1 == 1) && (i==6))
	{
		i++;
	}
	
	if(i==7)
	{
		BR_CNV=0;
		BR_PLT_BELT_1 = 0;
		i++;
	}
	while((BR_PLT_PUSH_DID_1 == 1) && (i==8))
	{
		BR_PLT_PUSH_1 = 1;
	}
	if((i==8) && (BR_PLT_PUSH_DID_1 == 0))
	{
		i++;
	}
	if((i==9) && (BR_PLT_PUSH_DID_1 == 1))
	{
		BR_PLT_PUSH_1 = 0;
		i++;
	}
	if(BR_PLT_SENS_1 == 1 && (i==10))
	{
		BR_CNV=1;
		BR_PLT_BELT_1 = 1;
		i++;
	}
	if((BR_PLT_SENS_1 == 0) && (i==11))
	{	
		i++;
	}
	if((BR_PLT_SENS_1 == 1) && (i==12))
	{
		i++;
	}
	if((BR_PLT_SENS_1 == 0) && (i==13))
	{
		i++;
	}
	if((BR_PLT_SENS_1 == 1) && (i==14))
	{
		i++;
	}
	if((BR_PLT_SENS_1 == 0) && (i==15))
	{
		i++;
	}
	if((BR_PLT_SENS_1 == 1) && (i==16))
	{
		i++;
	}
	
	if(i==17)
	{
		BR_CNV=0;
		BR_PLT_BELT_1 = 0;
		i++;
	}
	while((BR_PLT_PUSH_DID_1 == 1) && (i==18))
	{
		BR_PLT_PUSH_1 = 1;
	}
	if((i==18) && (BR_PLT_PUSH_DID_1 == 0))
	{
		i++;
	}
	if((i==19) && (BR_PLT_PUSH_DID_1 == 1))
	{
		BR_PLT_PUSH_1 = 0;
		i++;
	}
	if((BR_PLT_PUSH_DID_1 == 1) && (i==20))
	{
		BR_PLT_CLAMP_1 = 1;
	}
	if((i==20) && (BR_PLT_CLAMP_DID_1 == 0))
	{
		i++;
	}
	if((i==21) && (BR_PLT_CLAMP_DID_1 == 1))
	{
		i++;
	}
	if((BR_PLT_PLATE_DID_1 == 1) && (i==22))
	{
		BR_PLT_PLATE_1 = 1;
		i++;
	}
	if((i==23) && (BR_PLT_PLATE_DID_1 == 0))
	{
		i++;
	}
	if((i==24) && (BR_PLT_PLATE_DID_1 == 1))
	{
		BR_PLT_EL_FULL = 0;
		BR_PLT_DOWN = 1;
		i++;
	}
	if((i==25)&&(BR_PLT_EL_MOVING == 0))
	{
		i++;
	}
	if((i==26)&&(BR_PLT_EL_MOVING == 1))
	{
		i++;
	}
	if((i==27)&&(BR_PLT_EL_MOVING == 0))
	{
		BR_PLT_CLAMP_1 = 0;
		BR_PLT_PLATE_1 = 0;
		BR_PLT_DOWN = 0;
		i=0;
		go++;
	}
	if(go==2)
	{
		BR_PLT_EL_FULL = 1;
		go++;
	}
	if(go==3)
	{
		BR_PLT_DOWN = 1;
		go++;
	}
	if((go==4)&&(BR_PLT_EL_MOVING == 1))
	{
		go++;
	}
	if((go==5)&&(BR_PLT_EL_MOVING == 0))
	{
		BR_PLT_GO = 1;
		BR_PLT_DOWN = 0;
		go++;
	}
	if((BR_PLT_FRONT == 1) && (BR_PLT_BACK == 0))
	{
		BR_PLT_CNV=1;
		k=0;
	}
}

void _EXIT ProgramExit(void)
{
	// Insert code here 

}
