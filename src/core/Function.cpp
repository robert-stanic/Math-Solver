#include "Function.hpp"
#include <algorithm>
#include <stdexcept>
//#include <memory>


namespace Math::Core { //=======================================================
//==============================================================================
// FunctionArgument implementation
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::ostream& operator<<(std::ostream& out, const FunctionArgument& functionArg) {
    return functionArg.print(out);
}
//==============================================================================
//==============================================================================
// Variable implementation
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Variable::Variable(const std::string& name): name(name) {}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool Variable::isName(const std::string& name) {
    return this->name == name;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::ostream& Variable::print(std::ostream& out) const {
    out << name;
    return out;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::ostream& operator<<(std::ostream& out, const Variable& variable) {
    return variable.print(out);
}
//==============================================================================
//==============================================================================
// Function implementation
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Function::Function(const std::string name, std::vector<std::string>& variableNames)
: Element(name) {
    variables.reserve(variableNames.size());
		
    for(const auto& name: variableNames) {
        variables.push_back(std::make_shared<Variable>(name));
    }

    expression = nullptr;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Function::Function(const std::string name, std::initializer_list<const std::string> variableNames)
: Element(name) {
    variables.reserve(variableNames.size());

    for(const auto& name: variableNames) {
        variables.push_back(std::make_shared<Variable>(name));
    }

    expression = nullptr;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
_ArgPtr Function::operator()(std::vector<_ArgPtr>& arguments) {
    return std::make_shared<Expression>(this, arguments);
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
_ArgPtr Function::operator()(std::initializer_list<_ArgPtr> arguments) {
    return std::make_shared<Expression>(this, arguments);
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Function& Function::operator=(const _ArgPtr& expression) {
    this->expression = expression;
    return *this;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
_ArgPtr Function::get(const std::string& variableName) const {
    auto it = std::find_if(variables.begin(), variables.end(), 
        [variableName] (auto& varPtr) { return varPtr->isName(variableName); } );

    // Checking if element is found or not
    if (it != variables.end()) {
        return *it;
    }
    throw std::runtime_error("'" + variableName + "' is an invalid argument for function '" + name + "'");
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const std::string& Function::getName() const {
    return name;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::ostream& Function::printExpression(std::ostream& out) const {
    out << *expression;
    return out;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::ostream& operator<<(std::ostream& out, const Function& function) {
    out <<  function.name << "[";

    auto it = function.variables.begin();
    if(it != function.variables.end()) {
        out << **it;
    }

    ++it;
    for(; it != function.variables.end(); ++it){
        out << "," << **it;
    }

    return out << "]";
}
//==============================================================================
//==============================================================================
// Expression implementation
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Expression::Expression(const Function* function, std::vector<_ArgPtr>& arguments)
: function(function), arguments(arguments) { }
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Expression::Expression(const Function* function, std::initializer_list<_ArgPtr> arguments)
: function(function), arguments(arguments) { }
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::ostream& Expression::print(std::ostream& out) const {
    out << function->getName() << "[";

    auto it = arguments.begin();

    if(it !=arguments.end()) {
        out << **it;
    }

    ++it;
    for(; it != arguments.end(); ++it){
        out << "," << **it;
    }
    out << "]";

    return out;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::ostream& operator<<(std::ostream& out, const Expression& expr) {
    return expr.print(out);
}
//==============================================================================
} // namespace Math::Core ======================================================

