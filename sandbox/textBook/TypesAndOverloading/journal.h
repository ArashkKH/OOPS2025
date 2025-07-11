#ifndef SENECA_JOURNAL_H
#define SENECA_JOURNAL_H

struct Journal {
    char description[51];
    double amount;
};

void readJournal(Journal& j);
void displayJournal(const Journal& j);
void displayJournal(const Journal& j , bool withCurrencySymbol);

void increaseAmountByValue(Journal j);
void increaseAmountByReference(Journal& j);

#endif