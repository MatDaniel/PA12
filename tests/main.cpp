#include "tst_regalcontroller.h"
#include "tst_removewarebefehl.h"
#include "tst_setanzahlbefehl.h"
#include "tst_setwarebefehl.h"
#include "tst_exitbefehl.h"
#include "tst_setdefektbefehl.h"
#include "tst_setlagerbedingungenbefehl.h"
#include "tst_removelagerbedingungenbefehl.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
