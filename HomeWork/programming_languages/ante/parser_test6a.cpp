/*
*/

#include "gtest/gtest.h"

#include "Parser.h"

// Tests Parser's parse function if valid or not.
TEST(singles, 0){
  Parser p;
  EXPECT_EQ(p.parse("486"), true);
}

TEST(singles, 1){
  Parser p;
  EXPECT_EQ(p.parse("0"), true);
}

TEST(singles, 2){
  Parser p;
  EXPECT_EQ(p.parse("53"), true);
}

TEST(singles, 3){
  Parser p;
  EXPECT_EQ(p.parse("+"), false);
}

TEST(singles, 4){
  Parser p;
  EXPECT_EQ(p.parse("5+"), false);
}

TEST(dual, 0){
  Parser p;
  EXPECT_EQ(p.parse("5+5"), true);
}

TEST(dual, 1){
  Parser p;
  EXPECT_EQ(p.parse("55+3"), true);
}

TEST(dual, 2){
  Parser p;
  EXPECT_EQ(p.parse("5+"), false);
}

TEST(dual, 3){
  Parser p;
  EXPECT_EQ(p.parse("5+5+"), false);
}

TEST(dual, 4){
  Parser p;
  EXPECT_EQ(p.parse("5+5a"), false);
}

TEST(paren, 0){
  Parser p;
  EXPECT_EQ(p.parse("(5)"), true);
}

TEST(paren, 1){
  Parser p;
  EXPECT_EQ(p.parse("(5)+5"), true);
}

TEST(paren, 2){
  Parser p;
  EXPECT_EQ(p.parse("(5+5"), false);
}

TEST(paren, 3){
  Parser p;
  EXPECT_EQ(p.parse("5+5)"), false);
}
