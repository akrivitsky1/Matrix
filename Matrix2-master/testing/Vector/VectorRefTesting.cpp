//
// Created by mfbut on 11/21/2019.
//
#include <algorithm>
#include <functional>
#include "VectorTesting.h"
#include "VectorRef.h"

#include "gmock/gmock.h"

TEST_F(VectorTesting, VectorRefTest){
  using namespace ::testing;
  using namespace Matrix;

  Vector v(3,7);
  VectorRef vr(v);

  for(auto& val : vr){
   val += 4;
  }

  ASSERT_EQ(v, vr);

  for(auto& val : v){
    val *= 2;
  }

  ASSERT_EQ(v, vr);


}
