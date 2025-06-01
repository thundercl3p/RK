#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <list>
#include "DocumentVisitor.h"

class Document {
public:
    virtual ~Document() = default;
    virtual void addToList(const std::string& line) = 0;
    virtual void accept(DocumentVisitor* visitor) = 0;
};

class Markdown : public Document {
public:
    Markdown();
    void addToList(const std::string& line) override;
    void accept(DocumentVisitor* visitor) override;
    
    std::string getStart() const;
    std::list<std::string> getContent() const;

private:
    std::string m_start;
    std::list<std::string> m_content;
};

class HTML : public Document {
public:
    HTML();
    void addToList(const std::string& line) override;
    void accept(DocumentVisitor* visitor) override;
    
    std::string getStart() const;
    std::string getEnd() const;
    std::list<std::string> getContent() const;

private:
    std::string m_start;
    std::string m_end;
    std::list<std::string> m_content;
};

#endif // DOCUMENT_H
