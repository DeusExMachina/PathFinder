//
// Created by zairai on 03/04/17.
//

#include "gtest/gtest.h"
#include "../../Map.h"

TEST(Map, TestPathFinding){
    Map::get_instance().loadFromTxt();
    int test;
    test = Map::get_instance().startPF(2,4,8,8);
    ASSERT_EQ(0,test);
}