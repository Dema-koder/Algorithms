#include <string>
#include <vector>

using std::string;

class MyQueue {
   private:
    std::vector<string> values;
    size_t front_idx = 0;

   public:
    MyQueue() {}

    size_t size() { return values.size(); }

    void push(string value) { values.push_back(value); }

    void pop() { values.erase(values.begin()); }

    string front() { return values[front_idx]; }

    void clear() { values.clear(); }
};

#include <iostream>

int main() {
    size_t n;
    std::cin >> n;

    int grade;
    string name;
    MyQueue g9, g10, g11;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> grade >> name;
        switch (grade) {
            case 9:
                g9.push(name);
                break;
            case 10:
                g10.push(name);
                break;
            case 11:
                g11.push(name);
                break;

            default:
                break;
        }
    }

    size_t sg9 = g9.size(), sg10 = g10.size(), sg11 = g11.size();
    for (size_t i = 0; i < sg9; ++i) {
        std::cout << "9 " << g9.front() << std::endl;
        g9.pop();
    }
    for (size_t i = 0; i < sg10; ++i) {
        std::cout << "10 " << g10.front() << std::endl;
        g10.pop();
    }
    for (size_t i = 0; i < sg11; ++i) {
        std::cout << "11 " << g11.front() << std::endl;
        g11.pop();
    }

    return 0;
}
