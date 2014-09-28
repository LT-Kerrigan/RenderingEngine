/***********************************************************************************************
*	          .--.																		       *
*	::\`--._,'.::.`._.--'/::			@author Ana M. Mihut		@module Physics            *
*	::::. `  __::__ ' .:::::   			@alias  LT-Kerrigan			@date 28.09.2014	       *
*	::::::-:.`'..`'.:-::::::			@link								                   *
*	::::::::\ `--' /::::::::			@detail	Physics Entity implementation with hook vertex *
*																						       *
************************************************************************************************/

#include "PhysicsEntity.h"

PhysicsEntity::PhysicsEntity(void)	{
	target = NULL;
}

PhysicsEntity::PhysicsEntity(Quaternion orientation, Vector3 position) {
	m_orientation = orientation;
	m_position = position;
}

PhysicsEntity::~PhysicsEntity(void)	{

}

//You will perform your per-object physics integration, here!
//I've added in a bit that will set the transform of the
//graphical representation of this object, too.
void	PhysicsEntity::Update(float msec) {
	//FUN GOES HERE

	if (target) {
		target->SetTransform(BuildTransform());
	}
}

/*
This function simply turns the orientation and position
of our physics node into a transformation matrix, suitable
for plugging into our Renderer!

It is cleaner to work with matrices when it comes to rendering,
as it is what shaders expect, and allow us to keep all of our
transforms together in a single construct. But when it comes to
physics processing and 'game-side' logic, it is much neater to
have seperate orientations and positions.

*/
Matrix4		PhysicsEntity::BuildTransform() {
	Matrix4 m = m_orientation.ToMatrix();

	m.SetPositionVector(m_position);

	return m;
}