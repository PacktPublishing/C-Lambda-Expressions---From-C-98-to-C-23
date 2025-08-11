#include <iostream>
#include <string>
class Text {
    std::string m_Text ;
public:
    Text(const std::string& text)
        : m_Text{text} {
    }
 
    auto GetPrintOperation(const std::string &title)const {
        return [=]() {
            std::cout << title <<": " << m_Text << '\n' ;
        } ;
    }
};
auto TextPrinter(const std::string &text) {
	Text p{text} ;
    return p.GetPrintOperation("Information") ;
}

int main() {
  /* Text text{"Using [=] will implicitly capture this"} ;
    auto printer = text.GetPrintOperation("Information") ;
    printer() ;*/
    auto printer = TextPrinter("Using [=] will implicitly capture this") ;
    printer() ;
}