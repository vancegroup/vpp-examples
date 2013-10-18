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

// Standard includes
#include <string>

static const std::string address = "127.0.0.1";

int main() {
    boost::shared_ptr<Virtuose> v;
    try {
        v = boost::make_shared<Virtuose>(address);
    } catch (std::exception & e) {
        std::cerr << "Error! " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
