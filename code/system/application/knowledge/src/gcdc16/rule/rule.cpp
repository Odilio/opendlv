/**
 * Copyright (C) 2015 Chalmers REVERE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */

#include <ctype.h>
#include <cstring>
#include <cmath>
#include <iostream>

#include "opendavinci/odcore/data/Container.h"
#include "opendavinci/odcore/data/TimeStamp.h"

#include "opendlvdata/GeneratedHeaders_opendlvdata.h"

#include "gcdc16/rule/rule.hpp"

namespace opendlv {
namespace knowledge {
namespace gcdc16 {
namespace rule {

/**
* Constructor.
*
* @param a_argc Number of command line arguments.
* @param a_argv Command line arguments.
*/
Rule::Rule(int32_t const &a_argc, char **a_argv)
: DataTriggeredConferenceClientModule(
	a_argc, a_argv, "knowledge-gcdc16-rule"),
	standstillDistance(6), //TODO: Get actual value at GCDC in meters
	headway(1), //TODO: Get actual value at GCDC in seconds
	minimumEuclideanDistance(5) //TODO: Get actual value at GCDC in meters
{
}

Rule::~Rule()
{
}

/**
* Receives .
* Sends .
*/
double Rule::getDistances(double hostVelocity)
{
	double desiredDistance = standstillDistance + headway * hostVelocity;
	//double safeDistance = scalingFactor * desiredDistance;
	//returnVector[0] = desiredDistance;
	//returnvector[1] = safeDistance;
	return desiredDistance;
}

bool Rule::euclideanDistance(double measuredDistance)
{
	double distanceError = measuredDistance - minimumEuclideanDistance;
	if (distanceError >= 0) {
		return true;
	}
	return false;

}
void Rule::nextContainer(odcore::data::Container &)
{
}

void Rule::setUp()
{
}

void Rule::tearDown()
{
}

} // rule
} // gcdc16
} // knowledge
} // opendlv
