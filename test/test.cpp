// Testing suite for sailbot control system

#include "gtest/gtest.h"

int main(int argc, char **argv)
{
    TEST(datapointTest, simpleMath)
    {
	EXPECT(0, 1-1);
    }
}
