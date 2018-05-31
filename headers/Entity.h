#ifndef ENTITY_H
#define ENTITY_H


class Entity {
private:
	char* name;
	double hp;
	double strength;
	double intelligence;

	double attackDmg;

	void copy(const Entity& other);
	void del();

protected:
	const double BASE_STRENGTH;
	const double BASE_INTELLIGENCE;
public:
	Entity();
	Entity(const char * name, double hp, double strength, double intelligence);
	Entity(const Entity& other);
	Entity& operator=(const Entity& other);

	virtual ~Entity() {};

	void setName(const char* name);
	const char* getName() const;

	void setHp(double hp);
	double getHp() const;

	void setStrength(double strength);
	double getStrength() const;

	void setIntelligence(double intelligence);
	double getIntelligence() const;

	double getAgility() const;

	virtual void setAttackDmg(double dmg = 0);
	double getAttackDmg();

	void printAttack(const char* name, double dmg) const;

	virtual const char* getClassName() { return "Entity";  };
	virtual void attack(Entity* entity) = 0;
	virtual void defend(double dmg);
	virtual bool isAlive() const;
};

#endif