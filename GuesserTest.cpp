/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, match_first)
{
  Guesser object("Secret");
  ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, fail_off_end)
{
  Guesser object("Secret");
  ASSERT_FALSE(object.match("Secre"));
}

TEST(GuesserTest, fail_off_start)
{
  Guesser object("Secret");
  ASSERT_FALSE(object.match("ecret"));
}

TEST(GuesserTest, match_second_close)
{
  Guesser object("Secret");
  object.match("secret");
  ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, match_third_close)
{
  Guesser object("Secret");
object.match("secret");
object.match("secret");
ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, fail_fourth_close)
{
  Guesser object("Secret");
	object.match("secret");
	object.match("secret");
	object.match("secret");
  ASSERT_FALSE(object.match("Secret"));
}

TEST(GuesserTest, fail_second_far)
{
  Guesser object("Secret");
  object.match("Secretsarenotverycooltohaveunlesstheyarewithmanypeoplethenitiskindacool");
  ASSERT_FALSE(object.match("Secret"));
}

TEST(GuesserTest, match_second_edgecase)
{
  Guesser object("Secret");
  object.match("Secret12");
  ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, fail_third_edgecase)
{
  Guesser object("Secret");
  object.match("Secret123");
  ASSERT_FALSE(object.match("Secret"));
}

TEST(GuesserTest, match_empty)
{
  Guesser object("");
  ASSERT_TRUE(object.match(""));
}

TEST(GuesserTest, match_third_and_sixth_close)
{
  Guesser object("Secret");
	object.match("secret");
	object.match("secret");
	object.match("Secret");
	object.match("secret");
	object.match("secret");
  ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, test_remaining_after_one)
{
  Guesser object("Secret");
	object.match("secret");
  ASSERT_EQ(2,object.remaining());
}

TEST(GuesserTest, test_remaining_after_two)
{
  Guesser object("Secret");
	object.match("secret");
  object.match("secret");
  ASSERT_EQ(1,object.remaining());
}

TEST(GuesserTest, test_remaining_after_three)
{
  Guesser object("Secret");
	object.match("secret");
  object.match("secret");
    object.match("secret");
  ASSERT_EQ(0,object.remaining());
}

TEST(GuesserTest, remaining_reset_first)
{
  Guesser object("Secret");
	object.match("Secret");
  ASSERT_EQ(3,object.remaining());
}

TEST(GuesserTest, remaining_reset_second)
{
  Guesser object("Secret");
	object.match("secret");
	object.match("Secret");
  ASSERT_EQ(3,object.remaining());
}

TEST(GuesserTest, remaining_reset_third)
{
  Guesser object("Secret");
	object.match("secret");
	object.match("secret");
	object.match("Secret");
  ASSERT_EQ(3,object.remaining());
}




