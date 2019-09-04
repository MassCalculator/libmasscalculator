#ifndef ___NICKEL_H___
#define ___NICKEL_H___
#include "material.hpp"

// Lua is written in C, so compiler needs to know how to link its libraries TODO:
// #include "lua_handler.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  /**
   * @brief Class Nickel, that holds all the nessesary information for Nickel and it's types therefore we can use in the interface
   * 
   */
  class Nickel : public Material<Nickel>
  {
    public: enum class Type : uint8_t;

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    struct Properties
    {

      /**
       * @brief Private members of Nickel class. Values defaulted with brace-enclosed initializer list
       * and will be set from the constructor.
       * 
       * @param type_ Type The parameter to save the specific type
       * @param specific_color_ string Parameter to save specific color
       * @param specific_density_ double Parameter to save specific density
       * @param specific_volume_ double Parameter to save specific volume
       * @param specific_mass_ double Parameter to save specific mass
       * @param specific_weight_ double Parameter to save specific weight
       * @param specific_melting_point_ double Parameter to save specific melting point
       * @param specific_boiling_point_ double Parameter to save specific boiling point
       * 
       */
      std::pair<std::string, Type> type_{"UNSPECIFIED", Nickel::Type::UNSPECIFIED};
      std::string color_{0};
      double density_{0};
      double gravity_{0};
      double melting_point_{0};
      double poissons_ratio_{0};
      double thermal_conductivity{0};
      double mod_of_elasticity_tension_{0};
      double mod_of_elasticity_torsion_{0};
    }specific_properties_;

    public:
    /**
     * @brief Enum that holds the Nickel types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     * TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,
      /**
       * @brief This grade is commercially pure Nickel. It is soft and ductile and has excellent workability, making it ideal for applications with difficult forming. 
       * It can be welded using any method, but it is non heat-treatable. It has an excellent resistance to corrosion and is commonly used in the chemical and 
       * food processing industries.
       * 
       */
      N_201 = BEGIN,

      /**
       * @brief High mechanical strength and excellent machining capabilities are the highlights of this grade. It is often called – Free Machining Alloy (FMA), 
       * an excellent choice for projects done on automatic lathes. The high-speed machining of this grade will produce fine chips that are easily removed. 
       * Alloy 2011 is an excellent choice for production of complex and detailed parts.
       * 
       */
      N_210,

      /**
       * @brief A copper based alloy with very high strength and excellent machining capabilities. This alloy is commonly used in many aerospace structural applications 
       * due to its resistance.
       * 
       */
      N_220,

      /**
       * @brief One of the most commonly used high strength aluminum alloys. With its combination of high strength and excellent fatigue resistance, it is commonly used 
       * where a good strength-to-weight ratio is desired.  This grade can be machined to a high finish and it can be formed in the annealed condition with 
       * subsequent heat treating, if needed. The corrosion resistance of this grade is relatively low. When this is an issue, 2024 is commonly used in an 
       * anodized finish or in clad form (thin surface layer of high purity aluminum) known as Alclad.
       * 
       */
      N_230,

      /**
       * @brief The most widely used of all aluminum alloys. A commercially pure aluminum with added manganese to increase its strength (20% stronger than the 1100 grade). 
       * It has excellent corrosion resistance, and workability. This grade can be deep drawn or spun, welded or brazed.
       * 
       */
      N_400,

      UNSPECIFIED,

      END
    };

    friend std::ostream& operator<<(std::ostream& os, Type type)
    {
        switch(type)
        {
            case Type::N_201: os << "N_201"; break;
            case Type::N_210: os << "N_210"; break;
            case Type::N_220: os << "N_220"; break;
            case Type::N_230: os << "N_230"; break;
            case Type::N_400: os << "N_400"; break;
            case Type::UNSPECIFIED: os << "UNSPECIFIED"; break;
            default: os << "Name cannot be found";
        }
        return os;
    }

    /**
     * @brief Construct a new Nickel object
     * 
     */
    Nickel(void) = default;

    /**
     * @brief Construct a new Nickel object and specify the type
     * 
     */
    Nickel(Type type);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the Nickel
     * @return true If the type is set successfully
     * @return false If the type failed to set
     */
    bool setType(Type type);

    /**
     * @brief Get the Type object
     * 
     * @return const std::pair<std::string, Type> Pair with type name and type enum
     */
    std::pair<std::string, Type> getType(void) const;

    /**
     * @brief Get the Specific Color object
     * 
     * @return const std::string Color of the material
     */
    std::string getSpecificColor(void) const;

    /**
     * @brief Get the Specific Density object
     * 
     * @return const double Density of the material
     */
    double getSpecificDensity(void) const;

    /**
     * @brief Get the Specific Gravity object
     * 
     * @return const double Gravity of the material
     */
    double getSpecificGravity(void) const;

    /**
     * @brief Get the Specific Melting Point object
     * 
     * @return const double The specific melting point of Nickel type
     */
    double getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Nickel type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return double The specific thermal conductivity of Nickel type
     */
    double getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return const double The specific modulus of elasticity tension point of Nickel type
     */
    double getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return const double The specific modulus of elasticity torsion point of Nickel type
     */
    double getSpecificModOfElasticityTorsion(void) const;

    /**
     * @brief Destroy the Nickel object
     * 
     */
    ~Nickel(void) = default;

    /**
     * @brief Shift operator overload for class Nickel, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Nickel &obj);

    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    Nickel(const Nickel&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Nickel(Nickel&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Nickel& operator=(const Nickel&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Nickel& operator=(Nickel&&) = default;

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Nickel
     * @return true If the specifications of propertie are successfully set
     * @return false  If the specifications of propertie failed to set
     */
    bool setPropertieSpecs(Type type);

    //TODO:
    //HelperClasses::LuaHandler lua_state_;

    bool checkFromLuaConfig(std::string value);

    template<typename TLuaReturnType>
    constexpr TLuaReturnType getFromLuaConfig(std::string value);

    template<class T> T& TTernaryOperator(bool b, T&x, T&y) { return b ? x : y; }
    template<class T> const T& TTernaryOperator(bool b, const T&x, const T&y) { return b ? x : y; }

  };
}//end namespace MassCalculator
#endif