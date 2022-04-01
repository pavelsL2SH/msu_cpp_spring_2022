#include <iostream>

#include <gtest/gtest.h>

#include "allocator.hpp"

class TestFoo : public ::testing::Test
{
protected:
	void SetUp()
	{
        std::cout << "SetUp" << std::endl;
	}
	void TearDown()
	{
        std::cout << "TearDown" << std::endl;
	}
};

TEST_F(TestFoo, test_const_method)
{
		Allocator test_alloc = Allocator();
		test_alloc.makeAllocator(10);
		ASSERT_NE(test_alloc.alloc(2), nullptr);
		ASSERT_NE(test_alloc.alloc(2), nullptr);
		ASSERT_NE(test_alloc.alloc(2), nullptr);
		ASSERT_NE(test_alloc.alloc(2), nullptr);
		ASSERT_NE(test_alloc.alloc(2), nullptr);
		test_alloc.reset();
		ASSERT_EQ(test_alloc.alloc(2), nullptr);
		test_alloc.makeAllocator(5);
		ASSERT_EQ(test_alloc.alloc(10), nullptr);
		//ASSERT_NE(test_alloc.alloc(1), nullptr);
}

TEST_F(TestFoo, test_string_method)
{
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
