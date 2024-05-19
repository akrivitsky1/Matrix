//
// Created by mfbut on 11/19/2019.
//

#ifndef ECS_36B_HOMEWORK_BASEVECTORTESTS_CPP
#define ECS_36B_HOMEWORK_BASEVECTORTESTS_CPP
//====Methods defined in BaseVector=====

//element writes
#include "VectorTesting.h"
#include "gmock/gmock.h"

TEST_F(VectorTesting, VectorAtWrite){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{12, 45, -89, 64, -1325};
  Vector v1(inV1), v2(inV2);

  for (unsigned int i = 0; i < inV1.size(); ++i) {
    inV1.at(i) += 3;
    v1.at(i)  += 3;
    ASSERT_EQ(v1.at(i), inV1.at(i));
  }

  ASSERT_THAT(v1, ElementsAreArray(inV1));

  for (unsigned int i = 0; i < inV2.size(); ++i) {
    inV2.at(i) -= 3;
    v2.at(i)  -= 3;
    ASSERT_EQ(v2.at(i), inV2.at(i));
  }
  ASSERT_THAT(v2, ElementsAreArray(inV2));
}

TEST_F(VectorTesting, VectorBracketWrite){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{12, 45, -89, 64, -1325};
  Vector v1(inV1), v2(inV2);

  for (unsigned int i = 0; i < inV1.size(); ++i) {
    inV1[i] *= 12;
    v1[i] *= 12;
    ASSERT_EQ(v1[i], inV1.at(i));
  }

  ASSERT_THAT(v1, ElementsAreArray(inV1));

  for (unsigned int i = 0; i < inV2.size(); ++i) {
    inV2[i] += 12;
    v2[i] += 12;
    ASSERT_EQ(v2[i], inV2.at(i));
  }

  ASSERT_THAT(v2, ElementsAreArray(inV2));
}


TEST_F(VectorTesting, VectorIteratorWrite){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3,4,5};
  Vector v1(inV1);

  for(auto& elem : inV1){
    elem *= 10;
  }

  for(auto& elem : v1){
    elem *= 10;
  }

  ASSERT_THAT(v1, ElementsAreArray(inV1));
}



//arithmetic methods
TEST_F(VectorTesting, VectorPlusEqualVector){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{10, 20, 30};
  Vector v1(inV1), v2(inV2);

  const Vector& sum1 = dynamic_cast<Vector&>(v1 += v2);
  ASSERT_THAT(v1, ElementsAre(11, 22, 33));
  ASSERT_THAT(sum1, ElementsAre(11, 22, 33));
  ASSERT_THAT(v2, ElementsAreArray(inV2));


  v1 += v1;
  ASSERT_THAT(v1, ElementsAre(22, 44, 66));
  ASSERT_THAT(sum1, ElementsAre(22, 44, 66));
  ASSERT_THAT(v2, ElementsAreArray(inV2));

  const Vector& sum2 = dynamic_cast<Vector&>(v2 += v1);
  ASSERT_THAT(v2, ElementsAre(32, 64, 96));
  ASSERT_THAT(sum2, ElementsAre(32, 64, 96));
  ASSERT_THAT(v1, ElementsAre(22, 44, 66));
}

TEST_F(VectorTesting, VectorMinusEqualVector){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{10, 20, 30}, inV3{100, 200, 300};
  Vector v1(inV1), v2(inV2), v3(inV3);

  const Vector& diff1 = dynamic_cast<Vector&>(v1 -= v2);
  ASSERT_THAT(v1, ElementsAre(-9, -18, -27));
  ASSERT_THAT(diff1, ElementsAre(-9, -18, -27));
  ASSERT_THAT(v2, ElementsAreArray(inV2));


  v1.operator-=(v1);
  ASSERT_THAT(v1, ElementsAre(0 ,0 , 0));
  ASSERT_THAT(diff1, ElementsAre(0 ,0 , 0));
  ASSERT_THAT(v2, ElementsAreArray(inV2));

  const Vector& diff2 = dynamic_cast<Vector&>(v3 -= v2);
  ASSERT_THAT(v3, ElementsAre(90, 180, 270));
  ASSERT_THAT(diff2, ElementsAre(90, 180, 270));
  ASSERT_THAT(v1, ElementsAre(0 ,0 , 0));
}

TEST_F(VectorTesting, VectorPlusEqualScalar){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{10, 20, 30, 40};
  Vector v1(inV1), v2(inV2);

  const Vector& sum1 = dynamic_cast<Vector&>(v1 += 10);
  ASSERT_THAT(v1, ElementsAre(11, 12, 13));
  ASSERT_THAT(sum1, ElementsAre(11, 12, 13));
  ASSERT_THAT(v2, ElementsAreArray(inV2));

  const Vector& sum2 = dynamic_cast<Vector&>(v2 += 10);
  ASSERT_THAT(v2, ElementsAre(20, 30, 40, 50));
  ASSERT_THAT(sum2, ElementsAre(20, 30, 40, 50));
  ASSERT_THAT(v1, ElementsAre(11, 12, 13));
}

TEST_F(VectorTesting, VectorMinusEqualScalar){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{10, 20, 30, 40};
  Vector v1(inV1), v2(inV2);

  const Vector& diff1 = dynamic_cast<Vector&>(v1 -= -1);
  std::vector<Vector::value_type> ans1{2, 3, 4};
  ASSERT_THAT(v1, ElementsAreArray(ans1));
  ASSERT_THAT(diff1, ElementsAreArray(ans1));
  ASSERT_THAT(v2, ElementsAreArray(inV2));

  const Vector& sum2 = dynamic_cast<Vector&>(v2 -= 10);
  std::vector<Vector::value_type> ans2{0, 10, 20, 30};
  ASSERT_THAT(v2, ElementsAreArray(ans2));
  ASSERT_THAT(sum2, ElementsAreArray(ans2));
  ASSERT_THAT(v1, ElementsAreArray(ans1));
}

TEST_F(VectorTesting, VectorTimeEqualScalar){
  using namespace Matrix;
  using namespace ::testing;
  std::vector<Vector::value_type> inV1{1,2,3}, inV2{10, 20, 30, 40};
  Vector v1(inV1), v2(inV2);

  const Vector& diff1 = dynamic_cast<Vector&>(v1 *= -2);
  std::vector<Vector::value_type> ans1{-2, -4, -6};
  ASSERT_THAT(v1, ElementsAreArray(ans1));
  ASSERT_THAT(diff1, ElementsAreArray(ans1));
  ASSERT_THAT(v2, ElementsAreArray(inV2));

  const Vector& sum2 = dynamic_cast<Vector&>(v2 *= -10);
  std::vector<Vector::value_type> ans2{-100, -200, -300, -400};
  ASSERT_THAT(v2, ElementsAreArray(ans2));
  ASSERT_THAT(sum2, ElementsAreArray(ans2));
  ASSERT_THAT(v1, ElementsAreArray(ans1));
}

#endif //ECS_36B_HOMEWORK_BASEVECTORTESTS_CPP
