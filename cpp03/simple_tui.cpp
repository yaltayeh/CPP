#include <iostream>
#include <string>
#include <cstddef>
#include <cstdlib>
#include <ncurses.h>

struct attr_type
{
    const char* name;
    size_t      offset;
    const char* type;
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

const size_t Test::attrs_count = 3;

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

// Debug state storage (fixed size array)
struct DebugState
{
    int x_val;
    int y_val;
    const char* operation;
};

class MovementDebugger
{
private:
    static const size_t MAX_STATES = 20;
    DebugState states[MAX_STATES];
    size_t num_states;
    size_t current_state;
    
public:
    MovementDebugger() : num_states(0), current_state(0) {}
    
    void captureState(Test* obj, const char* operation)
    {
        if (num_states >= MAX_STATES) return; // Prevent overflow
        
        DebugState& state = states[num_states];
        state.operation = operation;
        state.x_val = getValue(obj, Test::attrs[1].offset); // x
        state.y_val = getValue(obj, Test::attrs[2].offset); // y
        
        num_states++;
        current_state = num_states - 1;
    }
    
    void restoreState(Test* obj, size_t index)
    {
        if (index >= num_states) return;
        
        const DebugState& state = states[index];
        setValue(obj, Test::attrs[1].offset, state.x_val); // x
        setValue(obj, Test::attrs[2].offset, state.y_val); // y
    }
    
    void displayCurrentState(Test* obj)
    {
        clear(); // Clear screen
        
        // Title with colors and arrows (ASCII-safe)
        attron(COLOR_PAIR(1) | A_BOLD);
        mvprintw(0, 0, "<== Movement Debugger ==>");
        attroff(COLOR_PAIR(1) | A_BOLD);
        
        // State info with navigation arrows
        mvprintw(2, 0, "State: %lu/%lu", (unsigned long)(current_state + 1), (unsigned long)num_states);
        
        // Navigation indicators
        if (current_state > 0) {
            attron(COLOR_PAIR(3) | A_BOLD);
            mvprintw(2, 20, "< PREV");
            attroff(COLOR_PAIR(3) | A_BOLD);
        }
        if (current_state < num_states - 1) {
            attron(COLOR_PAIR(3) | A_BOLD);
            mvprintw(2, 30, "NEXT >");
            attroff(COLOR_PAIR(3) | A_BOLD);
        }
        
        if (current_state < num_states)
        {
            attron(COLOR_PAIR(2));
            mvprintw(3, 0, "Operation: %s", states[current_state].operation);
            attroff(COLOR_PAIR(2));
        }
        
        // Current values box with arrow pointer
        attron(COLOR_PAIR(3) | A_BOLD);
        mvprintw(5, 0, "> Current Values (via offsets):");
        attroff(COLOR_PAIR(3) | A_BOLD);
        
        // Draw a box with corners (ASCII-safe)
        mvprintw(6, 2, "+==================+");
        mvprintw(7, 2, "|");
        mvprintw(7, 21, "|");
        mvprintw(8, 2, "|");
        mvprintw(8, 21, "|");
        mvprintw(9, 2, "+==================+");
        
        // Values inside the box with arrows
        attron(COLOR_PAIR(4));
        mvprintw(7, 4, "> x: %d", getValue(obj, Test::attrs[1].offset));
        mvprintw(8, 4, "> y: %d", getValue(obj, Test::attrs[2].offset));
        attroff(COLOR_PAIR(4));
        
        // Controls section with arrows
        attron(COLOR_PAIR(5) | A_BOLD);
        mvprintw(11, 0, "> Navigation Controls:");
        attroff(COLOR_PAIR(5) | A_BOLD);
        
        mvprintw(12, 2, "^ UP [p/P] Previous state");
        mvprintw(13, 2, "v DOWN [n/N] Next state");
        mvprintw(14, 2, "< > Arrow keys also work");
        mvprintw(15, 2, "X [q/Q/ESC] Quit");
        
        // Progress bar
        mvprintw(17, 0, "Progress: ");
        int bar_width = 20;
        int filled = (current_state * bar_width) / (num_states > 1 ? num_states - 1 : 1);
        
        attron(COLOR_PAIR(6));
        mvaddch(17, 10, '[');
        for (int i = 0; i < bar_width; i++) {
            if (i < filled) {
                mvaddch(17, 11 + i, '#');  // Use # for filled
            } else {
                mvaddch(17, 11 + i, '-');  // Use - for empty
            }
        }
        mvaddch(17, 11 + bar_width, ']');
        attroff(COLOR_PAIR(6));
        
        // Status bar at bottom with arrows
        int max_y, max_x;
        getmaxyx(stdscr, max_y, max_x);
        
        attron(COLOR_PAIR(7) | A_REVERSE);
        mvprintw(max_y - 2, 0, "<< Use arrows or keys to navigate >>");
        for (int i = 37; i < max_x; i++) {
            mvaddch(max_y - 2, i, ' ');
        }
        attroff(COLOR_PAIR(7) | A_REVERSE);
        
        refresh();
    }
    
    bool nextState(Test* obj)
    {
        if (current_state < num_states - 1)
        {
            current_state++;
            restoreState(obj, current_state);
            return true;
        }
        else
        {
            // Show message at bottom of screen with arrows
            int max_y, max_x;
            getmaxyx(stdscr, max_y, max_x);
            attron(COLOR_PAIR(8) | A_BLINK);
            mvprintw(max_y - 1, 0, ">> Already at last state! <<");
            attroff(COLOR_PAIR(8) | A_BLINK);
            refresh();
            napms(1500); // Wait 1.5 seconds
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
        else
        {
            // Show message at bottom of screen with arrows
            int max_y, max_x;
            getmaxyx(stdscr, max_y, max_x);
            attron(COLOR_PAIR(8) | A_BLINK);
            mvprintw(max_y - 1, 0, "<< Already at first state! >>");
            attroff(COLOR_PAIR(8) | A_BLINK);
            refresh();
            napms(1500); // Wait 1.5 seconds
        }
        return false;
    }
    
    void runTUI(Test* obj)
    {
        // Initialize ncurses
        initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        
        // Initialize colors if supported
        if (has_colors()) {
            start_color();
            init_pair(1, COLOR_CYAN, COLOR_BLACK);    // Title
            init_pair(2, COLOR_YELLOW, COLOR_BLACK);  // Operation
            init_pair(3, COLOR_GREEN, COLOR_BLACK);   // Section headers/arrows
            init_pair(4, COLOR_WHITE, COLOR_BLACK);   // Values
            init_pair(5, COLOR_MAGENTA, COLOR_BLACK); // Controls
            init_pair(6, COLOR_BLUE, COLOR_BLACK);    // Progress bar
            init_pair(7, COLOR_BLACK, COLOR_WHITE);   // Status bar
            init_pair(8, COLOR_RED, COLOR_BLACK);     // Error messages
        }
        
        int ch;
        while (true)
        {
            displayCurrentState(obj);
            ch = getch();
            
            switch (ch)
            {
                case 'n':
                case 'N':
                case KEY_RIGHT:
                case KEY_DOWN:
                    nextState(obj);
                    break;
                case 'p':
                case 'P':
                case KEY_LEFT:
                case KEY_UP:
                    prevState(obj);
                    break;
                case 'q':
                case 'Q':
                case 27: // ESC key
                    endwin();
                    return;
                default:
                    // Show invalid key message with arrows
                    int max_y, max_x;
                    getmaxyx(stdscr, max_y, max_x);
                    attron(COLOR_PAIR(8));
                    mvprintw(max_y - 1, 0, "^v Invalid key! Use arrows or n/p/q <>");
                    attroff(COLOR_PAIR(8));
                    refresh();
                    napms(1500);
                    break;
            }
        }
    }
};

int main() {
    Test test(10, 20);
    MovementDebugger debugger;
    
    // Show initial setup in regular terminal
    std::cout << "\n=== Movement Debugger with ncurses ===" << std::endl;
    std::cout << "Capturing movement states..." << std::endl;
    
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
    
    std::cout << "Captured 7 movement states." << std::endl;
    std::cout << "Starting ncurses TUI..." << std::endl;
    std::cout << "Controls: n/p (or arrow keys) to navigate, q/ESC to quit" << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    
    // Start ncurses TUI debugger
    debugger.runTUI(&test);
    
    std::cout << "Debugger exited. Goodbye!" << std::endl;
    return 0;
}
