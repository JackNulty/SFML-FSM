#include <Events.h>

#include <BackwardsThrowAttackPlayerState.h>

#include <RunRightPlayerState.h>
#include <IdlePlayerState.h>
#include <DiedPlayerState.h>

PlayerState* BackwardsThrowAttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		DEBUG_MSG("BackwardsThrowAttackPlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::BACKWARDS_THROW_STOP_EVENT)
	{
		DEBUG_MSG("BackwardsThrowAttackPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("BackwardsThrowAttackPlayerStatee -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void BackwardsThrowAttackPlayerState::update(Player& player) {
	DEBUG_MSG("BackwardsThrowAttackPlayerState -> IdlePlayerState");
	if (m_clock.getElapsedTime().asSeconds() > 1.2f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void BackwardsThrowAttackPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering BackwardsThrowAttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(sf::IntRect(6075, 1353, 377, 451));
	player.getAnimatedSprite().addFrame(sf::IntRect(6829, 902, 377, 451));
	player.getAnimatedSprite().addFrame(sf::IntRect(6452, 902, 377, 451));
	player.getAnimatedSprite().addFrame(sf::IntRect(6075, 902, 377, 451));
	player.getAnimatedSprite().addFrame(sf::IntRect(6829, 451, 377, 451));
	player.getAnimatedSprite().addFrame(sf::IntRect(6452, 451, 377, 451));
	player.getAnimatedSprite().addFrame(sf::IntRect(6075, 451, 377, 451));
	player.getAnimatedSprite().addFrame(sf::IntRect(6829, 0, 377, 451));
	player.getAnimatedSprite().addFrame(sf::IntRect(6452, 0, 377, 451));
	player.getAnimatedSprite().addFrame(sf::IntRect(6075, 0, 377, 451));

	player.getAnimatedSprite().setTime(seconds(0.03f));
}
void BackwardsThrowAttackPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting BackwardsThrowAttackPlayerState");
}