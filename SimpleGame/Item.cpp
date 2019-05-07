#include "stdafx.h"
#include "Item.h"


Item::Item()
{
	coin = 10;
}

void Item::SetCoin(int _in) {
	if (coin < 99 && coin > 0) {
		coin = _in;
	}
}
void Item::GetCoin(int* _in) {
	if (coin < 99 && coin > 0) {
		*_in = coin;
	}
}

void Item::GetItem() {
	if (coin < 99 && coin > 0) {
		coin += 3;
	}
}

Item::~Item()
{
}
