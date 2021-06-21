#ifndef TST_REGALCONTROLLER_H
#define TST_REGALCONTROLLER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include "regalcontroller.h"

TEST(RegalControllerSuite, InitTest)
{

    RegalController controller(5, 2, 3);
    EXPECT_EQ(controller.size(), 30);
    EXPECT_EQ(controller[30], nullptr);

    for (size_t i = 0; i < 30; i++)
    {
        EXPECT_NE(controller[i], nullptr);
    }

}

TEST(RegalControllerSuite, IndexOfTest)
{

    RegalController controller3_3_4(3, 3, 4);
    EXPECT_EQ(controller3_3_4.index_of(0, 0, 0),  0);
    EXPECT_EQ(controller3_3_4.index_of(0, 0, 1),  1);
    EXPECT_EQ(controller3_3_4.index_of(0, 0, 2),  2);
    EXPECT_EQ(controller3_3_4.index_of(0, 1, 0),  4);
    EXPECT_EQ(controller3_3_4.index_of(0, 2, 0),  8);
    EXPECT_EQ(controller3_3_4.index_of(1, 0, 0), 12);
    EXPECT_EQ(controller3_3_4.index_of(2, 0, 0), 24);
    EXPECT_EQ(controller3_3_4.index_of(1, 1, 1), 17);
    EXPECT_EQ(controller3_3_4.index_of(0, 0, 4), -1);
    EXPECT_EQ(controller3_3_4.index_of(0, 3, 0), -1);
    EXPECT_EQ(controller3_3_4.index_of(3, 0, 0), -1);

    RegalController controller5_2_3(5, 2, 3);
    EXPECT_EQ(controller5_2_3.index_of(0, 0, 0),  0);
    EXPECT_EQ(controller5_2_3.index_of(0, 0, 1),  1);
    EXPECT_EQ(controller5_2_3.index_of(0, 0, 2),  2);
    EXPECT_EQ(controller5_2_3.index_of(0, 1, 0),  3);
    EXPECT_EQ(controller5_2_3.index_of(0, 1, 1),  4);
    EXPECT_EQ(controller5_2_3.index_of(1, 0, 0),  6);
    EXPECT_EQ(controller5_2_3.index_of(2, 0, 0), 12);
    EXPECT_EQ(controller5_2_3.index_of(1, 1, 1), 10);
    EXPECT_EQ(controller5_2_3.index_of(0, 0, 3), -1);
    EXPECT_EQ(controller5_2_3.index_of(0, 2, 0), -1);
    EXPECT_EQ(controller5_2_3.index_of(5, 0, 0), -1);

}

TEST(RegalControllerSuite, UniqueValueTest)
{

    RegalController controller(3, 3, 3);
    const auto init_ware = "INITIALIZED";

    for (size_t i = 0; i < controller.size(); i++)
    {
        Palette *palette = controller[i];
        EXPECT_TRUE(palette->empty());
        palette->setAnzahl(i);
        palette->setWare(init_ware);
    }

    for (size_t i = 0; i < controller.size(); i++)
    {
        Palette *palette = controller[i];
        EXPECT_EQ(palette->anzahl(), i);
        EXPECT_EQ(palette->ware(), init_ware);
    }

}

#endif // TST_REGALCONTROLLER_H
