#pragma once
class Item
{

	int coin=0;

public:
	Item();
	void SetCoin(int _in);
	void GetCoin(int* _in);
	void GetItem();
	~Item();
};

