#include "game.cpp"
#include <algorithm>

#include <gtest/gtest.h>

class TestAirplane : public testing::Test {
protected:
    AbstractFactory* factory;
    Unit *first, *second, *third, *fourth, *fifth;
    void SetUp() {
        factory = new AirplaneFactory();
        first = factory->CreateUnit(1, 1);
        second = factory->CreateUnit(1, 2);
        third = factory->CreateUnit(2, 3);
        fourth = factory->CreateUnit(3, 4);
        fifth = factory->CreateUnit(4, 5);
    }
    void TearDown() { delete factory; }
};

TEST_F(TestAirplane, Test1) {
vector<int> expected = {1, 1, 0, 100, 2, 0, 0, 0, 0, 0, 860, 181120, 0, 10190, 103700};
vector<int> first_plane = first->GetInfo();
ASSERT_NE(first_plane, expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
