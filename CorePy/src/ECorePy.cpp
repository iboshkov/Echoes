#include "ECore.h"
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(ECorePy)
{
	using namespace boost::python;
	using namespace Echoes;
	class_<Core, boost::noncopyable>("Core")
		.def("initialize", &Core::initialize)
		.def("destroy", &Core::destroy)
		.def("render", &Core::render);
}