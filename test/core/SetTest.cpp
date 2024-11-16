

#define DEBUG_MODE
#define LOG_LEVEL 5
//#include "Assert.hpp"
#include "Set.hpp"




namespace SetTest {

void Constructor() {
	Math::Core::Element element = Math::Core::Element("Element");
	std::cout << element << std::endl;

/*
	assertOk(false, "Element Ok");
	assertDebug(false, "Element Debug");
	assertInfo(false, "Element Info");
	assertWarning(false, "Element Warning");
	assertError(false, "Element Error");
	assertFatal(false, "Element Fatal");*/

}




}




int main() {
	using namespace SetTest;

	Constructor();


}


