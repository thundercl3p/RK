#include "DocumentVisitor.h"
#include "Document.h"
#include <iostream>

void DocumentPrinter::visit(Markdown* doc) {
    std::cout << "Printing Markdown document:" << std::endl;
    for (const auto& line : doc->getContent()) {
        std::cout << doc->getStart() << line << std::endl;
    }
}

void DocumentPrinter::visit(HTML* doc) {
    std::cout << "Printing HTML document:" << std::endl;
    for (const auto& line : doc->getContent()) {
        std::cout << doc->getStart() << line << doc->getEnd() << std::endl;
    }
}
