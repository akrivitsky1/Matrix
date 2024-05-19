//
// Created by mfbut on 11/19/2019.
//

#include "VectorTesting.h"
#include "gmock/gmock.h"

//====Methods defined in ConstBaseVector=====

//element reads
TEST_F(VectorTesting, VectorAtRead){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{12, 45, -89, 64, -1325};
  Vector v1(inV1), v2(inV2);

  for (unsigned int i = 0; i < inV1.size(); ++i) {
    ASSERT_EQ(v1.at(i), inV1.at(i));
  }

  for (unsigned int i = 0; i < inV2.size(); ++i) {
    ASSERT_EQ(v2.at(i), inV2.at(i));
  }
}

TEST_F(VectorTesting, VectorBracketRead){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{12, 45, -89, 64, -1325};
  Vector v1(inV1), v2(inV2);

  for (unsigned int i = 0; i < inV1.size(); ++i) {
    ASSERT_EQ(v1[i], inV1.at(i));
  }

  for (unsigned int i = 0; i < inV2.size(); ++i) {
    ASSERT_EQ(v2[i], inV2.at(i));
  }
}

//arithmetic methods
TEST_F(VectorTesting, VectorNegate){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{12, 45, -89, 64, -1325};
  Vector v1(inV1), v2(inV2);

  ASSERT_THAT(-v1, ElementsAre(-1,-2,-3));
  ASSERT_THAT(-v2, ElementsAre(-12, -45, 89, -64, 1325));
}


TEST_F(VectorTesting, VectorPlusVector){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{10, 20, 30};
  Vector v1(inV1), v2(inV2);
  Vector sum1 = v1 + v2;
  ASSERT_THAT(sum1 , ElementsAre(11, 22, 33));
  ASSERT_THAT(v1, ElementsAreArray(inV1));
  ASSERT_THAT(v2, ElementsAreArray(inV2));
}

TEST_F(VectorTesting, VectorMinusVector){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{10, 20, 30};
  Vector v1(inV1), v2(inV2);
  Vector diff = v1 - v2;
  ASSERT_THAT(diff , ElementsAre(-9, -18, -27));
  ASSERT_THAT(v1, ElementsAreArray(inV1));
  ASSERT_THAT(v2, ElementsAreArray(inV2));
}

TEST_F(VectorTesting, VectorTimesVector){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{10, 20, 30};
  Vector v1(inV1), v2(inV2);
  Vector prod = v1 * v2;
  ASSERT_THAT(prod , ElementsAre(140));
  ASSERT_THAT(v1, ElementsAreArray(inV1));
  ASSERT_THAT(v2, ElementsAreArray(inV2));
}

TEST_F(VectorTesting, VectorEqualToVector){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{10, 20, 30};
  Vector v1(inV1), v2(inV2), v3(v1), v4(v2);

  //you should be equal to yourself
  ASSERT_EQ(v1, v1);
  ASSERT_EQ(v2, v2);
  ASSERT_EQ(v3, v3);
  ASSERT_EQ(v4, v4);

  //you should be equal to your copy
  ASSERT_EQ(v1, v3);
  ASSERT_EQ(v2, v4);

  //you shouldn't be equal to anything else
  ASSERT_FALSE(v1 == v2);
  ASSERT_FALSE(v1 == v4);
  ASSERT_FALSE(v3 == v2);
  ASSERT_FALSE(v3 == v4);
}

TEST_F(VectorTesting, VectorNotEqualVector){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{10, 20, 30};
  Vector v1(inV1), v2(inV2), v3(v1), v4(v2);
  ASSERT_NE(v1, v2);
  ASSERT_NE(v1, v4);
  ASSERT_NE(v3, v2);
  ASSERT_NE(v3, v4);


  //you should be equal to yourself
  ASSERT_FALSE(v1 != v1);
  ASSERT_FALSE(v2 != v2);
  ASSERT_FALSE(v3 != v3);
  ASSERT_FALSE(v4 != v4);

  //you should be equal to your copy
  ASSERT_FALSE(v1 !=  v3);
  ASSERT_FALSE(v2 !=  v4);
}


TEST_F(VectorTesting, VectorPlusScalar) {
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1, 2, 3}, inV2{10, 20, 30, 40};
  Vector v1(inV1), v2(inV2);
  ASSERT_THAT(v1 + 7, ElementsAre(8, 9, 10));
  ASSERT_THAT(v2 + 100, ElementsAre(110, 120, 130, 140));

  ASSERT_THAT(v1, ElementsAreArray(inV1));
  ASSERT_THAT(v2, ElementsAreArray(inV2));
}

TEST_F(VectorTesting, ScalarPlusVector) {
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1, 2, 3}, inV2{10, 20, 30, 40};
  Vector v1(inV1), v2(inV2);
  ASSERT_THAT(7 + v1, ElementsAre(8, 9, 10));
  ASSERT_THAT(100 + v2 , ElementsAre(110, 120, 130, 140));

  ASSERT_THAT(v1, ElementsAreArray(inV1));
  ASSERT_THAT(v2, ElementsAreArray(inV2));
}

TEST_F(VectorTesting, VectorMinusScalar) {
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1, 2, 3}, inV2{10, 20, 30, 40};
  Vector v1(inV1), v2(inV2);
  ASSERT_THAT(v1 - 7, ElementsAre(-6, -5, -4));
  ASSERT_THAT(v2 - 100, ElementsAre(-90, -80, -70, -60));

  ASSERT_THAT(v1, ElementsAreArray(inV1));
  ASSERT_THAT(v2, ElementsAreArray(inV2));
}

TEST_F(VectorTesting, ScalarMinusVector) {
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1, 2, 3}, inV2{10, 20, 30, 40};
  Vector v1(inV1), v2(inV2);
  ASSERT_THAT(7 - v1, ElementsAre(6, 5, 4));
  ASSERT_THAT(100 - v2 , ElementsAre(90, 80, 70, 60));

  ASSERT_THAT(v1, ElementsAreArray(inV1));
  ASSERT_THAT(v2, ElementsAreArray(inV2));
}


TEST_F(VectorTesting, VectorTimesScalar) {
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1, 2, 3}, inV2{10, 20, 30, 40};
  Vector v1(inV1), v2(inV2);
  ASSERT_THAT(v1 * 7, ElementsAre(7, 14, 21));
  ASSERT_THAT(v2 * 100, ElementsAre(1000, 2000, 3000, 4000));

  ASSERT_THAT(v1, ElementsAreArray(inV1));
  ASSERT_THAT(v2, ElementsAreArray(inV2));
}

TEST_F(VectorTesting, ScalarTimesVector) {
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1, 2, 3}, inV2{10, 20, 30, 40};
  Vector v1(inV1), v2(inV2);
  ASSERT_THAT(7 * v1 , ElementsAre(7, 14, 21));
  ASSERT_THAT(100 * v2 , ElementsAre(1000, 2000, 3000, 4000));

  ASSERT_THAT(v1, ElementsAreArray(inV1));
  ASSERT_THAT(v2, ElementsAreArray(inV2));
}
