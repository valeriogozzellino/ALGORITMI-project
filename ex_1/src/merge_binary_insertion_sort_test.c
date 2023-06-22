#include "unity.h"
#include "merge_binary_insertion_sort.h"
#include "compare.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//static void test_array_empty(); 
static void test_one_array();
static void test_two_array(); 
static void test_sort_array();
static void test_unsort_array(); 

int main(void)
{
  UNITY_BEGIN();
  /* RUN_TEST(test_array_empty); */
  RUN_TEST(test_one_array);
  RUN_TEST(test_two_array);
  RUN_TEST(test_sort_array);
  RUN_TEST(test_unsort_array);
  return UNITY_END();  
}

static void test_one_array() {
  size_t nitems = 1;
  size_t k = 5;
  int array_int[] = {2};
  int expected_int []= {2};
  int *ptr_int = array_int;
  merge_binary_insertion_sort(ptr_int, nitems, sizeof(int), k, compare_integer1);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected_int, ptr_int, nitems);
}

static void test_sort_array() {
  size_t nitems = 5;
  size_t k = 8;
  int array_int[] = {2,8,9,5,4};
  int expected_int []= {2,4,5,8,9};
  int *ptr_int = array_int;
  merge_binary_insertion_sort(ptr_int, nitems, sizeof(int), k, compare_integer1);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected_int, ptr_int, nitems);
}

static void test_two_array(){
  int i_array[] = {2, 3}; /* Actual Array */
  int i_exp_array[] = {2, 3}; /* Expected result */
  void* i_array_ptr = i_array; /* ptr to the actual array */
  void* i_exp_array_ptr = i_exp_array; /* ptr to the exp array */
  size_t i_nitems = sizeof(i_array)/sizeof(int);
  size_t i_size = sizeof(int);
  size_t k = 10;
  merge_binary_insertion_sort(i_array_ptr, i_nitems, i_size, k, compare_integer1);
  TEST_ASSERT_EQUAL_INT_ARRAY(i_exp_array_ptr, i_array_ptr, i_nitems);
}


static void test_unsort_array()
{
  size_t k = 2;
  int array_int[] = {3, 2, 1};
  int array_exp_int[] = {1, 2, 3};
  size_t size = sizeof(array_int[0]);
  size_t nitems = 3;
  merge_binary_insertion_sort(array_int, nitems, size, k, compare_integer1);
  //----------test--------------
  TEST_ASSERT_EQUAL_INT_ARRAY(array_exp_int, array_int, nitems);
}

/*
static void test_array_empty(){
  size_t k = 2;
  int array_int[] = {};
  int array_exp_int[] = {};
  size_t size_int = sizeof(array_int) / sizeof(array_int[0]);
  size_t nitems = 0;
  merge_binary_insertion_sort(array_int, nitems, size_int, k, compare_integer1);
  TEST_ASSERT_EQUAL_INT_ARRAY(array_exp_int, array_int, nitems);
}
*/
