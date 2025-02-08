//
// Created by DarsenOP on 2/8/25.
//

#include <iostream>
#include <memory>

enum Priority { LOW, MEDIUM, HIGH };

class Request
{
    Priority _priority;
public:
    explicit Request(const Priority priority) : _priority(priority) {}

    [[nodiscard]] Priority GetPriority() const { return _priority; }
};

class Handler
{
protected:
    std::unique_ptr<Handler> _nextHandler;
public:
    explicit Handler(std::unique_ptr<Handler> n = nullptr) : _nextHandler(std::move(n)) {}
    virtual ~Handler() = default;

    virtual void handleRequest(Request& request) = 0;
};

class LowLevelHandler final : public Handler
{
public:
    explicit LowLevelHandler(std::unique_ptr<Handler> n = nullptr) : Handler(std::move(n)) {}

    void handleRequest(Request& request) override
    {
        if (request.GetPriority() == Priority::LOW) {
            std::cout << "Handled request in LVL1" << std::endl;
        } else if (_nextHandler != nullptr) {
            _nextHandler->handleRequest(request);
        }
    }
};

class MediumLevelHandler final : public Handler
{
public:
    explicit MediumLevelHandler(std::unique_ptr<Handler> n = nullptr) : Handler(std::move(n)) {}

    void handleRequest(Request& request) override
    {
        if (request.GetPriority() == Priority::MEDIUM) {
            std::cout << "Handled request in LVL2" << std::endl;
        } else if (_nextHandler != nullptr) {
            _nextHandler->handleRequest(request);
        }
    }
};

class HighLevelHandler final : public Handler
{
public:
    explicit HighLevelHandler(std::unique_ptr<Handler> n = nullptr) : Handler(std::move(n)) {}

    void handleRequest(Request& request) override
    {
        if (request.GetPriority() == Priority::HIGH) {
            std::cout << "Handled request in LVL3" << std::endl;
        } else {
            std::cout << "The task cannot be handled!" << std::endl;
        }
    }
};

int main() {
    auto level3Handler = std::make_unique<HighLevelHandler>();
    auto level2Handler = std::make_unique<MediumLevelHandler>(std::move(level3Handler));
    auto level1Handler = std::make_unique<LowLevelHandler>(std::move(level2Handler));

    Request request1(Priority::LOW);
    Request request2(Priority::MEDIUM);
    Request request3(Priority::HIGH);


    level1Handler->handleRequest(request1);
    level1Handler->handleRequest(request2);
    level1Handler->handleRequest(request3);
}