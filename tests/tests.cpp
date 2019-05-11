#include <algorithm>
#include <vector>
#include "gtest/gtest.h"
#include "../Factories/AbstractFactory.h"
#include "../Units/Unit.h"
#include "../Builders/BuildAirplane.h"
#include "../Builders/AirplaneFactory.h"


class TestAirplane : public testing::Test {
protected:
    AbstractFactory *factory;
    BuildAirplane *builder;
    Unit *first, *second, *third, *fourth, *fifth;
    void SetUp() {
        factory = new AirplaneFactory();
        first = factory->CreateUnit(1, 1);
        second = factory->CreateUnit(1, 2);
        third = factory->CreateUnit(2, 3);
        fourth = factory->CreateUnit(3, 4);
        fifth = factory->CreateUnit(4, 5);
    }
    void TearDown() { delete factory;
    delete first;
    delete second;
    delete third;
    delete fourth;
    delete fifth;
    }
};

TEST_F(TestAirplane, Test1) {
    std::vector<int> expected = {1, 1, 0, 100, 2, 0, 0, 0, 0, 0, 860, 181120, 0, 10190, 103700};
    std::vector<int> first_plane = first->GetInfo();
    ASSERT_EQ(first_plane, expected);
}

TEST_F(TestAirplane, Test2) {
    std::vector<int> expected = {1, 2, 0, 100, 2, 0, 0, 0, 0, 0, 860, 181120, 0, 10190, 103700};
    std::vector<int> second_plane = second->GetInfo();
    ASSERT_EQ(second_plane, expected);
}

TEST_F(TestAirplane, Test3) {
    std::vector<int> expected = {2, 3, 0, 100, 2, 0, 400, 0, 0, 0, 860, 145810, 0, 10190, 103700};
    std::vector<int> third_plane = third->GetInfo();
    ASSERT_EQ(third_plane, expected);
}

TEST_F(TestAirplane, Test4) {
    std::vector<int> expected = {3, 4, 0, 100, 2, 0, 420, 0, 0, 0, 860, 171160, 0, 10190, 101200};
    std::vector<int> fourth_plane = fourth->GetInfo();
    ASSERT_EQ(fourth_plane, expected);
}

TEST_F(TestAirplane, Test5) {
    std::vector<int> expected = {4, 5, 0, 100, 2, 0, 480, 0, 0, 0, 860, 171160, 0, 10190, 101200};
    std::vector<int> fifth_plane = fifth->GetInfo();
    ASSERT_EQ(fifth_plane, expected);
}

TEST_F(TestAirplane, Test6) {
    std::vector<int> expected = {1, 1, 13, 100, 2, 0, 0, 0, 0, 0, 860, 181120, 0, 10190, 103700};
    first->Move(13);
    std::vector<int> first_plane = first->GetInfo();
    ASSERT_EQ(first_plane, expected);
}

TEST_F(TestAirplane, Test7) {
    std::vector<int> expected = {1, 2, 0, 100, 2, 0, 0, 0, 0, 0, 860, 181120, 999, 10190, 103700};
    second->Refuel(999);
    std::vector<int> second_plane = second->GetInfo();
    ASSERT_EQ(second_plane, expected);
}

TEST_F(TestAirplane, Test8) {
    std::vector<int> expected = {2, 3, 0, 80, 2, 0, 400, 0, 0, 0, 860, 145810, 0, 10190, 103700};
    third->Repair(80);
    std::vector<int> third_plane = third->GetInfo();
    ASSERT_EQ(third_plane, expected);
}

TEST_F(TestAirplane, Test9) {
    std::vector<int> expected = {3, 4, 0, 100, 2, 0, 420, 56, 57, 58, 860, 171160, 0, 10190, 101200};
    fourth->Load(56, 57, 58);
    std::vector<int> fourth_plane = fourth->GetInfo();
    ASSERT_EQ(fourth_plane, expected);
}

TEST_F(TestAirplane, Test10) {
    std::vector<int> expected = {4, 5, 0, 100, 2, 0, 480, 0, 0, 0, 860, 171160, 0, 10190, 101200};
    std::vector<int> fifth_plane = fifth->GetInfo();
    ASSERT_EQ(fifth_plane, expected);
}

TEST_F(TestAirplane, Test11) {
    std::vector<int> expected = {1, 1, 0, 100, 0, 11111, 0, 0, 0, 0, 860, 181120, 6666, 10190, 103700};
    builder->SetCrew(first, 4);
    builder->SetFuel(first, 6666);
    builder->SetLoad(first, 99, 100, 101);
    builder->SetPayload(first, 11111);
    std::vector<int> first_plane = first->GetInfo();
    ASSERT_EQ(first_plane, expected);
}

TEST_F(TestAirplane, Test12) {
    std::vector<int> expected = {2, 3, 0, 100, 5, 211, 400, 99, 100, 101, 860, 181120, 6776, 10190, 103700};
    builder->SetCrew(third, 5);
    builder->SetFuel(third, 6776);
    builder->SetLoad(third, 99, 100, 101);
    builder->SetPayload(third, 211);
    std::vector<int> third_plane = third->GetInfo();
    ASSERT_EQ(third_plane, expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
