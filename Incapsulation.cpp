#include <iostream>

class Player
{
protected:
	int damage = 1;

public:
	//Задание 1
	bool isGrounded = true;  // Отсутствие инкапсуляции
	
	// get, set
	void setDamage(int _damage)
	{
		this->damage = _damage;
		return;
	}
	
	unsigned int getDamage() const
	{
		return damage;
	}
	// Спец методы
	void increaseDamage(int _damage)
	{
		this->damage += _damage;
		return;
	}

	int decreaseDamage(int _damage)
	{
		if ((damage - _damage) > 0)
		{
			this->damage -= _damage;
			return 0;
		}
		else
		{
			this->damage = 1;
			std::cout << "damage couldn't be less than one" << '\n';
			return 1;
		}
	}
	virtual void hit() const
	{
		std::cout << damage << '\n';
		return;
	}

	virtual void killEnemy() const
	{
		std::cout << "I kill enemy" << '\n';
	}
};

class Enemy : public Player
{
	void hit() const
	{
		Player::hit();
		std::cout << 5 << '\n';
	}

	void killEnemy() const
	{
		std::cout << "I can't kill my friend" << '\n';
	}
};

//Задание 2
void attack(const Player *attacker)
{
	attacker->hit();
}

void killAlien(const Player* attacker)
{
	attacker->killEnemy();
}

int main()
{
	Player Man;
	Enemy Alien;
	Man.isGrounded = false;
	Man.setDamage(15);
	std::cout << Man.getDamage() << '\n';
	std::cout << '\n';
	Man.increaseDamage(500);
	std::cout << Man.getDamage() << '\n';
	Man.decreaseDamage(520);
	std::cout << Man.getDamage() << '\n';
	std::cout << '\n';
	attack(&Man);
	attack(&Alien);
	std::cout << '\n';
	killAlien(&Man);
	killAlien(&Alien);
}
//100 строчка :З
