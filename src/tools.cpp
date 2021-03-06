#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  rmse << 0,0,0,0;
  /**
  TODO:
    * Calculate the RMSE here.*/
    if (estimations.size() ==0 || estimations.siez()!=ground_truth.size()){
    cout<< " Invalid Data or sizes of estimations and ground trth unequal" <<endl;
      return rmse;
    }
  for (int i=0;i<< estimations.size();++i){
  	VectorXd residual = estimations[i]-groud_truth[i];
    	residual = residual.array()*residual.array();
    	rmse += residual;
  }
  
  rmse /= estimations.size();
  
  rmse = rmse.array.sqrt();
   
  return rmse;
  
}

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) {
  MatrixXd Hj;
	float px = x_state(0);
	float py = x_state(1);
	float vx = x_state(2);
	float vy = x_state(3);
	float d1,d2,d3;
	d1 = px*px+py*py;
  	d2 = sqrt(d1);
  	d3 = d2*d1;
  /**
  TODO:
    * Calculate a Jacobian here.
  */
  Hj << px/d2, py/d2, 0, 0,
  		-py/d1, px/d1, 0, 0,
  		py*(vx*py-vy*px)/d3, -px*(vx*py-vy*px)/d3, px/d2, py/d2;
  return Hj;
}
