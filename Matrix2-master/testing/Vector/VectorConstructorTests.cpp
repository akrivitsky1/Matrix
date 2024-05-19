//
// Created by mfbut on 11/19/2019.
//

#include "VectorTesting.h"
#include "gmock/gmock.h"

TEST_F(VectorTesting, NumElementsValueConstructor){
using namespace Matrix;
using namespace ::testing;
Vector v1(3, 4), v2(5, 7);
ASSERT_EQ(v1.size(), 3);
ASSERT_EQ(v2.size(), 5);
ASSERT_THAT(v1, ElementsAre(4,4,4));
ASSERT_THAT(v2, ElementsAre(7,7,7,7,7));
}

TEST_F(VectorTesting, NumElementsConstructor){
using namespace Matrix;
using namespace ::testing;
Vector v1(2), v2(8);
ASSERT_EQ(v1.size(), 2);
ASSERT_EQ(v2.size(), 8);
ASSERT_THAT(v1, ElementsAre(0, 0));
ASSERT_THAT(v2, ElementsAre(0,0,0,0,0,0,0,0));
}

TEST_F(VectorTesting, StdVectorConstructor){
using namespace Matrix;
using namespace ::testing;
std::vector<Vector::value_type> inV1{1,2,3}, inV2{12, 45, -89, 64, -1325};
Vector v1(inV1), v2(inV2);
ASSERT_EQ(v1.size(), 3);
ASSERT_EQ(v2.size(), 5);
ASSERT_THAT(v1, ElementsAreArray(inV1));
ASSERT_THAT(v2, ElementsAreArray(inV2));
}
