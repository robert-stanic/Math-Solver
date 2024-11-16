#include "Set.hpp"





namespace Math::Core {


//Element::Element(char const* name): name(name) {}
Element::Element(const std::string& name): name(name) {}


std::ostream& operator<<(std::ostream &out, const Element &element) {
    return out << element.name;
}





}

