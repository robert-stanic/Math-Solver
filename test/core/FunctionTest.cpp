

#define DEBUG_MODE
#define LOG_LEVEL 5
//#include "Assert.hpp"
#include "Function.hpp"

#include <memory>




namespace FunctionTest {



void Constructor() {
	using namespace Math::Core;


/* What we expect to write:

	Function f("f", {"x", "y"});
	Function g("g", {"x", "y"});
	g = f(g.get("x"), f(g.get("y"), g.get("x")));

	Function h("h", {"x", "y", "z"});
	h = g(h.get("z"), f(h.get("y"), h.get("x")));


	int val = g(2, 3);	// Evaluate function

*/	

	Function f = Function("f", {"x", "y"});
	Function g("g", {"x", "y"});
	g = f({ g.get("x"), f({ g.get("y"), g.get("x") }) });

	Function h("h", {"x", "y", "z"});
	h = g({h.get("z"), f({h.get("y"), h.get("x")})});


	//Function u("u", {"x"});
	//u = f({u.get("x"), u.get("y")});		// Runtime error: y is an ivalid argument for u


	std::cout << "Function: " << f << std::endl;
	std::cout << "Function: " << g << " = ";
	g.printExpression(std::cout) << std::endl;
	std::cout << "Function: " << h << " = ";
	h.printExpression(std::cout) << std::endl;



	Function v("v", {"x"});
	std::vector<std::shared_ptr<FunctionArgument>> vec;
	vec.reserve(2);
	vec.push_back(v.get("x"));
	vec.push_back(v.get("x"));
	v = f(vec);		// Runtime error: y is an ivalid argument for u

	std::cout << "Function: " << v << " = ";
	v.printExpression(std::cout) << std::endl;


	//Variable v("aa");
	//std::cout << "Variable: " << v << std::endl;

}




}




int main() {
	using namespace FunctionTest;

	Constructor();


}


