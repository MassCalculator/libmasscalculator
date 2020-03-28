/**
 * @file brass_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Brass, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-08-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "materials/brass.hpp"
#include <gtest/gtest.h>

// The fixture for testing class Brass.
class BrassTest : public ::testing::Test 
{
  protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  BrassTest() 
  {
   // You can do set-up work for each test here.
   material_B_240Low.setType(MassCalculator::Materials::Brass::Type::B_240Low);
  }

  ~BrassTest() override 
  {
   // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override 
  {
   // Code here will be called immediately after the constructor (right
   // before each test).
  }

  void TearDown() override 
  {
   // Code here will be called immediately after each test (right
   // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
  MassCalculator::Materials::Brass material_B_240Low;
};