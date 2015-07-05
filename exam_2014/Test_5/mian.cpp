/* 2015-01-08 */
/* �������еĽ������˵��������Ʒ����ĺô������ó��� */
#include<iostream>
#include<string>
using namespace std;

class Beverage{
public:
	virtual string GetDescription() = 0;
	virtual double Cost() = 0;
};

class HouseBlend :public Beverage{
public:
	double Cost(){
		return 0.89;
	}

	string GetDescription(){
		return "House Blend Coffee"; 
	}
};

class DarkRoast :public Beverage{
public:
	double Cost(){ 
		return 0.99; 
	}

	string GetDescription(){ 
		return "Dark Roast Coffee"; 
	}
};

class CondimentDecorator :public Beverage{
public:
	CondimentDecorator(Beverage* bev){ 
		beverage = bev; 
	}

protected:
	Beverage *beverage;
};

class Soy :public CondimentDecorator{
public:
	Soy(Beverage *bev) :CondimentDecorator(bev){}

	string GetDescription(){ 
		return beverage->GetDescription() + ",Soy"; 
	}

	double Cost(){ 
		return 0.15 + beverage->Cost(); 
	}
};

class SteamedMilk :public CondimentDecorator{
public:
	SteamedMilk(Beverage *bev) :CondimentDecorator(bev){}
	string GetDescription(){
		return beverage->GetDescription() + ",Steamed Milk";
	}

	double Cost(){ 
		return 0.10 + beverage->Cost();
	}
};

class Whip :public CondimentDecorator{
public:
	Whip(Beverage* bev) :CondimentDecorator(bev){}
	string GetDescription(){ 
		return beverage->GetDescription() + ",Whip";
	}

	double Cost(){ 
		return 0.10 + beverage->Cost(); 
	}
};

void main(){
	Beverage *beverage = new HouseBlend;
	beverage = new SteamedMilk(beverage);
	beverage = new Whip(beverage);
	cout << beverage->GetDescription() << "$" << beverage->Cost() << endl;
}

/* ����� House Blend Coffee, SteamedMilk, Whip$1.09 */