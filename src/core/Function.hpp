#ifndef FUNCTION_HPP
#define FUNCTION_HPP


#include <memory>
#include <vector>
#include <iostream>
#include "Set.hpp"



/**
 * @brief ...
 */
namespace Math::Core { //=======================================================
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -	
class FunctionArgument;
class Variable;
class Function;
class Expression;
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
using _ArgPtr = std::shared_ptr<FunctionArgument>;
using _VarPtr = std::shared_ptr<Variable>;
//==============================================================================
/**
 * @brief Instances of this class are valid arguments for a function or 
 * expression
 */
class FunctionArgument {
private:
	virtual std::ostream& print(std::ostream& out) const = 0;

public:
	friend std::ostream& operator<<(std::ostream& out, const FunctionArgument& functionArg);
};
//==============================================================================
/**
 * @brief A variable used as a function argument
 */
class Variable: public FunctionArgument {
public:
	explicit Variable(const std::string& name);

	bool isName(const std::string& name);
	std::ostream& print(std::ostream& out) const;

	friend std::ostream& operator<<(std::ostream& out, const Variable& variable);

private:
	std::string name;
};
//==============================================================================
/**
 * @brief Defines a function with its expression if it exists
 */
class Function: public Element {
public:
	//Function(const Function&) = delete;
	explicit Function(const std::string name, std::initializer_list<const std::string> variableNames);
	explicit Function(const std::string name, std::vector<std::string>& variableNames);
	

	_ArgPtr operator()(std::initializer_list<_ArgPtr> arguments);
	_ArgPtr operator()(std::vector<_ArgPtr>& arguments);
	Function& operator=(const _ArgPtr& expression);
	/**
	 * @brief Get a pointer to a function argument corresponding to a certain 
	 * 	string
	 * 
	 * @param variableName: name of the function argument
	 * @return function argument object
	 */
	_ArgPtr get(const std::string& variableName) const;
	const std::string& getName() const;


	std::ostream& printExpression(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const Function& function);

private:
	std::vector<_VarPtr> variables;
	_ArgPtr expression;
};
//==============================================================================
/**
 * @brief An expression used to define a function
 */
class Expression: public FunctionArgument {
public:
	explicit Expression(const Function* function, std::vector<_ArgPtr>& arguments);
	explicit Expression(const Function* function, std::initializer_list<_ArgPtr> arguments);


	std::ostream& print(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const Expression& expr);

private:
	const Function* function;
	std::vector<_ArgPtr> arguments;
};
} // namespace Math::Core ======================================================

#endif // FUNCTION_HPP