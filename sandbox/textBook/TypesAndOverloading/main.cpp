#include "journal.h"

int main(){
    Journal entry;
    readJournal(entry);
    displayJournal(entry);
    displayJournal(entry , true);

    increaseAmountByValue(entry);
    displayJournal(entry);
    increaseAmountByReference(entry);
    displayJournal(entry);
    return 0;
}

