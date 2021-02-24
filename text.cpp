#include "text.h"

Ethons Display(TEXTS textid) {
	return _texts[static_cast<unsigned short int>(textid)];
}
