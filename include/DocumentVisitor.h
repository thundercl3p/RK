#ifndef DOCUMENT_VISITOR_H
#define DOCUMENT_VISITOR_H

class Markdown;
class HTML;

class DocumentVisitor {
public:
    virtual ~DocumentVisitor() = default;
    virtual void visit(Markdown* md) = 0;
    virtual void visit(HTML* hd) = 0;
};

class DocumentPrinter : public DocumentVisitor {
public:
    void visit(Markdown* md) override;
    void visit(HTML* hd) override;
};

#endif // DOCUMENT_VISITOR_H
