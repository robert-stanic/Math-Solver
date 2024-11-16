#ifndef SET_HPP
#define SET_HPP


#include <string>
#include <iostream>
#include <memory>



/**
 * @brief Contains components related to MyProject.
 */
namespace Math::Core { //=======================================================
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -	
class Element;
class Set;
class ParametricSet;
//==============================================================================
/**
 * @brief ...
 */
class Element {
public:
	explicit Element(const std::string& name);

	friend std::ostream& operator<<(std::ostream& out, const Element& element);

protected:
	std::string name;
};
//==============================================================================
/**
 * @brief ...
 */
class Set: Element {
public:
	explicit Set(const std::string& name);
	
	friend std::ostream& operator<<(std::ostream& out, const Set& set);
};
//==============================================================================
/**
 * @brief ...
 */
class ParametricSet: Set {
public:
	explicit ParametricSet(const std::string& name);
	
	friend std::ostream& operator<<(std::ostream& out, const ParametricSet& set);
private:
	std::unique_ptr<Function> function;
};
} // namespace Math::Core ======================================================

#endif // SET_HPP