#include "Document.h"
#include "DocumentVisitor.h"
#include <memory>

void clientCode() {
    DocumentVisitor* dp = new DocumentPrinter();

    Document* d1 = new HTML();
    d1->addToList("This is line");
    d1->accept(dp);

    Document* d2 = new Markdown();
    d2->addToList("This is another line");
    d2->accept(dp);

    delete d1;
    delete d2;
    delete dp;
}

int main() {
    clientCode();
    return 0;
}
