#include "Document.h"
#include "DocumentVisitor.h"
#include <gtest/gtest.h>

TEST(DocumentTest, MarkdownAcceptVisitor) {
    Markdown doc;
    doc.addToList("Test markdown content");
    
    DocumentPrinter visitor;
    doc.accept(&visitor);
}

TEST(DocumentTest, HtmlAcceptVisitor) {
    HTML doc;
    doc.addToList("Test HTML content");
    
    DocumentPrinter visitor;
    doc.accept(&visitor);
}
