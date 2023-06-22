#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compare.h"
#include "SkipList.h"
#include "unity.h"

static void test_list_empty(); 
static void test_one_list();
static void test_two_list(); 
static void test_sort_list();

#define MAX_HEIGHT 15

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_empty);
    RUN_TEST(test_one_list);
    RUN_TEST(test_two_list);
    RUN_TEST(test_sort_list);
    return UNITY_END();  
}

static void test_list_empty() {
    struct SkipList * list = NULL;
    new_skiplist(&list, MAX_HEIGHT);
    TEST_ASSERT_NULL(list -> head -> item);
}

static void test_one_list() {
    int (*generic_compare[])(const void *, const void *) = {compare_integer, compare_float, compare_string};
    struct SkipList * list = NULL;
    struct SkipList * exp_list = NULL;
    new_skiplist(&list, MAX_HEIGHT);
    new_skiplist(&exp_list, MAX_HEIGHT);
    list -> compare = generic_compare[0];
    exp_list -> compare = generic_compare[0];
    char item1[] = "ccccc";
    
    insert_skiplist(&list, &item1, list -> compare, MAX_HEIGHT);
    insert_skiplist(&exp_list, &item1, exp_list -> compare, MAX_HEIGHT);
    
    TEST_ASSERT_EQUAL_STRING(exp_list -> head -> next[0] -> item, list -> head -> next[0] -> item);
    struct Node * next_node = *list -> head -> next[0] -> next;
    struct Node * next_exp_node = *exp_list -> head -> next[0] -> next;
    TEST_ASSERT_NULL(next_node);
    TEST_ASSERT_NULL(next_exp_node);
}

static void test_two_list() {
    int (*generic_compare[])(const void *, const void *) = {compare_integer, compare_float, compare_string};
    struct SkipList * list = NULL;
    struct SkipList * exp_list = NULL;
    new_skiplist(&list, MAX_HEIGHT);
    new_skiplist(&exp_list, MAX_HEIGHT);
    list -> compare = generic_compare[0];
    exp_list -> compare = generic_compare[0];
    char item1[] = "ccccc";
    char item2[] = "aaaaa";
    insert_skiplist(&list, &item1, list -> compare, MAX_HEIGHT);
    insert_skiplist(&list, &item2, list -> compare, MAX_HEIGHT);
    insert_skiplist(&exp_list, &item1, exp_list -> compare, MAX_HEIGHT);
    insert_skiplist(&exp_list, &item2, exp_list -> compare, MAX_HEIGHT);
    struct Node * ptr_node = list -> head -> next[0];
    struct Node * exp_ptr_node = exp_list -> head -> next[0];
    for(int i = 0; i < 2; i++) {
        TEST_ASSERT_EQUAL_STRING(exp_ptr_node -> item, ptr_node -> item);
        ptr_node = ptr_node -> next[0];
        exp_ptr_node = exp_ptr_node -> next[0];
    }
    TEST_ASSERT_NULL(ptr_node);
    TEST_ASSERT_NULL(exp_ptr_node);
}

static void test_sort_list() {
    int (*generic_compare[])(const void *, const void *) = {compare_integer, compare_float, compare_string};
    struct SkipList * list = NULL;
    struct SkipList * exp_list = NULL;
    new_skiplist(&list, MAX_HEIGHT);
    new_skiplist(&exp_list, MAX_HEIGHT);
    list -> compare = generic_compare[0];
    exp_list -> compare = generic_compare[0];
    char item1[] = "ccccc";
    char item2[] = "aaaaa";
    char item3[] = "zzzzz";
    char item4[] = "bbbbb";
    insert_skiplist(&list, &item1, list -> compare, MAX_HEIGHT);
    insert_skiplist(&list, &item2, list -> compare, MAX_HEIGHT);
    insert_skiplist(&list, &item3, list -> compare, MAX_HEIGHT);
    insert_skiplist(&list, &item4, list -> compare, MAX_HEIGHT);
    insert_skiplist(&exp_list, &item2, exp_list -> compare, MAX_HEIGHT);
    insert_skiplist(&exp_list, &item4, exp_list -> compare, MAX_HEIGHT);
    insert_skiplist(&exp_list, &item1, exp_list -> compare, MAX_HEIGHT);
    insert_skiplist(&exp_list, &item3, exp_list -> compare, MAX_HEIGHT);
    struct Node * ptr_node = list -> head -> next[0];
    struct Node * exp_ptr_node = exp_list -> head -> next[0];
    for(int i = 0; i < 4; i++) {
        TEST_ASSERT_EQUAL_STRING(exp_ptr_node -> item, ptr_node -> item);
        ptr_node = ptr_node -> next[0];
        exp_ptr_node = exp_ptr_node -> next[0];
    }
    TEST_ASSERT_NULL(ptr_node);
    TEST_ASSERT_NULL(exp_ptr_node);


}





