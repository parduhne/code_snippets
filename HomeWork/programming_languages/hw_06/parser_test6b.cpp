/*
  Unit tests for HW06 - Part 2
*/

#include "gtest/gtest.h"

#include "Parser.h"
// Changed p.nodeCount() and p.eval() to p.nodeCount() and p.eval() respectively, because the former doesn't work

// Check nodeCount -----------------------------------------------

TEST(nodeCount, 0){
  Parser p;
  EXPECT_EQ(p.parse("5"), true);
  EXPECT_EQ(p.nodeCount(), 1);
}

TEST(nodeCount, 1){
  Parser p;
  EXPECT_EQ(p.parse("0"), true);
  EXPECT_EQ(p.nodeCount(), 1);
}

TEST(nodeCount, 2){
  Parser p;
  EXPECT_EQ(p.parse("53"), true);
  EXPECT_EQ(p.nodeCount(), 1);
}

TEST(nodeCount, 3){
  Parser p;
  EXPECT_EQ(p.parse("5+5"), true);
  EXPECT_EQ(p.nodeCount(), 3);
}

TEST(nodeCount, 4){
  Parser p;
  EXPECT_EQ(p.parse("55 + 3"), true);
  EXPECT_EQ(p.nodeCount(), 3);
}

TEST(nodeCount, 5){
  Parser p;
  EXPECT_EQ(p.parse("(5 )"), true);
  EXPECT_EQ(p.nodeCount(), 1);
}

TEST(nodeCount, 6){
  Parser p;
  EXPECT_EQ(p.parse("( 51)+5 "), true);
  EXPECT_EQ(p.nodeCount(), 3);
}

TEST(nodeCount, 7){
  Parser p;
  EXPECT_EQ(p.parse("(5+( 3 )+53)"), true);
  EXPECT_EQ(p.nodeCount(), 5);
}

TEST(nodeCount, 8){
  Parser p;
  EXPECT_EQ(p.parse("(5 -(3-3)+5)"), true);
  EXPECT_EQ(p.nodeCount(), 7);
}


TEST(nodeCount, 9){
  Parser p;
  EXPECT_EQ(p.parse("((5-(3-3)+5))"), true);
  EXPECT_EQ(p.nodeCount(), 7);
}


// Check eval -----------------------------------------------

TEST(eval, 0){
  Parser p;
  EXPECT_EQ(p.parse("5"), true);
  EXPECT_EQ(p.eval(), 5);
}

TEST(eval, 1){
  Parser p;
  EXPECT_EQ(p.parse("5+6"), true);
  EXPECT_EQ(p.eval(), 11);
}

TEST(eval, 2){
  Parser p;
  EXPECT_EQ(p.parse("5+1-2"), true);
  EXPECT_EQ(p.eval(), 4);
}

TEST(eval, 3){
  Parser p;
  EXPECT_EQ(p.parse("5+2-(5+1)"), true);
  EXPECT_EQ(p.eval(), 1);
}
