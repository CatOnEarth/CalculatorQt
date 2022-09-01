#ifndef CHECKINPUTCORRECTION_H
#define CHECKINPUTCORRECTION_H

#include <QString>
#include <set>
#include <map>
#include "stack_qstring.h"

class CheckInputCorrection
{
public:
    CheckInputCorrection();

    bool check_correct_expression(QString);
};

#endif // CHECKINPUTCORRECTION_H
