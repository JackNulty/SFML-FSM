#include <Events.h>

#include <BackwardsAttackPlayerState.h>

#include <RunRightPlayerState.h>
#include <IdlePlayerState.h>
#include <DiedPlayerState.h>

PlayerState* BackwardsAttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		DEBUG_MSG("BackwardsAttackPlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::BACKWARDS_ATTACK_STOP_EVENT)
	{
		DEBUG_MSG("BackwardsAttackPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("BackwardsAttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void BackwardsAttackPlayerState::update(Player& player) {
	DEBUG_MSG("BackwardAttackState -> IdlePlayerState");
	if (m_clock.getElapsedTime().asSeconds() > 1.2f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void BackwardsAttackPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering BackwardsAttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(sf::IntRect(0, 1485, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(1072, 990, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(536, 990, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 990, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(1072, 495, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(536, 495, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 495, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(1072, 0, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(536, 0, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 0, 536, 495));

	player.getAnimatedSprite().setTime(seconds(0.03f));
}
void BackwardsAttackPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting BackwardsAttackPlayerState");
}