#ifndef BACKWARDS_THROW_ATTACK_PLAYER_STATE_H
#define BACKWARDS_THROW_ATTACK_PLAYER_STATE_H

#include <Player.h>
#include <PlayerState.h>

class BackwardsThrowAttackPlayerState : public PlayerState {
public:
	virtual PlayerState* handleInput(gpp::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
private:
	sf::Clock m_clock;
};

#endif
