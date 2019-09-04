#ifndef ___BRONZ_H___
#define ___BRONZ_H___
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
   * @brief Class Bronz, that holds all the nessesary information for Bronz and it's types therefore we can use in the interface
   * 
   */
  class Bronz : public Material<Bronz>
  {
    public: enum class Type : uint8_t;

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    struct Properties
    {

      /**
       * @brief Private members of Bronz class. Values defaulted with brace-enclosed initializer list
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
      std::pair<std::string, Type> type_{"UNSPECIFIED", Bronz::Type::UNSPECIFIED};
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
     * @brief Enum that holds the Bronz types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     * TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,
      /**
       * @brief This grade is commercially pure Bronz. It is soft and ductile and has excellent workability, making it ideal for applications with difficult forming. 
       * It can be welded using any method, but it is non heat-treatable. It has an excellent resistance to corrosion and is commonly used in the chemical and 
       * food processing industries.
       * 
       */
      B_18Al = BEGIN,

      /**
       * @brief High mechanical strength and excellent machining capabilities are the highlights of this grade. It is often called – Free Machining Alloy (FMA), 
       * an excellent choice for projects done on automatic lathes. The high-speed machining of this grade will produce fine chips that are easily removed. 
       * Alloy 2011 is an excellent choice for production of complex and detailed parts.
       * 
       */
      B_21Al,

      /**
       * @brief A copper based alloy with very high strength and excellent machining capabilities. This alloy is commonly used in many aerospace structural applications 
       * due to its resistance.
       * 
       */
      B_314Commercial,

      /**
       * @brief One of the most commonly used high strength aluminum alloys. With its combination of high strength and excellent fatigue resistance, it is commonly used 
       * where a good strength-to-weight ratio is desired.  This grade can be machined to a high finish and it can be formed in the annealed condition with 
       * subsequent heat treating, if needed. The corrosion resistance of this grade is relatively low. When this is an issue, 2024 is commonly used in an 
       * anodized finish or in clad form (thin surface layer of high purity aluminum) known as Alclad.
       * 
       */
      B_425Am,

      /**
       * @brief The most widely used of all aluminum alloys. A commercially pure aluminum with added manganese to increase its strength (20% stronger than the 1100 grade). 
       * It has excellent corrosion resistance, and workability. This grade can be deep drawn or spun, welded or brazed.
       * 
       */
      B_485Naval,

      /**
       * @brief This is the highest strength alloy of the more non heat-treatable grades. Its fatigue strength is higher than most other aluminum grades. 
       * Alloy 5052 has a good resistance to marine atmosphere and salt water corrosion, and excellent workability. It can be easily drawn or formed into intricate shapes.
       * 
       */
      B_510Phos,

      /**
       * @brief The most versatile of the heat-treatable aluminum alloys, while keeping most of the good qualities of aluminum. This grade has a great range of mechanical 
       * properties and corrosion resistance. It can be fabricated by most of the commonly used techniques and it has good workability in the annealed condition. It is 
       * welded by all methods and can be furnace brazed. As a result, it is used in a wide variety of products and applications where appearance and better corrosion 
       * resistance with good strength are required. The Tube and Angle shapes in this grade typically have rounded corners.
       * 
       */
      B_524Phos,

      /**
       * @brief Commonly known as an architectural alloy. It has reasonably high tensile properties, excellent finishing characteristics and a high degree of resistance 
       * to corrosion. Most often found in various interior and exterior architectural applications and trim. It is very well suited for anodizing applications. 
       * Commonly known as an architectural alloy. It has reasonably high tensile properties, excellent finishing characteristics and a high degree of resistance to corrosion. 
       * Most often found in various interior and exterior architectural applications and trim. It is very well suited for anodizing applications. 
       * The Tube and Angle shapes in this grade typically have square corners.The Tube and Angle shapes in this grade typically have square corners.
       * 
       */
      B_532Phos,

      B_534Phos,

      B_544Phos,

      B_613Al,

      B_614Al,

      B_623Al,

      B_624Al,

      B_625Al,

      B_630NiAl,

      B_642AlSi,

      B_932Bearing,

      B_954Al,

      B_OilLite,

      UNSPECIFIED,

      END
    };

    friend std::ostream& operator<<(std::ostream& os, Type type)
    {
        switch(type)
        {
            case Type::B_18Al: os << "B_18Al"; break;
            case Type::B_21Al: os << "B_21Al"; break;
            case Type::B_314Commercial: os << "B_314Commercial"; break;
            case Type::B_485Naval: os << "B_485Naval"; break;
            case Type::B_510Phos: os << "B_510Phos"; break;
            case Type::B_524Phos: os << "B_524Phos"; break;
            case Type::B_532Phos: os << "B_532Phos"; break;
            case Type::B_534Phos: os << "B_534Phos"; break;
            case Type::B_544Phos: os << "B_544Phos"; break;
            case Type::B_613Al: os << "B_613Al"; break;
            case Type::B_614Al: os << "B_614Al"; break;
            case Type::B_623Al: os << "B_623Al"; break;
            case Type::B_624Al: os << "B_624Al"; break;
            case Type::B_625Al: os << "B_625Al"; break;
            case Type::B_630NiAl: os << "B_630NiAl"; break;
            case Type::B_642AlSi: os << "B_642AlSi"; break;
            case Type::B_932Bearing: os << "B_932Bearing"; break;
            case Type::B_954Al: os << "B_954Al"; break;
            case Type::B_OilLite: os << "B_OilLite"; break;
            case Type::UNSPECIFIED: os << "UNSPECIFIED"; break;
            default: os << "Name cannot be found";
        }
        return os;
    }

    /**
     * @brief Construct a new Bronz object
     * 
     */
    Bronz(void) = default;

    /**
     * @brief Construct a new Bronz object and specify the type
     * 
     */
    Bronz(Type type);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the Bronz
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
     * @return const double The specific melting point of Bronz type
     */
    double getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Bronz type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return double The specific thermal conductivity of Bronz type
     */
    double getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return const double The specific modulus of elasticity tension point of Bronz type
     */
    double getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return const double The specific modulus of elasticity torsion point of Bronz type
     */
    double getSpecificModOfElasticityTorsion(void) const;

    /**
     * @brief Destroy the Bronz object
     * 
     */
    ~Bronz(void) = default;

    /**
     * @brief Shift operator overload for class Bronz, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Bronz &obj);

    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    Bronz(const Bronz&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Bronz(Bronz&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Bronz& operator=(const Bronz&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Bronz& operator=(Bronz&&) = default;

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Bronz
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