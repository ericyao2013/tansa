#include <tansa/control.h>



HoverController::HoverController(Vehicle *v) {
	this->vehicle = v;
	this->point = Point(0,0,0);
}

void HoverController::control(double t) {
	// This is already built into PX4, so we will let it handle staying in one spot
	// Precision over speed should considered when calibrating the PX4 position controller

	vehicle->setpoint_pos(point);
}

double HoverController::distance() {
	VectorXd e(6);
	e << (point - vehicle->state.position),
	     (Vector3d(0,0,0) - vehicle->state.velocity);

	return e.norm();
}
