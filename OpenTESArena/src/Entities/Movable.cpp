#include <cassert>
#include <cmath>

#include "Movable.h"

Movable::Movable(const Float3d &velocity)
{
	this->velocity = velocity;
}

Movable::~Movable()
{

}

const Float3d &Movable::getVelocity() const
{
	return this->velocity;
}

void Movable::setVelocity(const Float3d &velocity)
{
	assert(std::isfinite(velocity.length()));
	this->velocity = velocity;
}
