/**
        @file
        @brief Sample using the VirtuoseAPI and the vpp header to
        provide a very simple haptics application.

        @date 2013

        @author
        Ryan Pavlik
        <rpavlik@iastate.edu> and <abiryan@ryand.net>
        http://academic.cleardefinition.com/
        Iowa State University Virtual Reality Applications Center
        Human-Computer Interaction Graduate Program
*/

//          Copyright Iowa State University 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// Internal Includes
// - none

// Library/third-party includes
#include <vpp.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <Eigen/Core>

// Standard includes
#include <string>
#include <iostream>

static const std::string address = "127.0.0.1";

double stiffness = 300;

/// The first time we get run, we save that position as the goal
/// then apply forces to attempt to restore to that point after.
bool hasRun = false;
Eigen::Vector3f goal;

void callback(VirtContext vc, void *data) {
    Virtuose v(vc);    // "Borrow" this vc and wrap it in a Virtuose object.
    float position[7]; // x, y, z, qw, qx, qy, qz
    v.getPosition(position);

    if (!hasRun) {
        // On first loop, record the position
        goal = Eigen::Vector3f::Map(position);
        hasRun = true;
    }

    float forcetorque[6] = { 0 };
    Eigen::Vector3f::Map(forcetorque) =
        (goal - Eigen::Vector3f::Map(position)) * stiffness;
    v.setForce(forcetorque);
}

int main() {
    boost::shared_ptr<Virtuose> v;
    try {
        v = boost::make_shared<Virtuose>(address);
    }
    catch (std::exception &e) {
        std::cerr << "Error! " << e.what() << std::endl;
        return 1;
    }

    v->setCommandType(COMMAND_TYPE_IMPEDANCE);
    v->enableForceFeedback(1);
    v->setPowerOn(1);

    float period = 0.001;
    v->setPeriodicFunction(callback, &period, NULL);
    v->startLoop();

    while (true) {
    }
    v->stopLoop();

    return 0;
}
