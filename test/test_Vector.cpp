#include "Vector.h"
#include "Stack.h"

#include <gtest.h>

TVector<int> NextGreaterElement(TVector<int>& nums)
{
  TVector<int> result(nums.size(), -1);
  TStack<int> stack;

  for (int i = nums.size() - 1; i >= 0; i--)
  {
    while (!stack.IsEmpty() && stack.top() <= nums[i])
      stack.Pop();

    if (!stack.empty())
      result[i] = stack.top();

    stack.Push(nums[i]);
  }
  return result;
}

TEST(TVector, can_create_birch_with_positive_height)
{
  TVector<int> arr;
  arr.push_back(10);
  arr.push_back(-15);
  arr.push_back(20);
  arr.push_back(-25);
  arr.push_back(30);


  TVector<int> a = NextGreaterElement(arr);
}

