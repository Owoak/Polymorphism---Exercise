#pragma once
#include <sstream>
#include <vector>

template <typename T>
class TypedStream {
private:
	std::string input;
protected:
	std::istringstream stream;
	TypedStream(const std::string& input) : input(input), stream(input) {}

public:
	std::vector<T> readToEnd() {
		std::vector <T>elements;
		T element;
		while (true) {
			*this >> element;
			if ((bool)stream == false) {
				break;
			}
			elements.push_back(element);
		}
		return elements;
	}
	virtual TypedStream<T>& operator>>(T& v) {
		return *this;
	}
};