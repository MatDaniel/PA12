#ifndef TST_SETANZAHLBEFEHL_H
#define TST_SETANZAHLBEFEHL_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include <string>
#include <vector>
#include "regalcontroller.h"
#include "befehle/setanzahlbefehl.h"

TEST(SetAnzahlBefehlSuite, SetTest)
{

    RegalController controller(1, 2, 3);
    auto palette = controller[5];

    SetAnzahlBefehl befehl(controller);
    std::vector<std::string> testing_args { "5", "42" };
    befehl.exec(testing_args);
    EXPECT_EQ(palette->anzahl(), 0);

    palette->setWare("Test");
    befehl.exec(testing_args);
    EXPECT_EQ(palette->anzahl(), 42);

}

#endif // TST_SETANZAHLBEFEHL_H
