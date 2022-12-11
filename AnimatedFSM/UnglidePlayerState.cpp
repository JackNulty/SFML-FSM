#include <Events.h>

#include <UnglidePlayerState.h>

#include <ClimbUpPlayerState.h>
#include <RunRightPlayerState.h>
#include <DiedPlayerState.h>
#include <IdlePlayerState.h>

PlayerState* UnglidePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_UP_START_EVENT)
	{
		DEBUG_MSG("UnglidePlayerState -> ClimbUpPlayerState");
		return new ClimbUpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		DEBUG_MSG("UnglidePlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("UnglidePlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void UnglidePlayerState::update(Player& player) {
	DEBUG_MSG("UnGlidePlayerState -> IdlePlayerState");
	if (m_clock.getElapsedTime().asSeconds() > 1.2f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void UnglidePlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering UnglidePlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(sf::IntRect(0, 3354, 443, 454));
	player.getAnimatedSprite().addFrame(sf::IntRect(886, 2900, 443, 454));
	player.getAnimatedSprite().addFrame(sf::IntRect(443, 2900, 443, 454));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 2900, 443, 454));
	player.getAnimatedSprite().addFrame(sf::IntRect(886, 2446, 443, 454));
	player.getAnimatedSprite().addFrame(sf::IntRect(443, 2446, 443, 454));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 2446, 443, 454));
	player.getAnimatedSprite().addFrame(sf::IntRect(886, 1992, 443, 454));
	player.getAnimatedSprite().addFrame(sf::IntRect(443, 1992, 443, 454));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 1992, 443, 454));

	player.getAnimatedSprite().setTime(seconds(0.03f));
}
void UnglidePlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting UnglidePlayerState ");
}