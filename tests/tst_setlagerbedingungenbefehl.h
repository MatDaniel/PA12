#ifndef TST_SETLAGERBEDINGUNGENBEFEHL_H
#define TST_SETLAGERBEDINGUNGENBEFEHL_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include <string>
#include <vector>
#include "regalcontroller.h"
#include "befehle/setlagerbedingungenbefehl.h"

TEST(SetLagerbedingungenBefehlSuite, SetTest)
{

    RegalController controller(1, 2, 3);
    SetLagerbedingungenBefehl befehl(controller);
    auto palette = controller[5];

    std::vector<std::string> testing_args0 { "5", "Meine", "tolle", "Bedingung!" };
    befehl.exec(testing_args0);
    EXPECT_FALSE(palette->hasLagerbedingungen());
    EXPECT_EQ(palette->lagerbedingungen(), "");
    palette->setWare("Test");

    befehl.exec(testing_args0);
    EXPECT_TRUE(palette->hasLagerbedingungen());
    EXPECT_EQ(palette->lagerbedingungen(), "Meine tolle Bedingung!");

    std::vector<std::string> testing_args1 { "5", "EinArgument" };
    befehl.exec(testing_args1);
    EXPECT_TRUE(palette->hasLagerbedingungen());
    EXPECT_EQ(palette->lagerbedingungen(), "EinArgument");

    std::vector<std::string> testing_args2 { "5", "", "Leer" };
    befehl.exec(testing_args2);
    EXPECT_TRUE(palette->hasLagerbedingungen());
    EXPECT_EQ(palette->lagerbedingungen(), " Leer");

    std::vector<std::string> testing_args3 { "5", "", "Leer2", "" };
    befehl.exec(testing_args3);
    EXPECT_TRUE(palette->hasLagerbedingungen());
    EXPECT_EQ(palette->lagerbedingungen(), " Leer2 ");
}


#endif // TST_SETLAGERBEDINGUNGENBEFEHL_H
