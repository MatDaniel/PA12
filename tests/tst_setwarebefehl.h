#ifndef TST_SETWAREBEFEHL_H
#define TST_SETWAREBEFEHL_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include <string>
#include <vector>
#include "regalcontroller.h"
#include "befehle/setwarebefehl.h"

TEST(SetWareBefehlSuite, SetTest)
{

    RegalController controller(1, 2, 3);
    SetWareBefehl befehl(controller);
    auto palette = controller[5];

    palette->setLagerbedingungen("Keine Bedingungen!");
    std::vector<std::string> testing_args0 { "5", "Produkt" };
    befehl.exec(testing_args0);
    EXPECT_EQ(palette->ware(), "Produkt");
    EXPECT_EQ(palette->anzahl(), 1);
    EXPECT_FALSE(palette->hasLagerbedingungen());

    palette->setLagerbedingungen("Aber...");
    std::vector<std::string> testing_args1 { "5", "Produkt", "3" };
    befehl.exec(testing_args1);
    EXPECT_EQ(palette->ware(), "Produkt");
    EXPECT_EQ(palette->anzahl(), 3);
    EXPECT_FALSE(palette->hasLagerbedingungen());

    std::vector<std::string> testing_args2 { "5", "Affe" };
    befehl.exec(testing_args2);
    EXPECT_EQ(palette->ware(), "Affe");
    EXPECT_EQ(palette->anzahl(), 1);

    std::vector<std::string> testing_args3 { "5", "Produkt", "42" };
    befehl.exec(testing_args3);
    EXPECT_EQ(palette->ware(), "Produkt");
    EXPECT_EQ(palette->anzahl(), 42);

    std::vector<std::string> testing_args4 { "5", "Tiger", "lol" };
    befehl.exec(testing_args4);
    EXPECT_EQ(palette->ware(), "Produkt");
    EXPECT_EQ(palette->anzahl(), 42);

}

#endif // TST_SETWAREBEFEHL_H
