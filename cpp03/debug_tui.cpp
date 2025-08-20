#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include <cstdlib>

struct attr_type
{
    std::string name;
    size_t      offset;
    std::string type;
};

class Test
{
private:
    std::string     name;
    int             y;
    int             x;

public:
    static struct attr_type attrs[];
    static const size_t attrs_count;
    Test(int x, int y);
    ~Test();
    void move(int new_x, int new_y);
};

struct attr_type Test::attrs[] = {
    {"name", offsetof(Test, name), "string"},
    {"x", offsetof(Test, x), "int"},
    {"y", offsetof(Test, y), "int"},
};

const size_t Test::attrs_count = sizeof(Test::attrs) / sizeof(Test::attrs[0]);

Test::Test(int x, int y) :
    name("Test"), y(y), x(x) 
{
}

Test::~Test()
{
}

void Test::move(int new_x, int new_y)
{
    x = new_x;
    y = new_y;
    std::cout << "move to {" << x << ", " << y << "}" << std::endl;
}

// Simple functions to get/set integer values using offsets
int getValue(Test* obj, size_t offset)
{
    char* base = (char*)obj;
    return *(int*)(base + offset);
}

void setValue(Test* obj, size_t offset, int value)
{
    char* base = (char*)obj;
    *(int*)(base + offset) = value;
}

// Debug state storage (simplified for integers only)
struct DebugState
{
    int x_val;
    int y_val;
    std::string operation;
};

class MovementDebugger
{
private:
    std::vector<DebugState> states;
    size_t current_state;
    
public:
    MovementDebugger() : current_state(0) {}
    
    void captureState(Test* obj, const std::string& operation)
    {
        DebugState state;
        state.operation = operation;
        state.x_val = getValue(obj, Test::attrs[1].offset); // x
        state.y_val = getValue(obj, Test::attrs[2].offset); // y
        
        // Remove states after current position when adding new state
        if (current_state < states.size() - 1)
        {
            states.erase(states.begin() + current_state + 1, states.end());
        }
        
        states.push_back(state);
        current_state = states.size() - 1;
    }
    
    void restoreState(Test* obj, size_t index)
    {
        if (index >= states.size()) return;
        
        const DebugState& state = states[index];
        setValue(obj, Test::attrs[1].offset, state.x_val); // x
        setValue(obj, Test::attrs[2].offset, state.y_val); // y
    }
    
    void displayCurrentState(Test* obj)
    {
        std::cout << "\033[2J\033[H"; // Clear screen and move cursor to top
        std::cout << "=== Movement Debugger ===" << std::endl;
        std::cout << "State: " << (current_state + 1) << "/" << states.size() << std::endl;
        
        if (current_state < states.size())
        {
            std::cout << "Operation: " << states[current_state].operation << std::endl;
        }
        
        std::cout << "\nCurrent Values (via offsets):" << std::endl;
        std::cout << "  x: " << getValue(obj, Test::attrs[1].offset) << std::endl;
        std::cout << "  y: " << getValue(obj, Test::attrs[2].offset) << std::endl;
        
        std::cout << "\nControls:" << std::endl;
        std::cout << "  [n] Next state" << std::endl;
        std::cout << "  [p] Previous state" << std::endl;
        std::cout << "  [q] Quit" << std::endl;
        std::cout << "\nEnter command: ";
    }
    
    bool nextState(Test* obj)
    {
        if (current_state < states.size() - 1)
        {
            current_state++;
            restoreState(obj, current_state);
            return true;
        }
        return false;
    }
    
    bool prevState(Test* obj)
    {
        if (current_state > 0)
        {
            current_state--;
            restoreState(obj, current_state);
            return true;
        }
        return false;
    }
    
    void runTUI(Test* obj)
    {
        char command;
        while (true)
        {
            displayCurrentState(obj);
            std::cin >> command;
            
            switch (command)
            {
                case 'n':
                case 'N':
                    if (!nextState(obj))
                    {
                        std::cout << "Already at last state! Press Enter...";
                        std::cin.ignore();
                        std::cin.get();
                    }
                    break;
                case 'p':
                case 'P':
                    if (!prevState(obj))
                    {
                        std::cout << "Already at first state! Press Enter...";
                        std::cin.ignore();
                        std::cin.get();
                    }
                    break;
                case 'q':
                case 'Q':
                    return;
                default:
                    std::cout << "Invalid command! Press Enter...";
                    std::cin.ignore();
                    std::cin.get();
                    break;
            }
        }
    }
};

int main() {
    Test test(10, 20);
    MovementDebugger debugger;
    
    // Capture initial state
    debugger.captureState(&test, "Initial state");
    
    // Simulate movements and capture states
    test.move(10, 21);
    debugger.captureState(&test, "move(10, 21)");
    
    test.move(11, 20);
    debugger.captureState(&test, "move(11, 20)");
    
    test.move(12, 20);
    debugger.captureState(&test, "move(12, 20)");
    
    test.move(12, 21);
    debugger.captureState(&test, "move(12, 21)");
    
    test.move(12, 22);
    debugger.captureState(&test, "move(12, 22)");
    
    test.move(12, 23);
    debugger.captureState(&test, "move(12, 23)");
    
    // Start TUI debugger
    std::cout << "\nStarting Movement Debugger TUI..." << std::endl;
    std::cout << "Captured " << 7 << " states for debugging." << std::endl;
    std::cout << "Press Enter to start...";
    std::cin.get();
    
    debugger.runTUI(&test);
    
    std::cout << "Debugger exited." << std::endl;
    return 0;
}
