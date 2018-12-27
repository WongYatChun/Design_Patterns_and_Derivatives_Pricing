#include "PayOffConstructible.h"

namespace{ // unnamed namespace and as such are invisible to the rest of the program
    PayOffHelper<PayOffCall> RegisterCall("call");
    PayOffHelper<PayOffPut> registerPut("put");
}