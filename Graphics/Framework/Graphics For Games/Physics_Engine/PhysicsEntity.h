/***********************************************************************************************
*	          .--.																		       *
*	::\`--._,'.::.`._.--'/::			@author Ana M. Mihut		@module Physics            *
*	::::. `  __::__ ' .:::::   			@alias  LT-Kerrigan			@date 28.09.2014	       *
*	::::::-:.`'..`'.:-::::::			@link								                   *
*	::::::::\ `--' /::::::::			@detail	Physics Entity properties (hook to SceneNode)  *
*																						       *
************************************************************************************************/

#pragma once
#include "../../nclgl/Quaternion.h"
#include "../../nclgl/Vector3.h"
#include "../../nclgl/Matrix4.h"
#include "../../nclgl/SceneNode.h"


class PhysicsEntity	{
public:
	PhysicsEntity(void);
	PhysicsEntity(Quaternion orientation, Vector3 position);
	~PhysicsEntity(void);

	Vector3		GetPosition()			{ return m_position; }
	Vector3		GetLinearVelocity()		{ return m_linearVelocity; }

	float		GetInverseMass()		{ return m_invMass; }

	Quaternion	GetOrientation()		{ return m_orientation; }
	Vector3		GetAngularVelocity()	{ return m_angularVelocity; }

	Matrix4		BuildTransform();

	virtual void		Update(float msec);

	void	SetTarget(SceneNode *s) { target = s; }

	Vector3	GetForce()	{ return m_force;}
	Vector3	GetTorque() { return m_torque;}

protected:
	
	// Linear motion
	Vector3		m_position;
	Vector3		m_linearVelocity;
	Vector3		m_force;
	float		m_invMass;

	// Angular motion
	Quaternion  m_orientation;
	Vector3		m_angularVelocity;
	Vector3		m_torque;
	Matrix4     m_invInertia;

	SceneNode*	target;
};