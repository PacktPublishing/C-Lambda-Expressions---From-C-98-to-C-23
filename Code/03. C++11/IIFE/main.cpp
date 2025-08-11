#include <iostream>
#include <random>
#include <vector>
#include <fstream>
void BasicUsage() {
	//[](std::string msg) {
	//	std::cout << "Hello world\n" ;
	//	std::cout << "Message:" << msg << '\n' ;
	//}("Hello world") ;

	std::vector<int> data(10);
	generate(data.begin(), data.end(), []() {
		return std::random_device{}() % 10;
	});
	for (int i = 0; i < data.size(); ++i) {
		//Print(data[i]) ;
		[](int value) {
			std::cout << value << ' ';
		}(data[i]);
	}
}

enum class SupportType {
	WHATSAPP,
	EMAIL
};

namespace FirstImplementation{
	SupportType GetSupportType() { 
		return SupportType::EMAIL ;
	}
	void ShowSupportLinks() {
		std::string HTML{} ;
		std::string message = "Contact Us" ;
		switch (GetSupportType()) {
		case SupportType::WHATSAPP: {
			std::string data = "1234567890";//WhatsApp support number
			HTML = "<a href=\"https://wa.me/" + data + "\">" + message + "</a>" ;
		}
			break ;
		case SupportType::EMAIL: {
			std::string data = "support@poash.com" ;//Support email
			HTML = "<a href=\"mailto:" + data + "\">" + message + "</a>" ;
		}
			break ;
		}
		std::cout << HTML << '\n' ;
		std::ofstream file{"support.html"} ;
		file << "<html><body>" << HTML << "</body></html>\n" ;
	}
}


SupportType GetSupportType() { 
	return SupportType::EMAIL ;
}
void ShowSupportLinks() {
	std::string message = "Contact Us";
	const std::string HTML = [](std::string message, SupportType type) {
		std::string HTML{};
		switch (type) {
		case SupportType::WHATSAPP: {
			std::string data = "1234567890";//WhatsApp support number
			HTML = "<a href=\"https://wa.me/" + data + "\">" + message + "</a>";
		}
								  break;
		case SupportType::EMAIL: {
			std::string data = "support@poash.com";//Support email
			HTML = "<a href=\"mailto:" + data + "\">" + message + "</a>";
		}
							   break;
		}
		return HTML;
	}(message, GetSupportType());
	
	std::cout << HTML << '\n' ;
	std::ofstream file{"support.html"} ;
	file << "<html><body>" << HTML << "</body></html>\n" ;
}
int main() {
	ShowSupportLinks() ;
}
