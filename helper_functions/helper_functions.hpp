/**
 * @file helper_functions.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file holds all the functions that are not specified for a class, but are needed
 * throughout the code as helpers
 * @version 0.1
 * @date 2020-03-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___HELPER_FUNCTIONS_H___
#define ___HELPER_FUNCTIONS_H___
#include "lua_handler.hpp"
using namespace MassCalculator::HelperClasses;

#include <sstream>

/**
 * @brief Stringify a string macro (Used to stringify the path parset from cmake)
 * 
 */
#define stringify(a) #a

/**
 * @brief Caller for stringify macro
 * 
 */
#define xstr(a) stringify(a)

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  /**
   * @brief HelperClasses namespace
   * 
   */
  namespace HelperFunctions
  {
    /**
     * @brief Helper function to initialize the Lua script
     * 
     * @param lua_state Lua state as forwarded reference
     * @param config_path Lua script path 
     * @return true if init is successful
     * @return false if init failed
     */
    bool initLuaConfig(LuaScriptHandler &&lua_state, const std::string &config_path);

    /**
     * @brief Helper function to check from Lua script
     * 
     * @param lua_state Lua state as forwarded reference
     * @param value Lua parameter that we want to check
     * @return true if parameter is true
     * @return false if parameter is false
     */
    bool checkFromLuaConfig(LuaScriptHandler &&lua_state, const std::string &value);

    /**
     * @brief Template helper function to get the value from Lua config in the datatype we want
     * 
     * @tparam TLuaReturnType Return type we want
     * @param lua_state Lua state as forwarded reference
     * @param value Lua parameter that we want to get
     * @return constexpr TLuaReturnType 
     */
    template<typename TLuaReturnType>
    constexpr TLuaReturnType getFromLuaConfig(LuaScriptHandler &&lua_state, const std::string &value)
    {
      return lua_state.get<TLuaReturnType>(value);
    }

    /**
     * @brief Get the Debug Lua Root Path object
     * 
     * @return const std::string 
     */
    const std::string getDebugLuaRootPath(void);

    /**
     * @brief Function to destroy the lua state and clean the stack
     * 
     * @param lua_state 
     */
    void destroyLuaConfig(LuaScriptHandler *lua_state);

    /**
     * @brief Template ternary operator, you can specify with template the return type
     * 
     * @tparam Data type
     * @param b Condition
     * @param x Return if true
     * @param y Return if false
     * @return T& Type as reference from template type
     */
    template<class T> T& TTernaryOperator(bool b, T&x, T&y) { return b ? x : y; }

    /**
     * @brief const Template ternary operator, you can specify with template the return type
     * 
     * @tparam Data type
     * @param b Condition
     * @param x Return if true
     * @param y Return if false
     * @return T& Type as reference from template type
     */
    template<class T> const T& TTernaryOperator(bool b, const T&x, const T&y) { return b ? x : y; }

    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName(void);

    /**
     * @brief Get the Version object
     * 
     * @return std::string with the library verison
     */
    std::string getVersion(void);
  }// End namespace HelperFunctions
}// End namespace MassCalculator
#endif