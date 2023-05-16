
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	i=0;
	n=0;
}

void _CYCLIC ProgramCyclic(void)
{
	if((go==6)&(i==0))
	{
		BR_CRANE_CONV_1 = 1;
		go=0;
		i++;
	}
	if((i==1)&&(BR_CRANE_SENS_1==1))
	{
		BR_CRANE_CONV_1 = 0;
		BR_CRANE_LEFT_1 = 1;
		i++;
	}
	if((i==2)&&(BR_CRANE_LIM_LEFT_1==1))
	{
		BR_CRANE_LIFT_1 = 1;
		i++;
	}
	if((i==3)&&(BR_CRANE_MOVING_Z_1==1))
	{
		BR_CRANE_LEFT_1 = 0;
		i++;
	}
	if((i==4)&&(BR_CRANE_LIM_MIDDLE_1==1))
	{
		while(crane_1_space[n]!=0)
		{
			n++;
		}
		crane_1_space[n] = 1;
		BR_CRANE_TG_POS_1 = (n+1);
		n=0;
		i++;
	}
	if((i==5)&&(BR_CRANE_MOVING_Z_1==1)&&(BR_CRANE_MOVING_X_1==1))
	{
		i++;
	}
	if((i==6)&&(BR_CRANE_MOVING_Z_1==0)&&(BR_CRANE_MOVING_X_1==0))
	{
		BR_CRANE_RIGHT_1 = 1;
		i++;
	}
	if((i==7)&&(BR_CRANE_LIM_RIGHT_1==1))
	{
		BR_CRANE_LIFT_1 = 0;
		i++;
	}
	if((i==8)&&(BR_CRANE_MOVING_Z_1==1))
	{
		i++;
	}
	if((i==9)&&(BR_CRANE_MOVING_Z_1==0))
	{
		BR_CRANE_RIGHT_1 = 0;
		i++;
	}
	if((i==10)&&(BR_CRANE_LIM_MIDDLE_1==1))
	{
		BR_CRANE_TG_POS_1 = 55;
		i=0;
	}
}

void _EXIT ProgramExit(void)
{

}

