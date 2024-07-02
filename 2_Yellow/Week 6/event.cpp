#include "event.h"

#include <iostream>
#include <string>

using namespace std;

Event ParseEvent(istream& stream) {
    Event event;
    stream >> event;
    return event;
}

bool operator <(const Event& value_1, const Event& value_2) {
    return value_1.value < value_2.value;
}

ostream& operator <<(ostream& stream, const Event& value) {
    stream << value.value;
    return stream;
}

istream& operator >>(istream& stream, Event& value) {
    string event_value;
    getline(stream, event_value);
    auto x = event_value.find_first_not_of(' ');
    value.value = x != string::npos ? event_value.substr(x, event_value.size() - x) : "";
    return stream;
}

bool operator ==(const Event& e1, const Event& e2) {
    return e1.value == e2.value;
}

bool operator !=(const Event& e1, const Event& e2) {
    return e1.value != e2.value;
}