#ifndef ENTITY_H
#define ENTITY_H


class Entity {
private:
public:
	virtual ~Entity() {};

	virtual const char* getClassName() { return "Entity";  };
	virtual void attack(Entity* entity) = 0;
	virtual void defend(double dmg) = 0;
	virtual bool isAlive() const = 0;
	virtual const char* getName() const = 0;
	virtual double getIntelligence() const = 0;
	virtual double getStrength() const = 0;
	virtual double getAgility() const = 0;
};

#endif