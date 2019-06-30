#include <sol/sol.hpp>
#include <cassert>

int main() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    int x = 0;
    lua.set_function("beep", [&x]{ ++x; });
    lua.script("beep()");
    assert(x == 1);

    lua.script("print(\"456\")");
}