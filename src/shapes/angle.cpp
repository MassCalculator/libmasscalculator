#include "shapes/angle.hpp"

namespace MassCalculator::Shapes
{

  Angle::Angle(double side, double length)
  {
    std::cout << "From constructor: " << side * length << std::endl;
  }

  bool Angle::setSize(double side, double length)
  {
    std::cout << "I just set the size of Angle\n"
              << 4 * side * length << std::endl;

    this->properties_.side_ = side;
    this->properties_.length_ = length;

    return true;
  }

  //TODO:
  double Angle::getDiagonal(void) const
  {
    return this->properties_.side_/2;
  }

  double Angle::getSide(void) const
  {
    return this->properties_.side_;
  }

  double Angle::getLength(void) const
  {
    return this->properties_.length_;
  }

  //TODO:
  double Angle::getVolume(void) const
  {
    //Volume π*r^2*h. Note: diameter = 2 * r	(Note: Check for Eigen if there are build in functions to calculate, and use those instead) TODO:
    return (M_PI * std::pow(this->getSide(), 2) * this->getLength());
  }

  double Angle::getSurfaceArea(void) const
  {
    //2	π	r	 (	r	+	h	)
    return (2 * M_PI * this->getSide() * (this->getSide() + this->getLength()));
  }

  std::string Angle::getType(void) const
  {
    return this->properties_.type_.first;
  }

  std::ostream &operator << (std::ostream &os, const Angle &obj)
  {
    os << "  Angle object properties: " "\n"
          "   - Radius  : " + std::to_string(obj.getDiagonal()) + "\n"
          "   - Diameter: " + std::to_string(obj.getSide()) + "\n"
          "   - Length  : " + std::to_string(obj.getLength()) + "\n"
          "   - Volume  : " + std::to_string(obj.getVolume()) + "\n"
          "   - Surface area: " + std::to_string(obj.getSurfaceArea()) + "\n";
    return os;
  }

}//end namespace MassCalculator::Shapes