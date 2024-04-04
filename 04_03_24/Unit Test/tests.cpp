#include <gtest/gtest.h>
#include <cmath>
#include "drink.h"
using namespace std;
// extern "C" int __wrap_main();

// int startTest() __attribute__ ((constructor));
TEST(drinkTest, constructorAndGetterTest)
{
	drink cube(TEA, BLEND, LARGE, "None", "Sugar");
	EXPECT_STRCASEEQ(cube.getBaseStr().c_str(), "Tea");
	EXPECT_STRCASEEQ(cube.getTemperature().c_str(), "Blended");
	EXPECT_STRCASEEQ(cube.getSize().c_str(), "Large");
	EXPECT_STRCASEEQ(cube.getDairy().c_str(), "None");
	EXPECT_STRCASEEQ(cube.getFlavor().c_str(), "Sugar");
}
TEST(drinkTest, baseSetterTest)
{
	drink cube(TEA, BLEND, LARGE, "None", "Sugar");
	cube.setBase(COFFEE);
	ASSERT_STRCASEEQ(cube.getBaseStr().c_str(), "Coffee");
	cube.setBase(CREAM);
	ASSERT_STRCASEEQ(cube.getBaseStr().c_str(), "Cream");
}
TEST(drinkTest, tempSetterTest)
{
	drink cube(TEA, BLEND, LARGE, "None", "Sugar");
	cube.setTemperature(HOT);
	ASSERT_STRCASEEQ(cube.getTemperature().c_str(), "Hot");
	cube.setTemperature(ICE);
	ASSERT_STRCASEEQ(cube.getTemperature().c_str(), "Iced");
}
TEST(drinkTest, sizeSetterTest)
{
	drink cube(TEA, BLEND, LARGE, "None", "Sugar");
	cube.setSize(SMALL);
	ASSERT_STRCASEEQ(cube.getSize().c_str(), "Small");
	cube.setSize(MED);
	ASSERT_STRCASEEQ(cube.getSize().c_str(), "Medium");
}
TEST(drinkTest, dairySetterTest)
{
	drink cube(TEA, BLEND, LARGE, "None", "Sugar");
	cube.setDairy("Skim Milk");
	ASSERT_STRCASEEQ(cube.getDairy().c_str(), "Skim Milk");
}
TEST(drinkTest, flavorSetterTest)
{
	drink cube(TEA, BLEND, LARGE, "None", "Sugar");
	cube.setFlavor("Peach");
	ASSERT_STRCASEEQ(cube.getFlavor().c_str(), "Peach");
}
TEST(drinkTest, priceTest)
{
	drink cube(TEA, BLEND, LARGE, "None", "Sugar");
	ASSERT_DOUBLE_EQ(cube.getPrice(), 7.5);
	cube.setBase(COFFEE);
	ASSERT_DOUBLE_EQ(cube.getPrice(), 8.5);
	cube.setBase(CREAM);
	std::cout << "Set Cream" << std::endl;
	ASSERT_DOUBLE_EQ(cube.getPrice(), 5.75);

	cube.setTemperature(HOT);
	ASSERT_DOUBLE_EQ(cube.getPrice(), 5);
	cube.setTemperature(ICE);
	ASSERT_DOUBLE_EQ(cube.getPrice(), 5.5);
	cube.setDairy("whole milk");
	std::cout << "Set whole milk" << std::endl;
	ASSERT_DOUBLE_EQ(cube.getPrice(), 5.75);
	cube.setDairy("skim milk");
	std::cout << "Set skim milk" << std::endl;
	ASSERT_DOUBLE_EQ(cube.getPrice(), 5.75);
	cube.setDairy("cream");
	ASSERT_DOUBLE_EQ(cube.getPrice(), 6.5);
	cube.setDairy("oat milk");
	ASSERT_DOUBLE_EQ(cube.getPrice(), 7);
	cube.setDairy("almond milk");
	ASSERT_DOUBLE_EQ(cube.getPrice(), 7);
}

extern "C" int startTest(int x, char **y)
{
	// cout << "begin" << endl;
	// int x = 0;
	// char ** y = NULL;
	testing::InitGoogleTest(&x, y);
	// cout << "Init Complete"<< endl;
	int code = RUN_ALL_TESTS();
	// exit(code);
	return code;
}
// int i = startTest();
extern "C" int __wrap_main(int x, char **y)
{
	return startTest(x, y);
}