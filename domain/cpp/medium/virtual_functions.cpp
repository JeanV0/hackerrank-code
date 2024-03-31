#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
    static int id_global;
    int id_message;
    string text_message;
public: 
    Message(const string& text): text_message(text) {
        this->id_message = id_global;
        id_global++;
    }
    
    bool operator<(const Message& other) const {
        return this->id_message < other.id_message;
    }
    
    Message& operator=(const Message& other) {
        this->text_message = other.text_message;
        this->id_message = other.id_message;

        return *this;
    }
    
    const string& get_text() {
        return this->text_message;
    }
};

int Message::id_global = 0;

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        return Message{text};
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
