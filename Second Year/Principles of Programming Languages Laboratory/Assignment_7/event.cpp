#include <iostream>
#include <vector>
#include <functional>

// Event class
class Event {
public:
    void RegisterHandler(const std::function<void()>& handler) {
        handlers_.push_back(handler);
    }

    void Trigger() {
        std::cout << "Event Triggered!" << std::endl;
        for (const auto& handler : handlers_) {
            handler(); // Call registered event handlers
        }
    }

private:
    std::vector<std::function<void()>> handlers_;
};

// Event handler classes
class EventHandler1 {
public:
    void HandleEvent() {
        std::cout << "EventHandler1: Event handled!" << std::endl;
    }
};

class EventHandler2 {
public:
    void HandleEvent() {
        std::cout << "EventHandler2: Event handled!" << std::endl;
    }
};

int main() {
    // Create event and event handlers
    Event event;
    EventHandler1 handler1;
    EventHandler2 handler2;

    // Register event handlers
    event.RegisterHandler(std::bind(&EventHandler1::HandleEvent, &handler1));
    event.RegisterHandler(std::bind(&EventHandler2::HandleEvent, &handler2));

    // Trigger the event
    event.Trigger();

    return 0;
}
