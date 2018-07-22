/*
 * sim32process.cpp
 *
 *  Created on: 2018Äê6ÔÂ26ÈÕ
 *      Author: admin
 */

#include "sim32process.h"

namespace std {

sim32process::sim32process() {
	// TODO Auto-generated constructor stub

}


bool sim32process::initParamData()
{
	this->RL_Data_List.clear();
	this->Calc_Node_List.clear();
	this->Calc_Node_Speed_List.clear();
	this->Current_Node.x = 0;
	this->Current_Node.y = 0;

	this->Current_Node_Speed.x = 0;
	this->Current_Node_Speed.y = 0;

	this->Current_Time = 0.0;
	this->Delta_Time   = 0;
	this->L_Distance   = 0;
	this->RL_Data_List.clear();
	this->Radius 		= inf;
	this->Run_Time 		= 0;
	this->U_Distance 	= 0;
	this->E_Speed		= 0;
	this->Max_Length	= 0;
	this->Current_Length= 0;

	this->Start_Flag 	= false;
	return true;
}
bool sim32process::setDelta_TimeData(FLOAT delta_time)
{
	this->Delta_Time = delta_time;
	return true;
}

bool sim32process::setU_DistanceData(FLOAT u_distance)
{
	this->U_Distance = u_distance;
	return true;
}

bool sim32process::setL_DistanceData(FLOAT l_distance)
{
	this->L_Distance = l_distance;
	return true;
}

bool sim32process::setRL_Data_ListData(POINT2D_LIST rl_data_list)
{
	this->RL_Data_List = rl_data_list;
	return true;
}

bool sim32process::setE_SpeedData(FLOAT e_speed)
{
	this->E_Speed = e_speed;
	return true;
}



bool sim32process::initSimProcess(	FLOAT 			u_distance,
									FLOAT 			l_distance,
									FLOAT 			delta_time,
									FLOAT			e_speed,
									POINT2D_LIST 	rl_data_list )
{
	this->initParamData			(	);
	this->setDelta_TimeData		(	delta_time	);
	this->setL_DistanceData		(	l_distance	);
	this->setU_DistanceData		(	u_distance	);
	this->setRL_Data_ListData	(	rl_data_list);
	this->setE_SpeedData		(	e_speed		);

	this->Max_Length = rl_data_list[ rl_data_list.size()-1 ].x;
	point2dprocess_hand.initPoint2DData(rl_data_list);
	return true;
}

bool sim32process::calcTheta()
{

	return true;
}
bool sim32process::calcLength()
{
	this->Current_Length += this->Delta_Time * this->E_Speed;
	return true;
}

bool sim32process::calcCurrentTime()
{
	this->Current_Time 	+= this->Delta_Time;
	return true;
}

void sim32process::simRun()
{
	simMainEntry();
}

bool sim32process::simMainEntry()
{
	this->Start_Flag = true;
	while(this->Start_Flag)
	{

		Current_Length 	+= E_Speed * Delta_Time;
		if (Current_Length > Max_Length)
		{
			this->Start_Flag = false;
			break;
		}
		print(Current_Length);
		print(" ");
		println(point2dprocess_hand.getInsert2DDataEx(Current_Length));
	}
	return true;
}



sim32process::~sim32process() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
