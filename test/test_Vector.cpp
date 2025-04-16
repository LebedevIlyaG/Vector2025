#include "Vector.h"

#include <gtest.h>

TEST(TVector, can_create_birch_with_positive_height)
{
  ASSERT_NO_THROW(TVector<int> bf(3));
}

TEST(TVector, can_get_height)
{
  TVector<int> bf(3);

  EXPECT_NEAR(3, bf.GetLen(), 0.000001);
}

TEST(TVector, new_vector_is_set_to_zero)
{
  TVector<int> bf(10);

  int sum = 0;
  for (int i = 0; i < bf.GetLen(); i++)
  {
    sum += bf[i];
  }

  EXPECT_EQ(0, sum);
}

TEST(TVector, can_set_number_of_vector)
{
  TVector<int> bf(10);

  bf.SetLen(3);
  EXPECT_EQ(0, bf[0]);
}


TEST(TVector, throws_when_create_vector_with_negative_height)
{
  ASSERT_ANY_THROW(TVector<int> bf(-3));
}
