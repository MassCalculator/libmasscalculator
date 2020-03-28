#include "materials/nickel.hpp"

namespace MassCalculator::Materials
{
  Nickel::Nickel(void)
  {
    if(!this->initLuaScript())
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  Nickel::Nickel(const Nickel::Type &type)
  {
    if(!setType(type) || !this->initLuaScript())
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool Nickel::initLuaScript(void)
  {
    return this->lua_state_.openScript(Constants::NickelLuaConfigPath);
  }

  bool Nickel::setType(const Nickel::Type &type)
  {
    if(!setPropertieSpecs(type))
    {
      std::cerr << "Cannot set the Nickel type\n";
      return false;
    }
    
    return true;
  }

  std::pair<std::string, Nickel::Type> Nickel::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  std::string Nickel::getSpecificColor(void) const
  {
    return{this->specific_properties_.color_};
  }

  kilograms_per_cubic_meter_t Nickel::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  meters_per_second_squared_t Nickel::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  kelvin_t Nickel::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double Nickel::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  watt_t Nickel::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity_};
  }

  pascal_t Nickel::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  pascal_t Nickel::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  bool Nickel::_setPropertieSpecs(const Properties_t &_properties)
  {
    this->specific_properties_.type_ = {
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        getFromLuaConfig<std::string>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".type"}),
        {_properties.type_.first}
      ), _properties.type_.second};
    this->specific_properties_.color_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        getFromLuaConfig<std::string>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".color"}),
        {_properties.color_}
      );
    this->specific_properties_.density_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".density"})),
        {_properties.density_}
      );
    this->specific_properties_.gravity_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".gravity"})),
        {_properties.gravity_}
      );
    this->specific_properties_.melting_point_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".melting_point"})),
        {_properties.melting_point_}
      );
    this->specific_properties_.poissons_ratio_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".poissons_ratio"}),
        {_properties.poissons_ratio_}
      );
    this->specific_properties_.thermal_conductivity_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".thermal_conductivity"})),
        {_properties.thermal_conductivity_}
      );
    this->specific_properties_.mod_of_elasticity_tension_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".mod_of_elasticity_tension"})),
        {_properties.mod_of_elasticity_tension_}
      );
    this->specific_properties_.mod_of_elasticity_torsion_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".mod_of_elasticity_torsion"})),
        {_properties.mod_of_elasticity_torsion_}
      );
    return true;
  }

  bool Nickel::setPropertieSpecs(const Nickel::Type &type)
  {
    auto _pair = type2func.find(type);

    if(_pair != type2func.end())
    {
      _pair->second();
    }
    else
    {
      std::cerr << "Could not set the values for type: " << type << std::endl;
    }

    return true;
  }

  std::ostream &operator << (std::ostream &os, const Nickel &obj)
  {
    os << "  Nickel object properties: " "\n"
          "   - Type    : " + obj.getType().first + "\n"
          "   - Color   : " + obj.getSpecificColor() + "\n"
          "   - Density : " + units::density::to_string(obj.getSpecificDensity()) + "\n"
          "   - Gravity : " + units::acceleration::to_string(obj.getSpecificGravity()) + "\n"
          "   - Melting point : " + units::temperature::to_string(obj.getSpecificMeltingPoint()) + "\n"
          "   - Poissons ratio: " + std::to_string(obj.getSpecificPoissonsRatio()) + "\n"
          "   - Thermal conductivity         : " + units::power::to_string(obj.getSpecificThermalConductivity()) + "\n"
          "   - Modulus of elasticity tension: " + units::pressure::to_string(obj.getSpecificModOfElasticityTension()) + "\n"
          "   - Modulus of elasticity torsion: " + units::pressure::to_string(obj.getSpecificModOfElasticityTorsion()) + "\n";
    return os;
  }

  std::ostream &operator << (std::ostream &os, const Nickel::Type &type)
  {
    switch(type)
    {
      case Nickel::Type::N_201: os << Constants::N_201; break;
      case Nickel::Type::N_210: os << Constants::N_210; break;
      case Nickel::Type::N_220: os << Constants::N_220; break;
      case Nickel::Type::N_230: os << Constants::N_230; break;
      case Nickel::Type::N_400: os << Constants::N_400; break;
      case Nickel::Type::UNSPECIFIED: os << Constants::UNSPECIFIED; break;
      default: os << "Name cannot be found";
    }
    return os;
  }
}//end namespace MassCalculator