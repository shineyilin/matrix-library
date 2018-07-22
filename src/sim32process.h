/*
 * sim32process.h
 *
 *  Created on: 2018年6月26日
 *      Author: admin
 */

#ifndef SIM32PROCESS_H_
#define SIM32PROCESS_H_

#include "point2dprocess.h"

namespace std {

/*
 *
 */
class sim32process {
public:
	sim32process();
	virtual ~sim32process();
public:
	//初始化参数
	bool initParamData();
	//set parameter entry

	bool setDelta_TimeData	(FLOAT delta_time);
	bool setU_DistanceData	(FLOAT u_diatence);
	bool setL_DistanceData	(FLOAT l_distance);
	bool setRL_Data_ListData(POINT2D_LIST rl_data_list);
	bool setE_SpeedData		(FLOAT e_speed);
	// initial simulation process function
	bool initSimProcess		(	FLOAT 		u_distance,
								FLOAT 		l_distance,
								FLOAT 		delta_time,
								FLOAT		e_speed,
								POINT2D_LIST rl_data_list );
	// simulation main function
	void simRun			(	);
private:
	bool simMainEntry	(	);
	bool calcTheta		(	);
	bool calcLength 	(  	);
	bool calcL_Distance	(	);
	bool calcCurrentTime(	);

	bool resetSimProcess();
private:
	POINT2D_LIST 	RL_Data_List;

	FLOAT  			Run_Time;
	FLOAT  			Current_Time;
	FLOAT  			Delta_Time;

	POINT2D			Current_Node;
	POINT2D			Current_Node_Speed;
	POINT2D_LIST    Calc_Node_List;
	POINT2D_LIST    Calc_Node_Speed_List;

private:
	FLOAT  			Radius;
	FLOAT 			U_Distance;
	FLOAT			L_Distance;
	FLOAT			E_Speed;
	FLOAT			Current_Length;
	FLOAT			Max_Length;
	bool 			Start_Flag;

private:
	point2dprocess point2dprocess_hand;
};

} /* namespace std */

#endif /* SIM32PROCESS_H_ */
