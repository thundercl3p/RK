#include "Document.h"
#include <iostream>

Markdown::Markdown() : m_start("* ") {}

void Markdown::addToList(const std::string& line) {
    m_content.push_back(line);
}

void Markdown::accept(DocumentVisitor* visitor) {
    visitor->visit(this);
}

std::string Markdown::getStart() const {
    return m_start;
}

std::list<std::string> Markdown::getContent() const {
    return m_content;
}

HTML::HTML() : m_start("<li>"), m_end("</li>") {}

void HTML::addToList(const std::string& line) {
    m_content.push_back(line);
}

void HTML::accept(DocumentVisitor* visitor) {
    visitor->visit(this);
}

std::string HTML::getStart() const {
    return m_start;
}

std::string HTML::getEnd() const {
    return m_end;
}

std::list<std::string> HTML::getContent() const {
    return m_content;
}
